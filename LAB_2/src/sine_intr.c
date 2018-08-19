// sine_intr.c 

#include "audio.h"

void I2S_HANDLER(void) {  /****** I2S Interruption Handler *****/
  const int sampling_freq = 8000;
  const float32_t frequency = 7000.0;
  const float32_t amplitude = 2000.0;
  const float32_t theta_increment = 2*PI*frequency/sampling_freq;
  static float32_t theta = 0.0f;
  int16_t audio_chR=0;    
  int16_t audio_chL=0;
	
  audio_IN = i2s_rx();	
  audio_chL = (audio_IN & 0x0000FFFF);       
  audio_chR = ((audio_IN >>16)& 0x0000FFFF); 

  theta += theta_increment;
  if (theta > 2*PI) theta -= 2*PI;
  audio_chL = (int16_t)(amplitude*sin(theta));
	audio_chR = audio_chL;
	
  audio_OUT = ((audio_chR<<16) & 0xFFFF0000) | (audio_chL & 0x0000FFFF);	
  i2s_tx(audio_OUT);
}

int main(void) {
  audio_init(hz8000, line_in, intr, I2S_HANDLER); 
  while(1){}
}

