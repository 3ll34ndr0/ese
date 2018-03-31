/*
 * leds.c
 *
 *  Created on: 30 de mar. de 2018
 *      Author: leandro marsó
 */
#include "leds.h"
#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

int * loadLedsPortNumber(void){
int port[8] = {(1<< LED0),
		(1<< LED1),
		(1<< LED2),
		(1<< LED3),
		(1<< LED4),
		(1<< LED5),
		(1<< LED6),
		(1<< LED7)};
return port;
}

LPC_GPIO_TypeDef * loadLedsAddress(void){
LPC_GPIO_TypeDef      *direccion[8] = {LPC_GPIO0,
		LPC_GPIO0,
		LPC_GPIO2,
		LPC_GPIO2,
		LPC_GPIO2,
		LPC_GPIO0,
		LPC_GPIO2,
		LPC_GPIO2};
return direccion;
}
