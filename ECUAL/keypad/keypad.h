/*
 * KeyPad.h
 *
 * Created: 12/11/2022 8:40:49 PM
 *  Author: M.Sayed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "dio.h"

#include "timeout.h"
/*************************config**********************/

#define COL   4
#define ROW   4

#define  NO_KEY  'N'

static u8 KeysArray[ROW][COL]={{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'c','0','=','+'}};


/*******************************************************/
typedef enum{
	
	Done,
	Error
}Keypad_Status_en;


Keypad_Status_en KEYPAD_Init(PIn_name First_Output,PIn_name Firs_Input);

u8 KEYPAD_GetNum_time(u32 timeout); //timeout is time in sec







#endif /* KEYPAD_H_ */
