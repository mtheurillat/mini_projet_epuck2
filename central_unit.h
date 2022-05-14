#ifndef CENTRAL_UNIT_H
#define CENTRAL_UNIT_H

//List of the different mode, i.e the different tasks that the robot must perform for our application
typedef enum {
	IDLE,
	STOP,
	ANALYSE,
	ALIGN,
	AVOID,
	PURSUIT,
	MEASURE,
	PUSH,
	ROTATE_BEFORE_FOLLOW, //////////////////////////////////////////////////////////////////////// test_max_1205 created
	FOLLOW,
	EXIT,
	PUSH_OUT,
	RECENTER
} task_mode;

//start the central unit thread
void central_unit_start(void);

void set_mode_with_selector(void);
void set_straight_move_in_mm(int distance_in_mm);


uint32_t degrees_to_motor_step(uint16_t degrees);

#endif /* CENTRAL_UNIT_H */
