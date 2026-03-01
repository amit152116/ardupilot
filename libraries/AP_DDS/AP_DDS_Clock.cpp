
#include "AP_DDS_Clock.h"
#include "AP_DDS_Type_Conversions.h"

#if AP_DDS_CLOCK_SUB_ENABLED

#include <AP_RTC/AP_RTC.h>
#include <GCS_MAVLink/GCS.h>

void AP_DDS_Clock::handle_clock_update(const rosgraph_msgs_msg_Clock &msg) {
  // Convert ROS time to microseconds
  const uint64_t time_us = AP_DDS_Type_Conversions::time_u64_micros(msg.clock);

  // Set the system clock using the DDS clock source
  // Using SOURCE_GPS as the source type to give DDS clock the highest priority.
  // This assumes the companion computer has a reliable time source (e.g.,
  // NTP/PTP). This allows the companion computer clock to override GPS time.
  AP_RTC::get_singleton()->set_utc_usec(time_us, AP_RTC::SOURCE_GPS);
}

#endif // AP_DDS_CLOCK_SUB_ENABLED
