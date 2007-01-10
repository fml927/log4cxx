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

#include <log4cxx/rolling/triggeringpolicy.h>

using namespace log4cxx;
using namespace log4cxx::rolling;

IMPLEMENT_LOG4CXX_OBJECT(TriggeringPolicy)


 #if 0
package org.apache.log4j.rolling;

import org.apache.log4j.Appender;
import org.apache.log4j.spi.LoggingEvent;
import org.apache.log4j.spi.OptionHandler;

import java.io.File;


/**
 * A <code>TriggeringPolicy</code> controls the conditions under which rollover
 * occurs. Such conditions include time of day, file size, an
 * external event, the log request or a combination thereof.
 *
 * @author Ceki G&uuml;lc&uuml;
 * @since 1.3
 * */
public interface TriggeringPolicy {
    /**
     * Should rolllover be triggered at this time?
     *
     * @param appender A reference to the appender.
     * @param event A reference to the currently event.
     * @param file A reference to the currently active log file.
     * @param fileLength Length of the file in bytes.
     * @return true if a rollover should occur.
     */
    public boolean isTriggeringEvent(final Appender appender,
        final LoggingEvent event, final File file, final long fileLength);
}

#endif
