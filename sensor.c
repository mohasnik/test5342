#include "sensor.h"

DEFINE_ISR(AdcDataCollect, 0x0c);


Sensor sensor;

uint32_t sensor_weight_window[WINDOW];
uint8_t state = 0;



/*

//initializing A/D converter :
void ADC_Init(void)
{
 	//PWRC register configuration :
 	_pwrc = 0x83;
 	
 	//PGAC0 register configuration :
 	_vgs1 = 0;
 	_vgs0 = 0;
 	
 	_ags1 = 0;
 	_ags0 = 0;
 	
 	_pgs2 = 0;
 	_pgs1 = 1;
 	_pgs0 = 1;
 	
 	//PGAC1 register configuration :
 	
 	_pgac1 = 0x00;
 	
 	_vrefs = 0;
 	
	//ADCS register configuration :
 	//Setting fMCLK to evaluated indirectly from f_sys: 
 	_adcs = 0x02;
	
	_vrbufn = 0;
	_vrbufp = 0;
	
 	
	_ador2 = 0;
	_ador1 = 0;
	_ador0 = 0;
	
	
	_flms2 = 0;
	_flms1 = 1;
	_flms0 = 0;
	

 	//PGACS register configuration :
 	_pgacs = 0x00;
 	//-------
 	

 	_adoff = 0;
 	_adslp = 0;
 	
 	_adrst = 1;
 	
 	
 	_adrst = 0;
 	
 	_eoc = 0;
 	
 }
*/


void ADC_Init(void)
{
	
	_pwrc = 0x83;
	
	_vgs1 = 0;
 	_vgs0 = 0;
 	
 	
 	_ags1 = 0;
 	_ags0 = 0;
 	
 	
 	_pgs2 = 0;
 	_pgs1 = 1;
 	_pgs0 = 1;
 	
 	_pgac1 = 0x00;
 	
 	_vrefs = 0;
 	
 	_adcs = 0x02;
 	
 	
 	_vrbufn = 0;
	_vrbufp = 0; 
 	
 	_ador2 = 0;
	_ador1 = 0;
	_ador0 = 0;
 	
 	_flms2 = 0;
	_flms1 = 1;
	_flms0 = 0;
	
	_pgacs = 0x10;
	
	_adoff = 0;
 	_adslp = 0;
 	
 	_adrst = 1;
 	
 	
 	_adrst = 0;
 	
 	_eoc = 0;
 	
 	
 	
} 
 


void AdcDataCollect(void)
{
	 _adf = 0;
 	_emi = 1;

	if(_eoc)
	{	
	 	_adcdl = 1;
	    
	    _eoc = 0; 
	    sensor.new_weight = ((uint32_t)_adrl)<<8;
	    sensor.new_weight |= (((uint32_t)_adrh<<24) | ((uint32_t)_adrm<<16));
	    sensor.new_weight>>=8;
	    
	    _adcdl = 0;
	        
	    if(state & STATE_TIME)
	    {
	    	if(state & STATE_ON_RISING)
	    	{
	    		sensor.old_weight = - (sensor.old_weight - sensor.new_weight);
	    		
	    	}
	    	else
	    	{
	    		sensor.old_weight = sensor.old_weight - sensor.new_weight;
	    	}		
	    	
	    }
	    else {
	    	
	    	if(state & STATE_ON_RISING)
	    	{
	    		sensor.old_weight =  sensor.new_weight - sensor.old_weight;
	    	}
	    	else {
	    		sensor.old_weight = - (sensor.new_weight - sensor.old_weight);
	    	}
	    		
	    }		 
	  	
	  	state |= STATE_ADC_FLAG_RAISED;
	  	
	  	_eoc = 0;
	  	
	} 
	
	if((state & STATE_TIME) == 0)
	{
		state ^= STATE_ON_RISING;	
	}
	state++;
	if((state & STATE_TIME) == 2)
	{
		_inx0 = ~_inx0;
		_inx1 = ~_inx1;
		state &= ~STATE_TIME;
	}
	
	
	
}



void Sensor_Weight_Filter(void)
{
	sensor.weight_sum= 0;
	sensor.weight_max= sensor_weight_window[0];
	sensor.weight_min= sensor_weight_window[0];
	
	uint8_t i = 0;
	for(i; i<WINDOW; i++) {
		if(sensor_weight_window[i] > sensor.weight_max) sensor.weight_max = sensor_weight_window[i];
		if(sensor_weight_window[i] < sensor.weight_min) sensor.weight_min = sensor_weight_window[i];
		sensor.weight_sum += sensor_weight_window[i]; 
 	}
 	sensor.weight_sum -= sensor.weight_max;
 	sensor.weight_sum -= sensor.weight_min;
 	sensor.avg_weight = sensor.weight_sum >> 2;
}