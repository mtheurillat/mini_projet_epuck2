#include "ch.h"
#include "hal.h"
#include <chprintf.h>
#include <usbcfg.h>
#include <sensors/proximity.h>
#include <leds.h>
#include <motors.h>
#include <epuck1x/utility/utility.h> //used for wait function 

#include <main.h>

#include <proxi.h>
#include <testing.h>


#define MAX_PROX_VALUE					4.095 // to remove once completed

// #define MAX_SPEED						200

// #define MOTOR_STEP_TO_DEGREES			2.7

#define PROX_DETECTION_THRESHOLD		100

#define NB_PROX_SENSORS					8

static int prox_value[NB_PROX_SENSORS];

bool* get_prox_activation_status(int prox_detection_threshold) {

	static bool prox_activation_status[NB_PROX_SENSORS];

	for (int i = 0; i < NB_PROX_SENSORS; ++i) {
		if (prox_value[i] > prox_detection_threshold) {
			prox_activation_status[i] = true;
		} else {
			prox_activation_status[i] = false;
		}
	}
	return prox_activation_status;
}

int* get_prox_value(void) {
	return prox_value;
}


// void obstacles_avoidance_algorithm(void) {

// 	if ((get_calibrated_prox(PROX_FRONT_RIGHT_49) > PROX_DETECTION_THRESHOLD) && (get_calibrated_prox(PROX_FRONT_LEFT_49) > PROX_DETECTION_THRESHOLD)) {
// 		motor_stop();
// //		rotate_left(MAX_SPEED);
// 	} else if ((get_calibrated_prox(PROX_FRONT_LEFT_49) > PROX_DETECTION_THRESHOLD) || (get_calibrated_prox(PROX_FRONT_LEFT_17) > PROX_DETECTION_THRESHOLD)) {
// 		motor_stop();
// 		rotate_right(MAX_SPEED);
// 	} else if ((get_calibrated_prox(PROX_FRONT_RIGHT_49) > PROX_DETECTION_THRESHOLD) || (get_calibrated_prox(PROX_FRONT_RIGHT_17) > PROX_DETECTION_THRESHOLD)) {
// 		motor_stop();
// 		rotate_left(MAX_SPEED);
// 	} else {
// 		motor_stop();
// 		right_motor_set_speed(MAX_SPEED);
//     	left_motor_set_speed(MAX_SPEED);
// 	}

// }

// void obstacles_follow_algorithm(void) {

// 	bool follow_mode = false; 
// 	bool exit_found = false; 

// 	if (!exit_found) {
// 		obstacles_avoidance_algorithm();
// 	} else {
// 		//rotate following external center
// 		//go straight 
// 		//go back to center
// 	}
// 	motor_stop();
// }


static THD_WORKING_AREA(waReadProx, 256); //???? How to know the size to allocate ?
static THD_FUNCTION(ReadProx, arg) {

    chRegSetThreadName(__FUNCTION__);
    (void)arg;

    systime_t time;

    while(1){

    	time = chVTGetSystemTime();

    	for (int i = 0; i < NB_PROX_SENSORS; ++i) {
			prox_value[i] = get_calibrated_prox(i);
		}	

		// --- USED FOR TESTINGS ----
		// bool *sensors_table = get_prox_activation_status(PROX_DETECTION_THRESHOLD);

		// if (sensors_table[PROX_RIGHT]) {
		// 	set_led_with_int(PROX_RIGHT);
		// } else {
		// 	clear_led_with_int(PROX_RIGHT);
		// }

    	//100Hz
        chThdSleepUntilWindowed(time, time + MS2ST(10));
    }
}

void read_prox_start(void) {
	chThdCreateStatic(waReadProx, sizeof(waReadProx), NORMALPRIO, ReadProx, NULL);
}

void test_prox_with_leds(unsigned int sensor_number) {

	volatile unsigned int prox_right_value = ((float)get_calibrated_prox(sensor_number)/(MAX_PROX_VALUE))*0.008; // Normalize proximity value to int of max value <= 9

	set_led_with_int(prox_right_value);

	wait(84000);

	clear_led_with_int(prox_right_value);

	// wait(84000);
}
