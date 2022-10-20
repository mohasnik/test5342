#ifndef __HOLTEKSETUP_H__
#define __HOLTEKSETUP_H__

#include "BH66F5242.h"


#define TRUE 1
#define FALSE 0


#define  WINDOW  6

#define STATE_ON_RISING 0x80
#define STATE_ADC_FLAG_RAISED 0x40
#define STATE_TM_RESET 0x20	//not used anymore
#define STATE_TM_OF 0x10  //not used anymore
#define STATE_TIME 0x0f









/* --------------------------------- shared pin selection Macros below --------------------------------- */


// port A :

/* PA7 Macros for setting pin shared functionality*/

#define PA7_SETMODE_INPUT _pas17 = 0; \
	_pas16 = 0; \
	_pac7= 1


#define PA7_SETMODE_OUTPUT _pas17 = 0; \
	_pas16 = 0; \
	_pac7 = 0


#define PA7_SETMODE_AN2 _pas17 = 0;\
	_pas16 = 1
	







/* PA6 Macros for setting pin shared functionality*/

#define PA6_SETMODE_INPUT _pas15 = 0; \
	_pas14 = 0; \
	_pac6= 1


#define PA6_SETMODE_OUTPUT _pas15 = 0; \
	_pas14 = 0; \
	_pac6 = 0


#define PA6_SETMODE_SCK _pas15 = 0;\
	_pas14 = 1
	








/* PA5 Macros for setting pin shared functionality*/

#define PA5_SETMODE_INPUT _pas13 = 0; \
	_pas12 = 0; \
	_pac5 = 1


#define PA5_SETMODE_OUTPUT _pas13 = 0; \
	_pas12 = 0; \
	_pac5 = 0


#define PA5_SETMODE_SDO_TX _pas13 = 0;\
	_pas12 = 1
	
#define PA5_SETMODE_AN7 _pas13 = 1;\
	_pas12 = 0








/* PA4 Macros for setting pin shared functionality*/

#define PA4_SETMODE_INPUT _pas11 = 0; \
	_pas10 = 0; \
	_pac4 = 1


#define PA4_SETMODE_OUTPUT _pas11 = 0; \
	_pas10 = 0; \
	_pac4 = 0


#define PA4_SETMODE_CTPB _pas11 = 0;\
	_pas10 = 1
	
#define PA4_SETMODE_SDI_RX _pas11 = 1;\
	_pas10 = 0







/* PA3 Macros for setting pin shared functionality*/

#define PA3_SETMODE_INPUT _pas07 = 0; \
	_pas06 = 0; \
	_pac3 = 1


#define PA3_SETMODE_OUTPUT _pas07 = 0; \
	_pas06 = 0; \
	_pac3 = 0


#define PA3_SETMODE_AN3 _pas07 = 0;\
	_pas06 = 1
	
#define PA3_SETMODE_OPIN _pas07 = 1;\
	_pas06 = 0






/* PA2 Macros for setting pin shared functionality*/

#define PA2_SETMODE_INPUT _pas05 = 0; \
	_pas04 = 0; \
	_pac2 = 1


#define PA2_SETMODE_OUTPUT _pas05 = 0; \
	_pas04 = 0; \
	_pac2 = 0

#define PA2_SETMODE_PTP _pas05 = 0; \
	_pas04 = 1
	
#define PA2_SETMODE_SCS _pas05 = 1; \
	_pas04 = 0
	
#define PA2_SETMODE_INT0 _pas05 = 1; \
	_pas04 = 1




/* PA1 Macros for setting pin shared functionality*/

#define PA1_SETMODE_INPUT _pas03 = 0; \
	_pas02 = 0; \
	_pac1 = 1


#define PA1_SETMODE_OUTPUT _pas03 = 0; \
	_pas02 = 0; \
	_pac1 = 0
	
	
#define PA1_SETMODE_CTP _pas03 = 0;\
	_pas02 = 1	
						// SDI or SDA mode
#define PA1_SETMODE_AN5 _pas03 = 1;\
	_pas02 = 0
	
#define PA1_SETMODE_INT0 _pas03 = 1;\
	_pas02 = 1





/* PA0 Macros for setting pin shared functionality*/
#define PA0_SETMODE_INPUT _pas01 = 0; \
	_pas00 = 0; \
	_pac1 = 1


#define PA0_SETMODE_OUTPUT _pas01 = 0; \
	_pas00 = 0; \
	_pac1 = 0

#define PA0_SETMODE_PTP _pas01 = 0; \
	_pas00 = 1
	
#define PA0_SETMODE_AN6 _pas01 = 1; \
	_pas00 = 0
	








// port B :




/* PB3 Macros for setting pin shared functionality*/

#define PB3_SETMODE_INPUT _pbs07 = 0 \
	_pbs06 = 0; \
	_pbc3 = 1

#define PB3_SETMODE_OUTPUT _pbs07 = 0 \
	_pbs06 = 0; \
	_pbc3 = 0
	
	
#define PB3_SETMODE_AN11 _pbs07 = 0 \
	_pbs06 = 1 
	
	
#define PB3_SETMODE_PTCK _pbs07 = 1 \
	_pbs06 = 0







/* PB2 Macros for setting pin shared functionality*/

#define PB2_SETMODE_INPUT _pbs05 = 0 \
	_pbs04 = 0; \
	_pbc2 = 1

#define PB2_SETMODE_OUTPUT _pbs05 = 0 \
	_pbs04 = 0; \
	_pbc2 = 0
	
	
#define PB2_SETMODE_AN11 _pbs05 = 0 \
	_pbs04 = 1 
	
	
#define PB2_SETMODE_PTCK _pbs05 = 1 \
	_pbs04 = 0
	



/* PB1 Macros for setting pin shared functionality*/

#define PB1_SETMODE_INPUT _pbs03 = 0 \
	_pbs02 = 0; \
	_pbc1 = 1

#define PB1_SETMODE_OUTPUT _pbs03 = 0 \
	_pbs02 = 0; \
	_pbc1 = 0
	
	
#define PB1_SETMODE_AN8 _pbs03 = 0 \
	_pbs02 = 1 
	
	
#define PB1_SETMODE_INT1 _pbs03 = 1 \
	_pbs02 = 0
	




/* PB0 Macros for setting pin shared functionality*/

#define PB0_SETMODE_INPUT _pbs01 = 0 \
	_pbs00 = 0; \
	_pbc0 = 1

#define PB0_SETMODE_OUTPUT _pbs01 = 0 \
	_pbs00 = 0; \
	_pbc0 = 0
	
	
#define PB0_SETMODE_PTPB _pbs01 = 0 \
	_pbs00 = 1 
	
	
#define PB0_SETMODE_LVDIN _pbs01 = 1 \
	_pbs00 = 0
	




// port C :


/* PC1 Macros for setting pin shared functionality*/

#define PC1_SETMODE_INPUT _pcs03 = 0 \
	_pcs02 = 0; \
	_pcc0 = 1

#define PC1_SETMODE_OUTPUT _pcs03 = 0 \
	_pcs02 = 0; \
	_pcc0 = 0
	
	
#define PC1_SETMODE_PTPB _pcs03 = 0 \
	_pcs02 = 1 
	
	
#define PC1_SETMODE_AN9 _pcs03 = 1 \
	_pcs02 = 0
	


/* PC1 Macros for setting pin shared functionality*/

#define PC0_SETMODE_INPUT _pcs01 = 0 \
	_pcs00 = 0; \
	_pbc0 = 1

#define PC0_SETMODE_OUTPUT _pcs01 = 0 \
	_pcs00 = 0; \
	_pbc0 = 0
	
	
#define PC0_SETMODE_AN4 _pcs01 = 0 \
	_pcs00 = 1 
	
	
#define PC0_SETMODE_OPIP _pcs01 = 1 \
	_pcs00 = 0
	
#define PC0_SETMODE_CTCK _pcs01 = 1 \
	_pcs00 = 1


/* --------------------------------- ******************************** --------------------------------- */









#define initial(freq) \
	_wdtc = 0xA8; \
	if(freq == 12) \
		_hirc1 = 1; \
	else if(freq == 8) \
		_hirc0 = 1








#define ADC_ENABLEINTERRUPT \
 	if(!_emi) { \
 		_emi = 1; \
 	} \
 	_ade = 1




#endif