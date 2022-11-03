#include "modbus.h"
#include "sensor.h"

extern Sensor sensor;


DEFINE_ISR(UartCallBack, 0x18);



uint8_t slave_id;
uint8_t uart_index = 0;
uint8_t frame[FRAME_SIZE];




void UART_Init(uint8_t status1,uint8_t status2, uint8_t N)
{
	
	_umd = 1; // 1 : UART, 0 : SPI or I2C
	
	//checkout other SIMC0 bits  for SPI or I2C configuration!
	
	
	_uren = 1;
	_utxen = 1;
	_urxen = 1;
	
	//SIMC0 :
	
	
	
	_uucr2 |= status1 & UART_ST1_UUCR2;
	
	
	_ubrg = N;
	
	//UUCR1:
	
	
	if(status1 & UART_ST1_EN_INTERRUPT) {
		_emi = 1;
		_usime = 1;
		
	}
	

	_uucr1 |= status2;
	
	
	
}


	
void UartCallBack(void)
{
	_pa1 = 0;

	
	do{
		
		
		frame[0] = frame[1];
		frame[1] = frame[2];
		frame[2] = frame[3];
		frame[3] = frame[4];
		frame[4] = frame[5];
		frame[5] = frame[6];
		frame[6] = _utxr_rxr;
		
		uart_index++;	
			
		if(frame[0] == FRAME_HEADER && frame[FRAME_SIZE - 1] == FRAME_FOOTER && frame[1] == slave_id) {
			
			
			uint8_t i = 0;
			uint8_t crc = 0xff;
			
			for(i = 0; i <FRAME_SIZE - 2; i++) {
				crc ^= frame[i];
			}
				
			if(frame[5] == crc) {		
				UART_SEND_FRAME();
				uart_index = 0;
						
			}
					
		}
		else {
			uart_index = 0;
		}
		
		
	}while(_urxif);
	
	
	

	
}
