#include "bsp/bsp.h"


void APP_1ms(void);

uint8_t led = 1;
uint8_t brightness = 0;
uint16_t counter = 80;



int main(void) {


	BSP_Init();

	while(1)
	{

		if(!counter)
		{
			Leds_OFF();
			counter = 80;

			if(Get_SW_State())
			{
				if(led>4)
					led=1;
				else
					led++;
				if(brightness <= 100)
					brightness++;
			}

			else
			{
				if(led<1)
					led=4;
				else
					led--;
				if(brightness > 0)
					brightness--;
			}
		}


		switch (led)
		{
			case 1:
			led_setBright(LED_AZUL, brightness);
			break;

			case 2:
			led_setBright(LED_ROJO, brightness);
			break;

			case 3:
			led_setBright(LED_NARANJA, brightness);
			break;

			case 4:
			led_setBright(LED_VERDE, brightness);
			break;
		}
	}

}

void APP_1ms(void) {

	if(counter){
		counter--;
	}

}
