// Class for handling external rangefinder data from DDS.

#pragma once

#include "AP_DDS_config.h"

#if AP_DDS_RANGEFINDER_SUB_ENABLED

#include "sensor_msgs/msg/Range.h"

class AP_DDS_Rangefinder
{
public:

    // Handler for external rangefinder data from DDS
    static void handle_external_rangefinder(const sensor_msgs_msg_Range& msg);

};

#endif // AP_DDS_RANGEFINDER_SUB_ENABLED
