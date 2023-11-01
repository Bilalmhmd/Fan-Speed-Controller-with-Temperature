 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Bilal Mohamed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


#define Channel_0          0
#define Channel_1          1
#define Channel_2          2
#define Channel_3          3
#define Channel_4          4
#define Channel_5          5
#define Channel_6          6
#define Channel_7          7



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


typedef enum
{
	AREF,AVCC_5V,Internal_2_56V =3
}ADC_Verf;


typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct {
 ADC_Verf volt;
 ADC_Prescaler prescaler;
} ADC_ConfigType;


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
