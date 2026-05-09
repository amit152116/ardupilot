# State topic from ArduPilot
#
# For system_status values
# see https://mavlink.io/en/messages/common.html#MAV_STATE
#

std_msgs/Header header

# System mode (raw ArduPilot mode number)
ardupilot_msgs/Mode flight_mode

# Connection status
uint8 gps_fix

# System status (MAV_STATE)
uint8 system_status

# Armed status
bool armed

# Guided status
bool guided

# Manual input status
bool manual_input

uint8 GPS_NO_GPS=0
uint8 GPS_NO_FIX=1
uint8 GPS_FIX_2D=2
uint8 GPS_FIX_3D=3
uint8 GPS_FIX_DGPS=4
uint8 GPS_FIX_RTK_FLOAT=5
uint8 GPS_FIX_RTK_FIXED=6


uint8 MAV_STATE_UNINIT = 0
uint8 MAV_STATE_BOOT = 1
uint8 MAV_STATE_CALIBRATING = 2
uint8 MAV_STATE_STANDBY = 3
uint8 MAV_STATE_ACTIVE = 4
uint8 MAV_STATE_CRITICAL = 5
uint8 MAV_STATE_EMERGENCY = 6
uint8 MAV_STATE_POWEROFF = 7
uint8 MAV_STATE_FLIGHT_TERMINATION = 8
