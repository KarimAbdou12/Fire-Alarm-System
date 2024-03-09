/*
 * Fire_System.c
 *
 * Created: 2/23/2024 8:45:32 PM
 * Author : Karim Abdou 
 */ 

/*******************************************************/
 
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "ADC_Int.h"
#include "KEYPAD_Int.h"
#include "LCD_Int.h"
#include "Sensors_Int.h"
#include "DCMOTOR_Int.h"
#include "FireSystem_Int.h"


#define F_CPU 8000000
#include "util/delay.h"



int main(void)
{
	DIO_Init();
	KEYPAD_Init();
	LCD_Init();
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);

	FireSystem_Init();
		
    while (1) 
    {
		FireSystem_Runnable();
    }
}
