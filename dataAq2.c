#include "holtekstartup.h"
#include "stdint.h"
#include "sensor.h"
#include "modbus.h"


#define N 0x02
#define FREQUENCY 12 //s_sys = 4 MHz


//defining interrupt service routines:


extern Sensor sensor;
extern uint8_t slave_id;

void main()
{
	//initialization of microcontroller :
	initial(FREQUENCY);
	UART_Init(UART_ST1_ENABLE_INT | UART_ST1_EN_RX_INT | UART_ST1_MULTBY4, UART_ST2_NOSETTINGS, N);
	
	PA2_SETMODE_TX;
	PA0_SETMODE_RX;
	PB0_SETMODE_IO;
	_pbc0 = 0;
	_pb0 = 0;
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

