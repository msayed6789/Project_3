/*
 * app.c
 *
 * Created: 4/23/2023 1:08:54 PM
 *  Author: Mohamed Sayed
 */ 


#include "app.h"

#define MAX_TEMP      35      //Temperature in Celsius
#define MIN_TEMP      18      //Temperature in Celsius
#define DEFAULT_TEMP  20.0    //Temperature in Celsius
/******************************************************Wire*****************************************************/
#define BUZZER_LED    PIND6
#define KEYPAD_ROW    PINB0
#define KEYPAD_COL    PINB4
#define TEMP_SENSOR   PINA0
/***************************************************************************************************************/
volatile f32 Req_Temp=DEFAULT_TEMP;
volatile f32 Act_Temp=0;
volatile u8 num=0;
volatile u8 Loop_flag=1;
u8 Display_flag=0;
u8 keypad_flag=0;
volatile u32 Timeout=3;              //Time in sec
u8 bell[8]={0x04,0x0E,0x0E,0x0E,0x1F,0x00,0x04,0x00};
	
void App_init(void)
{
	sei();
	LCD_init();
	keypad_flag=KEYPAD_Init(KEYPAD_ROW,KEYPAD_COL);
	while(keypad_flag!=Done)
	{
          LCD_sendString("The Keypad Pins");
		  LCD_setCursor(1,0);
		  LCD_sendString("are error");
		  Delay_ms(5000);
		  LCD_clear();
	}
	Temp_init(TEMP_SENSOR);
	bazz_init(BUZZER_LED);
	LCD_createCustomCharacter(bell,0);
	LCD_setCursor(0,5);
	LCD_sendString("Welcome");
	Delay_ms(2000);
	LCD_clear();
	LCD_sendString("Default temp is ");
	LCD_setCursor(1,0);
	LCD_sendString("Temp= ");
	LCD_floattostring(Req_Temp);
	LCD_sendChar('C');
	Delay_ms(2000);
	LCD_clear();
	LCD_sendString ("choose temp");
	Delay_ms(2000);
	LCD_clear();
	LCD_sendString("Min Temp= ");
	LCD_floattostring(MIN_TEMP);
	LCD_sendChar('C');
	LCD_setCursor(1,0);
	LCD_sendString("Max Temp= ");
	LCD_floattostring(MAX_TEMP);
	LCD_sendChar('C');
	Delay_ms(2000);
	LCD_clear();
	LCD_sendString("1)Increment");
	LCD_setCursor(1,0);
	LCD_sendString("2)Decrement3)set");
	Delay_ms(2000);
	LCD_clear();
	LCD_sendString("Temp= ");
	LCD_floattostring(Req_Temp);
	LCD_sendChar('C');
	while(Loop_flag)
	{
		num=KEYPAD_GetNum_time(Timeout);
		switch (num)
		{
			case 1:
			Req_Temp=Req_Temp+1.0;
			if (Req_Temp>=MAX_TEMP)
			{
				Req_Temp=MAX_TEMP;
				LCD_setCursor(1,0);
				LCD_sendString("Max Temp= ");
				LCD_floattostring(MAX_TEMP);
				LCD_sendChar('C');
				Display_flag=1;
			}
			else if (Display_flag==1&&Req_Temp<MAX_TEMP)
			{
				LCD_clear();
				Display_flag=0;
			}
			LCD_setCursor(0,0);
			LCD_sendString("Temp= ");
			LCD_floattostring(Req_Temp);
			LCD_sendChar('C');
			num=NO_KEY;
			break;
			case 2:
			Req_Temp=Req_Temp-1.0;
			if (Req_Temp<=MIN_TEMP)
			{
				Req_Temp=MIN_TEMP;
				LCD_setCursor(1,0);
				LCD_sendString("Min Temp= ");
				LCD_floattostring(MIN_TEMP);
				LCD_sendChar('C');
				Display_flag=1;
			}
			else if (Display_flag==1&&Req_Temp>MIN_TEMP)
			{
				LCD_clear();
				Display_flag=0;
			}
			LCD_setCursor(0,0);
			LCD_sendString("Temp= ");
			LCD_floattostring(Req_Temp);
			LCD_sendChar('C');
			num=NO_KEY;
			break;
			case 3:
			LCD_clear();
			LCD_sendString("The set Temp is");
			LCD_setCursor(1,0);
			LCD_floattostring(Req_Temp);
			LCD_sendChar('C');
			Delay_ms(2000);
			LCD_clear();
			LCD_sendString("Temp is set");
			LCD_setCursor(1,0);
			LCD_sendString("successfully");
			Delay_ms(2000);
			LCD_clear();
			Loop_flag=0;
			num=NO_KEY;
			break;
			case NO_KEY:
			LCD_clear();
			LCD_sendString("Timeout");
			LCD_setCursor(1,0);
			LCD_sendString("Temp= ");
			LCD_floattostring(Req_Temp);
			LCD_sendChar('C');
			Loop_flag=0;
			num=NO_KEY;
			Delay_ms(2000);
			LCD_clear();
			break;
			default:
			LCD_clear();
			LCD_sendString("This operation");
			LCD_setCursor(1,0);
			LCD_sendString("is not allowed");
			Delay_ms(2000);
			LCD_clear();
			LCD_sendString("Temp= ");
			LCD_floattostring(Req_Temp);
			LCD_sendChar('C');
			num=NO_KEY;
		}
	}
	num=NO_KEY;
	Loop_flag=1;
}
void App_start(void)
{
	LCD_setCursor(0,0);
	Act_Temp=Temp_Read(TEMP_SENSOR);
	LCD_sendString("Temp=  C");
	LCD_setCursor(0,6);
	LCD_floattostring(Act_Temp);
	if (Act_Temp>Req_Temp)
	{
		bazz_ON(BUZZER_LED);
		LCD_setCursor(1,0);
		LCD_sendChar(0);
	}
	else if (Act_Temp<Req_Temp)
	{
		bazz_OFF(BUZZER_LED);
		LCD_setCursor(1,0);
		LCD_sendChar(' ');
	}
	num=KEYPAD_GetNum_time(Timeout);
	switch (num)
	{
		case 4:
		bazz_OFF(BUZZER_LED);
		LCD_clear();
		LCD_sendString ("choose temp");
		Delay_ms(2000);
		LCD_clear();
		LCD_sendString("Min Temp= ");
		LCD_floattostring(MIN_TEMP);
		LCD_sendChar('C');
		LCD_setCursor(1,0);
		LCD_sendString("Max Temp= ");
		LCD_floattostring(MAX_TEMP);
		LCD_sendChar('C');
		Delay_ms(2000);
		LCD_clear();
		LCD_sendString("1)Increment");
		LCD_setCursor(1,0);
		LCD_sendString("2)Decrement3)set");
		Delay_ms(2000);
		LCD_clear();
		LCD_sendString("Temp= ");
		LCD_floattostring(Req_Temp);
		LCD_sendChar('C');
		while (Loop_flag)
		{
			num=KEYPAD_GetNum_time(Timeout);
			switch (num)
			{
				case 1:
				Req_Temp=Req_Temp+1.0;
				if (Req_Temp>=MAX_TEMP)
				{
					Req_Temp=MAX_TEMP;
					LCD_setCursor(1,0);
					LCD_sendString("Max Temp= ");
					LCD_floattostring(MAX_TEMP);
					LCD_sendChar('C');
					Display_flag=1;
				}
				else if (Display_flag==1&&Req_Temp<MAX_TEMP)
				{
					LCD_clear();
					Display_flag=0;
				}
				LCD_setCursor(0,0);
				LCD_sendString("Temp= ");
				LCD_floattostring(Req_Temp);
				LCD_sendChar('C');
				num=NO_KEY;
				break;
				case 2:
				Req_Temp=Req_Temp-1.0;
				if (Req_Temp<=MIN_TEMP)
				{
					Req_Temp=MIN_TEMP;
					LCD_setCursor(1,0);
					LCD_sendString("Min Temp= ");
					LCD_floattostring(MIN_TEMP);
					LCD_sendChar('C');
					Display_flag=1;
				}
				else if (Display_flag==1&&Req_Temp>MIN_TEMP)
				{
					LCD_clear();
					Display_flag=0;
				}
				LCD_setCursor(0,0);
				LCD_sendString("Temp= ");
				LCD_floattostring(Req_Temp);
				LCD_sendChar('C');
				num=NO_KEY;
				break;
				case 3:
				LCD_clear();
				LCD_sendString("The set Temp is");
				LCD_setCursor(1,0);
				LCD_floattostring(Req_Temp);
				LCD_sendChar('C');
				Delay_ms(2000);
				LCD_clear();
				LCD_sendString("Temp is set");
				LCD_setCursor(1,0);
				LCD_sendString("successfully");
				Delay_ms(2000);
				LCD_clear();
				Loop_flag=0;
				num=NO_KEY;
				break;
				case NO_KEY:
				LCD_clear();
				LCD_sendString("Timeout");
				LCD_setCursor(1,0);
				LCD_sendString("Temp= ");
				LCD_floattostring(Req_Temp);
				LCD_sendChar('C');
				Loop_flag=0;
				num=NO_KEY;
				Delay_ms(2000);
				LCD_clear();
				break;
				default:
				LCD_clear();
				LCD_sendString("This operation");
				LCD_setCursor(1,0);
				LCD_sendString("is not allowed");
				Delay_ms(2000);
				num=NO_KEY;
				LCD_clear();
				LCD_sendString("Temp= ");
				LCD_floattostring(Req_Temp);
				LCD_sendChar('C');
				num=NO_KEY;
			}
		}
		break;
		case 5:
		bazz_OFF(BUZZER_LED);
		Req_Temp=DEFAULT_TEMP;
		LCD_clear();
		LCD_sendString("The set Temp is");
		LCD_setCursor(1,0);
		LCD_floattostring(Req_Temp);
		LCD_sendChar('C');
		Delay_ms(2000);
		LCD_clear();
		Loop_flag=1;
		num=NO_KEY;
		break;
	}
}
