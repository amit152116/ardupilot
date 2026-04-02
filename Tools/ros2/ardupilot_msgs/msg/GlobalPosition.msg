# Experimental REP-147 Goal Interface

std_msgs/Header header

# --- VARIABLES (Optimized for 0 Padding) ---
# 8-Byte Aligned
geometry_msgs/Twist velocity
geometry_msgs/Twist acceleration_or_force
float64 latitude
float64 longitude

# 4-Byte Aligned
float32 altitude
float32 yaw

# 2-Byte Aligned
uint16 type_mask

# 1-Byte Aligned
uint8 coordinate_frame


# --- CONSTANTS (Zero bytes over the network) ---
uint16 IGNORE_LATITUDE = 1 
uint16 IGNORE_LONGITUDE = 2
uint16 IGNORE_ALTITUDE = 4
uint16 IGNORE_VX = 8
uint16 IGNORE_VY = 16
uint16 IGNORE_VZ = 32
uint16 IGNORE_AFX = 64
uint16 IGNORE_AFY = 128
uint16 IGNORE_AFZ = 256
uint16 FORCE = 512
uint16 IGNORE_YAW = 1024
uint16 IGNORE_YAW_RATE = 2048

uint8 FRAME_GLOBAL_INT = 5
uint8 FRAME_GLOBAL_REL_ALT = 6
uint8 FRAME_GLOBAL_TERRAIN_ALT = 11
