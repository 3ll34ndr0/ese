/*
===============================================================================
 Name        : eintTF.cpp
 Author      : Leandro Marsó
 Version     :
 Copyright   :
 Description : Versión en c++ de extIntTF.c
===============================================================================
*/
#include <iostream>
#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
using namespace std;

/* Find a better place to define these... */
/* These values are directly related to the
 * cortex_base_board_R02 we are using in the
 * course. */

/* Esta definición de pines y puertos está directamente
 * asociada a la placa de desarrollo que estamos
 * usando: Cortex_base_board_R02.
 * CUalquier duda, consultar el esquemático de la
 * placa, en conjunto con el manual del lpc1769,
 * de ser necesario */

#define LPC_PORT_0 LPC_GPIO0
#define LPC_PORT_2 LPC_GPIO2

/* Número de pines asociado a cada LED
 *
 *      Nombre Número    Label en el esquemático */
#define LED0   17      //P0
#define LED1   22      //P0_22 /*todo: Chequear pero parece que no funciona */
#define LED2   2       //P2_-2
#define LED3   3       //P2_3
#define LED4   4       //P2_4
#define LED5   4       //P0_4
#define LED6   11      //P2_11
#define LED7   12      //P2_12

/* Con el Puerto + el Número de Pin, se puede acceder  *
 * directamente a configurar, leer, escribir el mismo.
 * Se supone que el/la usuario/a final no necesita saber esa
 * info para poder usar los pines, de eso se hace cargo
 * los método que configuran el pin como entrada/salida.
 *
 */

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

class Pin {
private:
   uint8_t number;
   bool input;    /* True if input, false if output */
   uint8_t value;    /* Variable to store the value of the pin */
   bool interrupt;/* If defined as input, seting this to true,
                     the pin will interrupt*/
   LPC_GPIO_TypeDef * address;
   uint8_t mode; /* if 1, edge sensitive. If 0 level sensitive*/
   uint8_t polarity; /* if 1 active by high (or rising). If 0, active by low (or falling)*/
   uint8_t priority; /* From 1 to 4 */
   bool    dumb; /* If I need to define a dumb pin */
                 /* True if dumb, False if is real */
   void activateInterruption() {
	   if(!(priority>=0 && priority <5)){priority=1;}// default priority
       LPC_GPIOINT->IO0IntEnR |= 1 << number; /*todo: hardcoded address */
		                                      /*todo: Implementar mode y polarity */
	   /* todo: agregar la posibilidad que puedan interrumpir más de una entrada al mismo timpo)*/
	   NVIC_ClearPendingIRQ(EINT3_IRQn);   //Si estaba pendiente, limpio
	   NVIC_SetPriority(EINT3_IRQn, priority); // Le dá prioridad indicada
	   NVIC_EnableIRQ(EINT3_IRQn);         //Habilita la interrupción externa 3
                                           }

public:
   void setAsInput() {input = true;
   LPC_PORT_0->FIODIR &= ~(1 << (pin->number));
//   printf ("Configurado pin %i como entrada\n", pin->number);
   }
   void setRisingInterrupt() {
	   /* Guarda un estado interno */
      mode      = 1;
      polarity  = 1;
      interrupt = true;
      /*Habilito interrupción externa por pin con la prioridad indicada*/
      activateInterruption();

   }

   void setAsOutput() {input = false;
      /* "Configure" the Pin with the */
      if((number==LED0)||(number==LED1)||(number==LED5)){
         address = LPC_PORT_0;}
	  else if((number==LED2)
		    ||(number==LED3)
		    ||(number==LED4)
		    ||(number==LED6)
		    ||(number==LED7)){
         address = LPC_PORT_2;}

	  address->FIODIR |= 1 << number; /* This is the actual configuration of the port */
                              }


   void set() {value = 1;}
   void clear() {value = 0;}
   uint8_t read() {return value;}
   Pin(){ dumb=true;
   }
   Pin(uint8_t pinNumber){number = pinNumber;}
};








int main(void) {

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
        cout << i;
    }
    return 0 ;

}

