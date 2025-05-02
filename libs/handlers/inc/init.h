#include "chip.h"
#include "Sounds.h"

#ifndef INIT_H
#define INIT_H 

#define ENC_A_CLK_PIN 35 
#define ENC_B_DT_PIN 37  
#define BOTON_SW_PIN 33 

void Timer1_Init(void);
void Encoder_Init(void);

#endif /* #ifndef _INIT_H_ */
