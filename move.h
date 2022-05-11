#ifndef MOVE_H
#define MOVE_H

//List of the different mode, i.e the different tasks that the robot must perform for our application
typedef enum {
	STOP,
	SPIN_RIGHT,
	SPIN_LEFT,
	MOVE_STRAIGHT,
} moving_mode;

void spin_angle_degree(uint16_t angle_in_degree);
void move_start(void);
bool toggle_boolean(bool x);
void stopMove(void);
void update_currentModeInMove(uint8_t mode);

void rotate_left(int speed);
void rotate_right(int speed);
// void rotate_right_in_degrees(int speed, float degrees);
void motor_stop(void);
void avoid_obstacles(int speed, int prox_detection_threshold);

#endif /* MOVE_H */
//uint16_t angle_in_degree
