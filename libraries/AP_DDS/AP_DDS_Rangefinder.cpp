#include "AP_DDS_Rangefinder.h"

#if AP_DDS_RANGEFINDER_SUB_ENABLED

#include "AP_DDS_Type_Conversions.h"
#include <AP_RangeFinder/AP_RangeFinder.h>
#include <GCS_MAVLink/GCS.h>

void AP_DDS_Rangefinder::handle_external_rangefinder(
    const sensor_msgs_msg_Range &msg) {

  auto *rangefinder = AP::rangefinder();
  if (rangefinder == nullptr) {
    return;
  }

  mavlink_distance_sensor_t mavlink_msg = {};

  mavlink_msg.min_distance = uint16_t(msg.min_range * 100.0f);
  mavlink_msg.max_distance = uint16_t(msg.max_range * 100.0f);
  mavlink_msg.current_distance = uint16_t(msg.range * 100.0f);

  // Map ROS radiation_type to MAVLink distance sensor type
  // ROS: ULTRASOUND=0, INFRARED=1
  // MAVLink: LASER=0, ULTRASOUND=1, INFRARED=2, RADAR=3, UNKNOWN=4
  uint8_t mav_type = MAV_DISTANCE_SENSOR_UNKNOWN;
  if (msg.radiation_type == 0) {
    // ULTRASOUND in ROS maps to ULTRASOUND in MAVLink
    mav_type = MAV_DISTANCE_SENSOR_ULTRASOUND;
  } else if (msg.radiation_type == 1) {
    // INFRARED in ROS maps to INFRARED in MAVLink
    mav_type = MAV_DISTANCE_SENSOR_INFRARED;
  }
  mavlink_msg.type = mav_type;

  mavlink_msg.id = 0;
  // Dynamically map the ROS frame_id to a MAVLink orientation
  // MAVLink Orientations: 0 = Forward, 25 = Downward, 24 = Upward
  if (strcmp(msg.header.frame_id, "rangefinder_forward_link") == 0) {
    mavlink_msg.orientation = 0; // ROTATION_NONE (Forward)
  } else if (strcmp(msg.header.frame_id, "rangefinder_up_link") == 0) {
    mavlink_msg.orientation = 24; // ROTATION_PITCH_90 (Up)
  } else {
    // Default to downward for "rangefinder_link" or unknown frames
    mavlink_msg.orientation = 25; // ROTATION_PITCH_270 (Down)
  }
  mavlink_msg.signal_quality = 100;

  mavlink_message_t mav_msg;
  mavlink_msg_distance_sensor_encode(1, 1, &mav_msg, &mavlink_msg);

  rangefinder->handle_msg(mav_msg);
}

#endif // AP_DDS_RANGEFINDER_SUB_ENABLED
