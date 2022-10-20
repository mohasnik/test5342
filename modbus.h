#ifndef __MODBUS_H__
#define __MODBUS_H__

#include "stdint.h"
#include "holtekstartup.h"

/* ----------------------------- global definitions used in all over the code ----------------------------- */
#define TRUE 1
#define FALSE 0

/* ------------------------------------- Modbus frame main definition ------------------------------------- */


#define FRAME_SIZE 7
//#define SLAVE_ID 1
#define MODBUS_RMR 0x00
#define MODBUS_CHANGE_ID 0x01
#define BROADCASTING_ID 0
#define FRAME_HEADER 0xaa
#define FRAME_FOOTER 0xbb


/* ------------------------------------- UART control Macros below ------------------------------------- */




#define UART_ST1_UUCR2 0x3f

#define UART_ST1_EN_INTERRUPT 0x40
#define UART_ST1_MULTBY4 0x20
#define UART_ST1_CHECKADDR 0x10
#define UART_ST1_WAKECTRL 0x08
#define UART_ST1_EN_RX_INT 0x04
#define UART_ST1_EN_TXIDLE_INT 0x02
#define UART_ST1_EN_TXEMPT_INT 0x01



// ------------------------------------------------------------------------------------------------




#define UART_ST2_IS9BITS 0x40
#define UART_ST2_EN_PARITY_ODD	0x30
#define UART_ST2_EN_PARITY_EVEN 0x20
#define UART_ST2_2STOPBITS 0x08
#define UART_ST2_BREAKTRANSMIT 0x04
#define UART_ST2_NOSETTINGS 0x00




 
#define UART_SEND_FRAME() \
	frame[0] = FRAME_HEADER; \
	frame[1] = slave_id; \
	frame[2] = (uint8_t)(sensor.avg_weight >> 16); \
	frame[3] = (uint8_t)(sensor.avg_weight >> 8); \
	frame[4] = (uint8_t)(sensor.avg_weight); \
	uint8_t i = 0; \
	uint8_t crc = 0xff; \
	for(i = 0; i <FRAME_SIZE - 2; i++) { \
		crc ^= frame[i]; \
	} \
	frame[5] = crc; \
	frame[6] = FRAME_FOOTER; \
	_pa1 = 1; \
 	for(i = 0; i <FRAME_SIZE; i++) { \
 		while(!_utxif); \
  		_utxr_rxr = frame[i]; \
 	} \
 	while(!_utidle); \
 	_pa1 = 0




extern uint32_t sensor_weight_window[WINDOW];
extern uint8_t state;



void UART_Init(uint8_t status1, uint8_t status2, uint8_t N);
void UartCallBack(void);

#endif