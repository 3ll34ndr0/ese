#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include <stdio.h>
#include "pins.h"
#include "leds.h"
#include <stdlib.h> /* for malloc()/free() */


/* In this file we implement all abstract data types in order to
 * configure external interruptions and it's priorities for the
 * LPC1769
 */

/* External interrupt inputs
 * The LPC17xx include up to 46 edge sensitive interrupt inputs combined
 * with up to four level sensitive external interrupt inputs as selectable
 * pin functions. The external interrupt inputs can optionally be used to
 * wake up the processor from Power-down mode.
 *
 * Four external interrupt inputs configurable as edge/level sensitive.
 *  All pins on PORT0 and PORT2 can be used as edge sensitive
 *  interrupt sources.
 */

/* User Manual
 * Table 6: Pin summary
 Pin name:        EINT0
 Pin direction:   Input
 Pin description: External Interrupt Input 0 - An active low/high level or
                  falling/rising edge general purpose interrupt input.
                  This pin may be used to wake up the processor from
                  Sleep, Deep-sleep, or Power-down modes.
 Pin name:        EINT1
 Pin direction:   Input External
 Pin description: Interrupt Input 1 - See the EINT0 description above.

 Pin name:        EINT2
 Pin direction:   Input External
 Pin description: Interrupt Input 2 - See the EINT0 description above.

 Pin name:        EINT3
 Pin direction:   Input External
 Pin description: Interrupt Input 3 - See the EINT0 description above.




 * 3.3 Register description
 * Table 7.
Summary of system control registers
__External Interrupts__

Name 	| Description 						| Access | Reset val | Address
EXTINT  | External Interrupt Flag Register  |  R/W   | 0		 | 0x400F C140
EXTMODE | External Interrupt Mode register  |  R/W   | 0         | 0x400F C148
EXTPOLAR| External Interrupt Polarity Register R/W   | 0         | 0x400F C14C



__Register description__
The external interrupt function has four registers associated with it. The
EXTINT register contains the interrupt flags. The EXTMODE and EXTPOLAR
registers specify the level and edge sensitivity parameters.

Name       : EXTINT
Description: The External Interrupt Flag Register contains interrupt flags
             for EINT0, EINT1, EINT2 and EINT3.
Access     : R/W
Reset Value: 0x00
Address    : 0x400F C140

Name       : EXTMODE
Description: The External Interrupt Mode Register controls
             whether each pin is edge- or level-sensitive.
Access     : R/W
Address    : 0x400F C148

Name       : EXTPOLAR
Description: The External Interrupt Polarity Register controls R/W
             which level or edge on each pin will cause an interrupt.
Access     : R/W
Address    : 0x400F C14C

*/


/* Pin initialization function */
Pin * pinInit(uint8_t pinNumber){
   Pin * pin       = (Pin*)malloc(sizeof(Pin));
   setPinNumber(pin, pinNumber);

   return pin;
}

/* This function is intended to be used by the pinInit "method" */
void setPinNumber(Pin * pin, uint8_t number){
	pin->number = number;
}

void setPinAsInput(Pin * pin){
	pin->input = 1;
}
void setPinAsOutput(Pin * pin){
	pin->input     = 0;
	pin->interrupt = 0; /* Just in case ...*/
	   /* These are the available ports for the pin type: */
	   //int * puerto       = (int*)malloc(sizeof(uint8_t[8]));

	/* These addresses are hardcoded in the leds.h file, following
	 * the hardware definitions for the development board used. That
	 * way you don't need to change this file if you change the board.
	 */
	   if((pin->number==LED0)||(pin->number==LED1)||(pin->number==LED5)){
		   pin->address = LPC_GPIO0;/* todo: avoid this hardcoded address*/}
	   else if((pin->number==LED2)
			   ||(pin->number==LED3)
			   ||(pin->number==LED4)
			   ||(pin->number==LED6)
			   ||(pin->number==LED7)){
		   pin->address = LPC_GPIO2;/* todo: avoid this hardcoded address*/
	   }

	   (pin->address)->FIODIR |= (1 << pin->number);


}

void setRisingInterrupt(Pin * pin){
	pin->mode      = 1;
	pin->polarity  = 1;
	pin->interrupt = 1;
}

void setFallingInterrupt(Pin * pin){
	pin->mode      = 1;
	pin->polarity  = 0;
	pin->interrupt = 1;
}

void setLevelHighInterrupt(Pin * pin){
	pin->mode      = 0;
	pin->polarity  = 1;
	pin->interrupt = 1;
}

void setLevelLowInterrupt(Pin * pin){
	pin->mode      = 0;
	pin->polarity  = 0;
	pin->interrupt = 1;
}

void setPinValue(Pin * pin){
	pin->value = 1; /* Store the value in the pin data */
	(pin->address)->FIOSET |= 1 << (pin->number);

}
void clearPinValue(Pin * pin){
	pin->value = 0;/* Store the value in the pin data */
	(pin->address)->FIOCLR |= 1 << (pin->number);
}
uint8_t getPinValue(Pin * pin){
	return pin->value; /*todo: Should read the value directly from the port?*/
}

void setInterruptPriority(Pin * pin, uint8_t priority){
	pin->priority = priority;
}

/* This function will do the actual configuration of the pin.
 * Some other functions set, clear and read the value of the
 * Pin struct, but this fuction will read every data from the
 * struct and configure the board using the cmsis funtions*/
void configurePin(Pin * pin){
	if(pin->input == 1){
	/* Configurawq
	 * q
	 *  como entrada*/
       LPC_GPIO0->FIODIR &= ~(1 << (pin->number)); /*todo: hardcoded */
       printf ("Configurado pin %i como entrada\n", pin->number);
	}
    if(pin->interrupt == 1){
    	/*Habilitada interrupción externa por pin*/
    	LPC_GPIOINT->IO0IntEnR |= 1 << (pin->number);
    	printf ("Habilitada interrupción externa por pin %i\n", pin->number);
/* Una vez configurado, hay que habilitar: */
    	/* EINT3_IRQn es una de las 4 interrupciones externas*/
    	/* Esto está harcodeado */
    	/* TODO: Extender el código para que se puedan usar tantas interrupciones
    	 * como entradas que interrumpen sean definidas.
    	 */
        NVIC_ClearPendingIRQ(EINT3_IRQn);//Si estaba pendiente, limpio
        NVIC_SetPriority(EINT3_IRQn, 1); // Le dá prioridad 1 a la int externa 3
        NVIC_EnableIRQ(EINT3_IRQn);      //Habilita la interrupción externa 3
        printf ("Configurado el NVIC\n");
//        if(pin->priority == 0){
//            NVIC_ClearPendingIRQ(EINT0_IRQn);//Si estaba pendiente, limpio
//            NVIC_SetPriority(EINT0_IRQn, 0); // Le dá prioridad 1 a la int externa 3
//            NVIC_EnableIRQ(EINT0_IRQn);      //Habilita la interrupción externa 3
//            printf ("Configurada la interrupción externa "
//            		"%i\n",pin->priority);
//        }else if(pin->priority == 1){
//            NVIC_ClearPendingIRQ(EINT1_IRQn);//Si estaba pendiente, limpio
//            NVIC_SetPriority(EINT1_IRQn, 1); // Le dá prioridad 1 a la int externa 3
//            NVIC_EnableIRQ(EINT1_IRQn);      //Habilita la interrupción externa 3
//            printf ("Configurada la interrupción externa "
//            		"%i \n",pin->priority);
//        }else if(pin->priority == 2){
//            NVIC_ClearPendingIRQ(EINT2_IRQn);//Si estaba pendiente, limpio
//            NVIC_SetPriority(EINT2_IRQn, 2); // Le dá prioridad 1 a la int externa 3
//            NVIC_EnableIRQ(EINT2_IRQn);      //Habilita la interrupción externa 3
//            printf ("Configurada la interrupción externa "
//            		"%i\n",pin->priority);
//        }else if(pin->priority == 3){
//            NVIC_ClearPendingIRQ(EINT3_IRQn);//Si estaba pendiente, limpio
//            NVIC_SetPriority(EINT3_IRQn, 3); // Le dá prioridad 1 a la int externa 3
//            NVIC_EnableIRQ(EINT3_IRQn);      //Habilita la interrupción externa 3
//            printf ("Configurada la interrupción externa %i\n",pin->priority);
//        }
/* Lo siguiente lo hago ya en el setPinAsOutput() */
//        if(pin->input == 0){
//    	(pin->address)->FIODIR |= (1 << pin->number);
//    	printf ("Configurado %i como salida\n", pin->number);
//    	}
    } /* if interrupt */
}
