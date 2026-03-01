# EKF Status message
# Contains EKF variance information
std_msgs/Header header

float32 velocity_variance
float32 position_variance
float32 height_variance

geometry_msgs/Vector3 magnetic_variance

float32 true_airspeed_variance

bool healthy
