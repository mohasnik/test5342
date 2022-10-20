#include "holtekstartup.h"
#include "stdint.h"
#include "sensor.h"
#include "modbus.h"



#define N 0x02
#define FREQUENCY 12 //s_sys = 12 MHz


//defining interrupt service routines:



extern Sensor sensor;
extern uint8_t slave_id;






void main()
{
	//initialization of microcontroller :
	initial(FREQUENCY);
	UART_Init(UART_ST1_EN_INTERRUPT | UART_ST1_EN_RX_INT | UART_ST1_MULTBY4, UART_ST2_NOSETTINGS, N);
	
	//PA2_SETMODE_TX;
	PA5_SETMODE_SDO_TX;
	//PA0_SETMODE_RX;
	PA4_SETMODE_SDI_RX;
	
	//PB0_SETMODE_IO;
	PA1_SETMODE_OUTPUT;
	_sledc0 = 1;
	_sledc1 = 1;
	_pa1 = 0;
	
	PA6_SETMODE_OUTPUT;
	_pa6 = 0;
	
	
	ADC_Init();
	ADC_ENABLEINTERRUPT;
	
	
	

	while(TRUE) {
		//GCC_NOP();
		
		
		//filtering adc data :
		if(state & STATE_ADC_FLAG_RAISED)
		{
      		_ade = 0;
      		
      		uint8_t i = 0; 
      		
     		for(i; i<WINDOW - 1; i++) {
     			sensor_weight_window[WINDOW - i - 1] = sensor_weight_window[WINDOW - i -2];
     		}
     		
     		sensor.old_weight += 0X800000;
     		
			sensor_weight_window[0] = sensor.old_weight;
			
			_emi =1;
			Sensor_Weight_Filter();
			
	  		
	  		sensor.old_weight = sensor.new_weight;
			
			state &= ~STATE_ADC_FLAG_RAISED;
			
			_ade = 1;
			
			 
		}
		
		
		
	}
	
}

