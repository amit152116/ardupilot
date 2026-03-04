// Class for handling external obstacle avoidance data from DDS.

#pragma once

#include "AP_DDS_config.h"

#if AP_DDS_OBSTACLE_DISTANCE_SUB_ENABLED

#include "ardupilot_msgs/msg/ObstacleDistance3D.h"

class AP_DDS_ObstacleAvoidance
{
public:

    // Handler for external obstacle distance data from DDS
    static void handle_obstacle_distance(const ardupilot_msgs_msg_ObstacleDistance3D& msg);

};

#endif // AP_DDS_OBSTACLE_DISTANCE_SUB_ENABLED
