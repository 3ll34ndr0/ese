#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include <stdio.h>
#include "pins.h"
#include "leds.h"



/* Este ejemplo permite habilitar las interrupciones externas
 * de forma transparente para el usuario.
 * Las funciones hacen uso de la librería cmsis y se hace
 * cargo de la configuración de cada puerto entrada/salida
 * para configurar también de forma transparente.
 *
 * Los leds están configurados en el archivo leds.h,
 * para usarlos, simplemente usar:
 * LED0, LED1, ..., LED7.
 *
 * Lo mismo para los dos switch disponibles de la placa.
 * Usar directamente SWITCH_2 O SWITCH_3. (SWITCH_1 es el
 * hard reset del micro, por eso no lo usamos.)
 *
 */
int estado = 0;
Pin * led; /*todo: This is a toy example, remove global variables */
Pin * sw;
void EINT3_IRQHandler() {
/* todo: Trabajar sobre esta ISR para hacerla un poco más
 *       general */
if(estado == 0){
setPinValue(led);
estado = 1;
}
else{
estado = 0;
clearPinValue(led);
}
LPC_GPIOINT->IO0IntClr |= 1 << (sw->number);

/* Gets the IRQ number of the active interrupt */
uint32_t activeIRQn = NVIC_GetActive (EINT3_IRQn);
printf("Atendiendo la interrupción %u\n",activeIRQn);
}

//void GPIO_IRQ_HANDLER() {
//	printf("Entro la interrupción ...\n");
//
//	if(estado == 0){
//	LPC_GPIO2->FIOSET |= 1<<GPIO_LED2_PIN;
//	estado = 1;
//	}
//	else{
//	LPC_GPIO2->FIOCLR |= 1<<GPIO_LED2_PIN;
//	estado = 0;
//	}
//	LPC_GPIOINT->IO0IntClr |= 1 << GPIO_INTERRUP_PIN;
//	//NVIC_ClearPendingIRQ(EINT3_IRQn);//Si estaba pendiente, limpio
//
//	/* Gets the IRQ number of the active interrupt */
//	uint32_t activeIRQn = NVIC_GetActive (EINT2_IRQn);
//	printf("Atendiendo la interrupción %u\n",activeIRQn);
//
//}

int main(void) {

	/* Acá uso todos los setters y/o getters
	 * ("métodos") que modifican el tipo de
	 * dato abstracto Pin:
	 */


Pin * sw2 = pinInit(SWITCH_2);
setPinAsInput(sw2);
setRisingInterrupt(sw2); /* pin interrups on positive edge*/
setInterruptPriority(sw2, 3);
configurePin(sw2); /* Do the actual configuration */
sw = sw2; /* sw is a global var */

//Pin * sw2 = pinInit(SWITCH_2);
//setPinAsInput(sw2);
//setRisingInterrupt(sw2);
//setInterruptPriority(sw2, 2);
//configurePin(sw2);
//sw = sw2;


/* Ahora configuro un led como salida */
Pin * led2 = pinInit(LED6);
setPinAsOutput(led2); //led is a global variable
configurePin(led2); /* Ejecuta las configuraciónes que quedan pendientes*/
led = led2;
while(1);
return 0 ;
}
