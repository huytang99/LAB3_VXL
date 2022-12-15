/*
 * fsm_automatic.c
 *
 *
 */


#include "fsm_automatic.h"
#include "software_timer.h"
#include "global.h"
#include "main.h"
#include "display_led.h"


void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = AUTO_RED;
		setTimer1(initRED*100);
		setTimer2(100);
		setTimer4(50);
		index_led =0;
		break;
	case AUTO_RED:
		if(time_red == 0) time_red = initRED;
		if(index_led > 1) index_led =0;
		addTime(time_red);
		update7SEG(index_led);
		if(timer2_flag == 1){
			time_red--;
			setTimer2(100);
		}
		if(timer4_flag == 1)
		{
			index_led++;
			setTimer4(50);
		}
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(initGREEN*100);
			time_green =0;
			setTimer2(100);
			setTimer4(50);
			index_led =0;
		}
		if(is_Button1_Pressed() == 1)
		{
			status = MAN_RED;
			setTimer2(50);
			index_led =0;
			index_led2 =2;
		}
		break;
	case AUTO_GREEN:
		if(time_green == 0) time_green = initGREEN;
		if(index_led > 1) index_led =0;
		addTime(time_green);
		update7SEG(index_led);
		if(timer2_flag == 1){
			time_green--;
			setTimer2(100);
		}
		if(timer4_flag == 1)
		{
			index_led++;
			setTimer4(50);
		}
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			time_yellow=0;
			setTimer1(initYELLOW*100);
			setTimer2(100);
			setTimer4(50);
			index_led = 0;
		}
		if(is_Button1_Pressed() == 1)
		{
			status = MAN_RED;
			setTimer2(50);
			index_led =0;
			index_led2 =2;
		}
		break;
	case AUTO_YELLOW:
		if(time_yellow == 0) time_yellow = initYELLOW;
		if(index_led > 1) index_led =0;
		addTime(time_yellow);
		update7SEG(index_led);
		if(timer2_flag == 1){
			time_yellow--;
			setTimer2(100);
		}
		if(timer4_flag == 1)
		{
			index_led++;
			setTimer4(50);
		}
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
		if(timer1_flag == 1){
			status = AUTO_RED;
			time_red=0;
			setTimer1(initRED*100);
			setTimer2(100);
			setTimer4(50);
			index_led = 0;
		}
		if(is_Button1_Pressed() == 1)
		{
			status = MAN_RED;
			setTimer2(50);
			index_led =0;
			index_led2 =2;
		}
		break;
	default:
		break;
	}
}
//---fsm_automatic_2-------
void fsm_automatic_2_run(){
	switch(status_2){
	case INIT:
		status_2 = AUTO_GREEN;
		setTimer3(initGREEN*100);
		setTimer5(100);
		setTimer6(50);
		index_led2 =2;
		time_green2 =0;
		break;
	case AUTO_RED:
		if(index_led2 >3 ) index_led2 = 2;
		if(time_red2 == 0) time_red2 = initRED2;
		addTime_2(time_red2);
		update7SEG_2(index_led2);
		if(timer5_flag == 1){
			time_red2--;
			setTimer5(100);
		}
		if(timer6_flag == 1)
		{
			index_led2++;
			setTimer6(50);
		}
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		if(timer3_flag == 1){
			status_2 = AUTO_GREEN;
			setTimer3(initGREEN2*100);
			setTimer5(100);
			setTimer6(50);
			time_green2 =0;
		}
		if(status == MAN_RED)
		{
			status_2 = 100;
		}
		break;
	case AUTO_GREEN:
		if(index_led2 >3 ) index_led2 = 2;
		if(time_green2 == 0) time_green2 = initGREEN2;
		addTime_2(time_green2);
		update7SEG_2(index_led2);
		if(timer5_flag == 1){
			time_green2--;
			setTimer5(100);
		}
		if(timer6_flag == 1)
		{
			index_led2++;
			setTimer6(50);
		}
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		if(timer3_flag == 1){
			status_2 = AUTO_YELLOW;
			time_yellow2=0;
			setTimer3(initYELLOW2*100);
			setTimer5(100);
			setTimer6(50);
		}
		if(status == MAN_RED)
		{
			status_2 = 100;

		}
		break;
	case AUTO_YELLOW:
		if(index_led2 >3 ) index_led2 = 2;
		if(time_yellow2 == 0) time_yellow2 = initYELLOW2;
		addTime_2(time_yellow2);
		update7SEG_2(index_led2);
		if(timer5_flag == 1){
			time_yellow2--;
			setTimer5(100);
		}
		if(timer6_flag == 1)
		{
			index_led2++;
			setTimer6(50);
		}
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
		if(timer3_flag == 1){
			status_2 = AUTO_RED;
			time_red2=0;
			setTimer3(initRED2*100);
			setTimer5(100);
			setTimer6(50);
		}
		if(status_2 == MAN_RED)
		{
			status_2 = 100;
		}
		break;
	default:
		break;
	}
}
