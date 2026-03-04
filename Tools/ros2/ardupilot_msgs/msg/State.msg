# State topic from ArduPilot
#
# For system_status values
# see https://mavlink.io/en/messages/common.html#MAV_STATE
#

std_msgs/Header header

# Connection status
uint8 gps_fix

# Armed status
bool armed

# Guided status
bool guided

# Manual input status
bool manual_input

# System mode (raw ArduPilot mode number)
uint8 mode

# System status (MAV_STATE)
uint8 system_status

uint8 GPS_NO_GPS=0
uint8 GPS_NO_FIX=1
uint8 GPS_FIX_2D=2
uint8 GPS_FIX_3D=3
uint8 GPS_FIX_DGPS=4
uint8 GPS_FIX_RTK_FLOAT=5
uint8 GPS_FIX_RTK_FIXED=6
