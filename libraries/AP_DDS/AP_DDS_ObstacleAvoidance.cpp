#include "AP_DDS_ObstacleAvoidance.h"

#if AP_DDS_OBSTACLE_DISTANCE_SUB_ENABLED

#include <AC_Avoidance/AP_OADatabase.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_Proximity/AP_Proximity.h>
#include <GCS_MAVLink/GCS.h>

void AP_DDS_ObstacleAvoidance::handle_obstacle_distance(
    const ardupilot_msgs_msg_ObstacleDistance3D &msg) {
  // Pass through to AP_Proximity for pre-arm checks, GCS Radar, and Simple
  // Avoidance. NOTE: AP_Proximity will automatically push this data into the
  // AP_OADatabase for BendyRuler path planning. Do not manually push to
  // OADatabase here!

  auto *proximity = AP_Proximity::get_singleton();
  mavlink_obstacle_distance_3d_t mav_obs = {};
  mav_obs.time_boot_ms = AP_HAL::millis();
  mav_obs.sensor_type = msg.sensor_type;
  mav_obs.frame = msg.frame;
  mav_obs.obstacle_id = msg.obstacle_id;
  mav_obs.x = msg.position.x;
  mav_obs.y = msg.position.y;
  mav_obs.z = msg.position.z;
  mav_obs.min_distance = msg.min_distance;
  mav_obs.max_distance = msg.max_distance;

  mavlink_message_t mav_msg;
  mavlink_msg_obstacle_distance_3d_encode(1, 1, &mav_msg, &mav_obs);
  proximity->handle_msg(mav_msg);
}

#endif // AP_DDS_OBSTACLE_DISTANCE_SUB_ENABLED
