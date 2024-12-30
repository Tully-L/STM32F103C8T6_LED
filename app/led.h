////prevent header file redefine
//#ifndef _LED_H
//#define _LED_H

//void led_P13C_init(void);

//#endif

#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

// ??GPIO??
#define GPIO_CLOCK    RCC_APB2Periph_GPIOC

// ????
void led_init_use_regaddr(void);
void led_toggle_use_regaddr(uint16_t uiDelayNms);

#endif
