// Class for handling external clock synchronization from companion computer

#pragma once

#include "AP_DDS_config.h"
#if AP_DDS_CLOCK_SUB_ENABLED

#include "rosgraph_msgs/msg/Clock.h"

class AP_DDS_Clock
{
public:

    // Handler for external clock synchronization
    static void handle_clock_update(const rosgraph_msgs_msg_Clock& msg);

};

#endif // AP_DDS_CLOCK_SUB_ENABLED
