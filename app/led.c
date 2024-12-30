#include "led.h"
#include "stm32f10x.h"
#include "delay.h"  // ???????

#define GPIOC_CRH_ADDR    (volatile unsigned long *)(0x40011004UL)
#define GPIOC_ODR_ADDR    (volatile unsigned long *)(0x4001100CUL)

void led_init_use_regaddr(void)
{
    //step1: ????
    RCC_APB2PeriphClockCmd(GPIO_CLOCK, ENABLE);
    
    //step2: PC13???????,??50MHz
    *GPIOC_CRH_ADDR = *GPIOC_CRH_ADDR & (~(0xfu << 20u));
    /*
    *GPIOC_CRH_ADDR = xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
    0xfu << 20u = 0000 0000 1111 0000 0000 0000 0000 0000
    ~(0xfu << 20u)= 1111 1111 0000 1111 1111 1111 1111 1111
    *GPIOC_CRH_ADDR & (~(0xfu << 20u)):
    xxxx xxxx 0000 xxxx xxxx xxxx xxxx xxxx
    */
    
    *GPIOC_CRH_ADDR = *GPIOC_CRH_ADDR | (0x3u << 20u);
    /*
    *GPIOC_CRH_ADDR = xxxx xxxx 0000 xxxx xxxx xxxx xxxx xxxx
    (0x3u << 20u)= 0000 0000 0011 0000 0000 0000 0000 0000
    *GPIOC_CRH_ADDR | (0x3u << 20u):
    xxxx xxxx 0011 xxxx xxxx xxxx xxxx xxxx
    */
    
    //step3: PC13?????,??LED
    *GPIOC_ODR_ADDR = *GPIOC_ODR_ADDR | (0x1u << 13u);
}

void led_toggle_use_regaddr(uint16_t uiDelayNms)
{
    //step1: ?????
    *GPIOC_ODR_ADDR = *GPIOC_ODR_ADDR & (~(0x1u << 13u));
    Delay_ms(uiDelayNms);
    
    //step2: ?????
    *GPIOC_ODR_ADDR = *GPIOC_ODR_ADDR | (0x1u << 13u);
    Delay_ms(uiDelayNms);
}
