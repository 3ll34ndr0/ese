/*
 * leds.h
 *
 *  Created on: 30 de mar. de 2018
 *      Author: lean
 */

#ifndef LEDS_H_
#define LEDS_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

/* Esta definición de pines está directamente
 * asociada a la placa de desarrollo que estamos
 * usando: Cortex_base_board_R02.
 * CUalquier duda, consultar el esquemático de la
 * placa, en conjunto con el manual del lpc1769,
 * de ser necesario */

//#define LED2pIN 17 //LED2 => Pin 22
#define LED0 17 //P0
#define LED1 22  //P0_22 //No funciona
#define LED2 2   //P2_-2
#define LED3 3 //P2_3
#define LED4 4 //P2_4
#define LED5 4 //P0_4
#define LED6 11 //P2_11
#define LED7 12 //P2_12


/* Estas definiciones son necesarias para
 * hacer más abstracto el archivo
 * pins.h, así no depende de la
 * placa de desarrollo.
 */
#define LEDADDR0 LPC_GPIO0
#define LEDADDR1 LPC_GPIO0
#define LEDADDR2 LPC_GPIO2
#define LEDADDR3 LPC_GPIO2
#define LEDADDR4 LPC_GPIO2
#define LEDADDR5 LPC_GPIO0
#define LEDADDR6 LPC_GPIO2
#define LEDADDR7 LPC_GPIO2
int * loadLedsPortNumber(void);
LPC_GPIO_TypeDef * loadLedsAddress(void); /* Maybe I should choose a friendly
											 alias for this type of data.*/


#endif /* LEDS_H_ */
