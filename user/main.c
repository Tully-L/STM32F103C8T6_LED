//#include "stm32f10x.h"
//#include "led.h"

//int main()
//{
//led_P13C_init();
//while(1)
//{
//GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
//for(uint32_t i = 0; i < 500000; i++);
//GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
//for(uint32_t i = 0; i < 500000; i++);
//}
//}

#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
    // ???????
    SystemInit();
    
    // ???????
    Delay_Init();
    
    // ???LED
    led_init_use_regaddr();
    
    while(1)
    {
        // LED??,??500ms
        led_toggle_use_regaddr(500);
			Delay_ms(1000);
			led_toggle_use_regaddr(500);
    }
}
