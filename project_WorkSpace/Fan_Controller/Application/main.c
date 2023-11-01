/*
 * main.c
 *
 *  Created on: Oct 31, 2023
 *      Author: BILAL
 */

#include "../MCAL/gpio.h"
#include "../MCAL/adc.h"
#include "../HAL/lcd.h"
#include "../HAL/lm35_sensor.h"
#include "../HAL/DC_Motor.h"
#include "../MCAL/PWM0.h"

uint16 read_temp ;

void main(void)
{
	uint8 read_temp ;

	//initialize the ADC driver.
	ADC_ConfigType adc_config = {Internal_2_56V,F_CPU_8};
	ADC_init(&adc_config);

	//Initialize the LCD driver.
	LCD_init();

	//Initialize the DC Motor driver.
	DcMotor_Init();

	LCD_displayString("Fan is ");
	LCD_displayStringRowColumn(1, 0, "Temp = ");

	while(1)
	{
		read_temp = LM35_getTemperature();

		if(read_temp < 30)
		{
			DcMotor_Rotate(STOP_DcMotor, 0);
			LCD_displayStringRowColumn(0, 7, "OFF");
		}
		else if(read_temp >= 30 && read_temp < 60)
		{
			DcMotor_Rotate(CW_DcMotor, 64);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}
		else if(read_temp >= 60 && read_temp < 90)
		{
			DcMotor_Rotate(CW_DcMotor, 128);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}
		else if(read_temp >= 90 && read_temp < 120)
		{
			DcMotor_Rotate(CW_DcMotor, 192);
			LCD_displayStringRowColumn(0, 7, "ON ");
		}
		else if(read_temp >= 120)
		{
			DcMotor_Rotate(CW_DcMotor, 255);
			LCD_displayStringRowColumn(0, 7, "ON");
		}
		LCD_moveCursor(1,7);
		if(read_temp >= 100)
		{
			LCD_intgerToString(read_temp);
		}
		else
		{
			LCD_displayCharacter(' ');
			LCD_intgerToString(read_temp);
			/* In case the digital value is two or one digits print space in the next digit place */

		}
		LCD_moveCursor(1, 10);
		LCD_displayCharacter('C');
	}
}
