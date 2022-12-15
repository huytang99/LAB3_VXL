/*
 * global.h
 *
 *
 */

#include "software_timer.h"
#include "Button.h"
#include "main.h"
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4

#define MAN_RED 10
#define MAN_GREEN 11
#define MAN_YELLOW 12

extern int status;
extern int status_2;

extern int time_red;
extern int time_yellow;
extern int time_green;
extern int time_red2;
extern int time_yellow2;
extern int time_green2;
extern int index_led;
extern int index_led2;
extern int SEG_buffer[4];

extern int initRED;
extern int initGREEN;
extern int initYELLOW;
extern int initRED2;
extern int initGREEN2;
extern int initYELLOW2;

#endif /* INC_GLOBAL_H_ */
