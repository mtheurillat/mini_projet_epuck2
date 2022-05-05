#ifndef PROXI_H
#define PROXI_H

// Id proximity sensor
#define PROX_FRONT_RIGHT_17 			0 // IR 1
#define PROX_FRONT_LEFT_17				7 // IR 8
#define PROX_FRONT_RIGHT_49 			1 // IR 2
#define PROX_FRONT_LEFT_49				6 // IR 7
#define PROX_RIGHT						2 // IR 3
#define PROX_BACK_RIGHT 				3 // IR 4
#define PROX_LEFT						5 // IR 6
#define PROX_BACK_LEFT					4 // IR 5

bool* get_prox_activation_status(int prox_detection_threshold);
int* get_prox_value(void);

void test_prox_with_leds(unsigned int sensor_number);
void read_IR_start(void);
void obstacles_avoidance_algorithm(void);
void rotate_left(int speed);
void rotate_right(int speed);
void rotate_right_in_degrees(int speed, float degrees);
void motor_stop(void);

#endif /* PROXI_H */
