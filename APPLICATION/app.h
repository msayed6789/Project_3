/*
 * app.h
 *
 * Created: 4/23/2023 1:09:07 PM
 *  Author: AIO
 */ 


#ifndef APP_H_
#define APP_H_
#include "LCD.h"
#include "KeyPad.h"
#include "sensor.h"
#include "buzzer.h"
#include "delay.h"

/*********************************************************Configuration*****************************************/
#define MAX_TEMP      35      //Temperature in Celsius
#define MIN_TEMP      18      //Temperature in Celsius
#define DEFAULT_TEMP  20.0
/******************************************************Wire*****************************************************/
#define BUZZER_LED    PINB3
#define KEYPAD_ROW    PINC2
#define KEYPAD_COL    PINC5
#define TEMP_SENSOR   PINA0
/***************************************************************************************************************/

void App_init(void);
void App_start(void);



#endif /* APP_H_ */
