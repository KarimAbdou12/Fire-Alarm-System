

#define LED_PROG  1 

#include "StdTypes.h"
#include "DIO_Int.h"
#include "LED_Int.h"
#include "LED_Cfg.h"


void Led_Status (LED_Selec_t led,status_t status)
{
	if(status==ON)
	{
		DIO_WritePin(Led_arr[led],HIGH);
	}
	else if (status==OFF)
	{
		DIO_WritePin(Led_arr[led],LOW);		
	}
}

void BUZZER_Status (status_t status)
{
	if(status==ON)
	{
		DIO_WritePin(BUZZER_CH,HIGH);
	}
	else if (status==OFF)
	{
		DIO_WritePin(BUZZER_CH,LOW);
	}
}