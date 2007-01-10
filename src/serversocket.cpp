/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <log4cxx/logstring.h>
#include <log4cxx/helpers/serversocket.h>
#include <log4cxx/helpers/socket.h>

#include <assert.h>

using namespace log4cxx::helpers;

/**  Creates a server socket on a specified port.
*/
ServerSocket::ServerSocket(int port)
{
   InetAddressPtr bindAddr = InetAddress::anyAddress();

   socketImpl = new SocketImpl();
   socketImpl->create(true);
   socketImpl->bind(bindAddr, port);
   socketImpl->listen(50);
}

/** Creates a server socket and binds it to the specified local
port number, with the specified backlog.
*/
ServerSocket::ServerSocket(int port, int backlog)
{
   InetAddressPtr bindAddr = InetAddress::anyAddress();

   socketImpl = new SocketImpl();
   socketImpl->create(true);
   socketImpl->bind(bindAddr, port);
   socketImpl->listen(backlog);
}

/** Create a server with the specified port, listen backlog,
and local IP address to bind to.
*/
ServerSocket::ServerSocket(int port, int backlog, InetAddressPtr bindAddr)
{
   socketImpl = new SocketImpl();
   socketImpl->create(true);
   socketImpl->bind(bindAddr, port);
   socketImpl->listen(backlog);
}

ServerSocket::~ServerSocket()
{
}

/** Listens for a connection to be made to this socket and
accepts it
*/
SocketPtr ServerSocket::accept()
{
   SocketImplPtr accepted = new SocketImpl;
   socketImpl->accept(accepted);
   return new Socket(accepted);
}

/** Retrive setting for SO_TIMEOUT.
*/
int ServerSocket::getSoTimeout() const
{
   return socketImpl->getSoTimeout();
}

/** Enable/disable SO_TIMEOUT with the specified timeout, in milliseconds.
*/
void ServerSocket::setSoTimeout(int timeout)
{
   socketImpl->setSoTimeout(timeout);
}

