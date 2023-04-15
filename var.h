#ifndef __VAR_H
#define __VAR_H

#define SIZE_BUFFER     30
#define FRE_TIMER1      1000000
const float epsilon      = 0.0001;
//const unsigned int  R2   = 576; // don vi kOhm
//const unsigned int  R4   = 50;  // don vi kOhm
/*const float         C55  = 0.000000018;
const float         a    = 0.0000000125;
const float         b    = 0.00000136;
const float         c    = 0.000219;
const float         d    = 0.9;*/
float d;  
unsigned long int over;
unsigned long int buffer_frequency[SIZE_BUFFER];
unsigned int cur_icr1;
unsigned char index;
float frequency;
unsigned char start_convert=0;
#endif 