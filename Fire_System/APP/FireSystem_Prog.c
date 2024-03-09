
#include "StdTypes.h"
#include "LCD_Int.h"
#include "KEYPAD_Int.h"
#include "Sensors_Int.h"
#include "DCMOTOR_Int.h"
#include "LED_Int.h"
#include "FireSystem_Cfg.h"
#include "FireSystem_Int.h"


#define  F_CPU   8000000
#include <util/delay.h>


static u8 firemode_flag=0x55;

void Normal_Mode (u16 temp)
{
	u8 remainder=0;
	remainder=temp%10;
	temp=temp/10;
	
	LCD_SetCursor(1,7);
	if(firemode_flag==0X55)
	{
		LCD_WriteString("NORMAL");
	}
	else
	{
		LCD_WriteString("FIRE");
	}
	
	LCD_WriteString("      ");
	LCD_SetCursor(2,1);
	LCD_WriteString("T:");
	LCD_WriteNumber(temp);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder);
	LCD_WriteString("     ");
	
	LCD_SetCursor(2,11);
	LCD_WriteString("      ");
	
	if(firemode_flag==0X55)
	{
		// motor off
		MOTOR_Stop(M1);
		MOTOR_Stop(M2);
	
		// leds off
		Led_Status(LED_YELLOW,OFF);
		Led_Status(LED_RED,OFF);
		
		BUZZER_Status(OFF);
	}
	
	
	
}

void Inter_Passward (u16 temp,u8 k)  // u16 temp,u8 k
{
	u8 i=0;
	u8 flag=0x55;
	const u8 pass_arr[5]={'1','2','3','4','5'};
	u8 passward[5];
	
	LCD_Clear();
	LCD_SetCursor(1,2);
	LCD_WriteString("ENTER PASSWARD");
	LCD_SetCursor(2,7);
	
	passward[i]=k;
	LCD_WriteChar('*');
	i++;
	
	while(i!=5)
	{
		k=KEYPAD_GetKey();
		if(k!=NO_KEY)
		{
			if(k>='0'&&k<='9')
			{
				passward[i]=k;
				LCD_WriteChar('*');
				i++;
			}
		}
	}
	
	for(i=0;i<5;i++)
	{
		if(pass_arr[i]!=passward[i])
		{
			flag=0XAA;
			break;
		}
	}
	
	LCD_Clear();
	LCD_SetCursor(1,6);
	
	if(flag==0x55)
	{
		firemode_flag=0X55;
		LCD_WriteString("CORRECT");
		_delay_ms(1000);
		LCD_SetCursor(1,1);
		LCD_WriteString("                 ");
		Normal_Mode(temp); // Default mode
		
	}
	else
	{
		firemode_flag=0XAA;
		LCD_WriteString("WRONG");
		_delay_ms(1000);
		LCD_SetCursor(1,1);
		LCD_WriteString("                 ");
	}

	
}

void Heat_Mode (u16 temp,u16 pres_smoke)
{
	u8 remainder_temp=0;
	remainder_temp=temp%10;
	temp=temp/10;
	
	LCD_SetCursor(1,7);
	if(firemode_flag==0X55)
	{
		LCD_WriteString("HEAT");
	}
	else
	{
		LCD_WriteString("FIRE");
	}
	LCD_WriteString("      ");
	LCD_SetCursor(2,1);
	LCD_WriteString("T:");
	LCD_WriteNumber(temp);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder_temp);
	LCD_WriteString("  ");
	LCD_SetCursor(2,12);
	LCD_WriteString("SM:");
	LCD_WriteNumber(pres_smoke);
	LCD_WriteString("      ");
	
	if(firemode_flag==0X55)
	{
		// for pump
		MOTOR_CW(M1);
		MOTOR_Stop(M2);
	
		// for leds
		Led_Status(LED_YELLOW,ON);
		Led_Status(LED_RED,OFF);
		
		BUZZER_Status(OFF);
	}
	
	
	
}

void Fire_Mode (u16 temp,u16 pres_smoke)
{
	u8 remainder_temp=0;
	remainder_temp=temp%10;
	temp=temp/10;
	
	firemode_flag=0XAA;
	LCD_SetCursor(1,7);
	LCD_WriteString("FIRE");
	LCD_WriteString("      ");
	LCD_SetCursor(2,1);
	LCD_WriteString("T:");
	LCD_WriteNumber(temp);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder_temp);
	LCD_WriteString("   ");
	LCD_SetCursor(2,12);
	LCD_WriteString("SM:");
	LCD_WriteNumber(pres_smoke);
	LCD_WriteString("      ");
	
	// for pump
	MOTOR_Stop(M1);
	MOTOR_CW(M2);
	
	// for leds
	Led_Status(LED_YELLOW,OFF);
	Led_Status(LED_RED,ON);
	
	BUZZER_Status(ON);
	
}


void FireSystem_Init (void)
{
	
}

void FireSystem_Runnable (void)
{
	static u16 temp=0;
	static u8 flag=0x55;
	static u16 pres_smoke=0;
	u8 k=0;
	
	temp=TEMP_Read();
	pres_smoke =Pressure_Read();
	
	k=KEYPAD_GetKey();
	
	if(k!=NO_KEY)
	{
		Inter_Passward(temp,k);
	}
	
	if(pres_smoke>600)
	{
		Fire_Mode(temp,pres_smoke);
	}
	else if(temp>500||flag==0XAA)
	{
		flag=0XAA;
		if(temp<450)
		{
			flag=0X55;
		}
		Heat_Mode(temp,pres_smoke);
		
	}
	else if(temp<500&&flag==0x55)
	{
		Normal_Mode(temp);
	}
	
}