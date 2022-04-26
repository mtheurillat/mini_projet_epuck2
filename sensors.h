#ifndef SENSORS_H
#define SENSORS_H

float get_distance_cm(void);
uint16_t get_line_position(void);
void process_image_start(void);
void set_led_with_int(unsigned int led_int_number, unsigned int value);

#endif /* SENSORS_H */