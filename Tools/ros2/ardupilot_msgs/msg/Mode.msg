
# Mode constants (ArduPilot):
uint8 STABILIZE = 0    # manual airframe angle with manual throttle
uint8 ACRO = 1         # manual body-frame angular rate with manual throttle
uint8 ALT_HOLD = 2     # manual airframe angle with automatic throttle
uint8 AUTO = 3         # fully automatic waypoint control using mission commands
uint8 GUIDED = 4       # fully automatic fly to coordinate or fly at velocity/direction using GCS immediate commands
uint8 LOITER = 5       # automatic horizontal acceleration with automatic throttle
uint8 RTL = 6          # automatic return to launching point
uint8 CIRCLE = 7       # automatic circular flight with automatic throttle
uint8 LAND = 9         # automatic landing with horizontal position control
uint8 DRIFT = 11       # semi-autonomous position, yaw and throttle control
uint8 SPORT = 13       # manual earth-frame angular rate control with manual throttle
uint8 FLIP = 14        # automatically flip the vehicle on the roll axis
uint8 AUTOTUNE = 15    # automatically tune the vehicle's roll and pitch gains
uint8 POSHOLD = 16     # automatic position hold with manual override, with automatic throttle
uint8 BRAKE = 17       # full-brake using inertial/GPS system, no pilot input
uint8 THROW = 18       # throw to launch mode using inertial/GPS system, no pilot input
uint8 AVOID_ADSB = 19  # automatic avoidance of obstacles in the macro scale - e.g. full-sized aircraft
uint8 GUIDED_NOGPS = 20 # guided mode but only accepts attitude and altitude
uint8 SMART_RTL = 21   # SMART_RTL returns to home by retracing its steps
uint8 FLOWHOLD = 22    # holds position with optical flow without rangefinder
uint8 FOLLOW = 23      # follow attempts to follow another vehicle or ground station
uint8 ZIGZAG = 24      # fly in a zigzag manner with predefined point A and point B
uint8 SYSTEMID = 25    # produces automated system identification signals in the controllers
uint8 AUTOROTATE = 26  # autonomous autorotation
uint8 AUTO_RTL = 27    # Auto RTL, AUTO will report as this mode if entered to perform a DO_LAND_START Landing sequence
uint8 TURTLE = 28      # flip over after crash
