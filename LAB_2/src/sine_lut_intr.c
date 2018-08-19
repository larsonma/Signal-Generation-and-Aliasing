// sine_lut_intr.c

#include "audio.h"
 
void I2S_HANDLER(void) {    /****** I2S Interruption Handler*****/
	const int LOOP_SIZE = 8;
	const int16_t sine_table[LOOP_SIZE] = {10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000};
	static int sine_ptr = 0;

	int16_t audio_chR=0;    
  int16_t audio_chL=0;

	audio_IN = i2s_rx();	
  audio_chL = (audio_IN & 0x0000FFFF);       
  audio_chR = ((audio_IN >>16)& 0x0000FFFF); 

  audio_chL = sine_table[sine_ptr];
	audio_chR = sine_table[sine_ptr];
  sine_ptr = (sine_ptr+1) % LOOP_SIZE;
	
  audio_OUT = ((audio_chR<<16) & 0xFFFF0000) | (audio_chL & 0x0000FFFF);	
  i2s_tx(audio_OUT);
}

int main(void) {
  audio_init (hz8000, line_in, intr, I2S_HANDLER); 
  while(1){}
}
