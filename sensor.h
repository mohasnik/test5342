#ifndef __SENSOR_H__
#define __SENSOR_H__
#include "stdint.h"
#include "holtekstartup.h"



extern uint8_t state;




typedef struct 
{
	uint32_t avg_weight;
	int32_t new_weight;
	int32_t old_weight;
	uint32_t weight_sum;
	uint32_t weight_max;
	uint32_t weight_min;
}Sensor;


void ADC_Init(void);
void AdcDataCollect(void);
void Sensor_Weight_Filter(void);


#endif