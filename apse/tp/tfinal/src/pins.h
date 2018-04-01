#ifndef __PINS_H_
#define __PINS_H_


#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif


///////////////////////////////////////////////////////////////////
#define SWITCH_3 1  /* Para el switch 3 ubicado en el puerto 0_1 */
#define SWITCH_2 18 /* Para el switch 2 que está conectado al    */
                    /* puerto 0_18                               */
///////////////////////////////////////////////////////////////////

/* Defino una estructura que contenga las características
 * principales de un pin.
 */
typedef struct Pin{
   uint8_t number;
   uint8_t input;    /* 1 if input, 0 if output */
   uint8_t value;    /* Variable to store the value of the pin */
   uint8_t interrupt;/* If defined as input, seting this in 1
                        the pin will interrupt*/
   LPC_GPIO_TypeDef * address;
   uint8_t mode; /* if 1, edge sensitive. If 0 level sensitive*/
   uint8_t polarity; /* if 1 active by high (or rising). If 0, active by low (or falling)*/
   uint8_t priority; /* From 1 to 4 */
}Pin;


/* Encabezados de las funciones auxiliares para el tipo de dato Pin */
/* todo: No todas están implementadas, pero el ejemplo funciona. */
Pin * pinInit(uint8_t pinNumber);
void setPinNumber(Pin * pin, uint8_t number);
void setPinAsInput(Pin * pin);
void setPinAsOutput(Pin * pin);
void setRisingInterrupt(Pin * pin);
void setFallingInterrupt(Pin * pin);
void setLevelHighInterrupt(Pin * pin);
void setLevelLowInterrupt(Pin * pin);
void setInterruptPriority(Pin * pin, uint8_t priority);
void readPin(Pin * pin); /*todo: No implementada */
void configurePin(Pin * pin);
void setPinValue(Pin * pin);
void clearPinValue(Pin * pin);
uint8_t getPinValue(Pin * pin);

#endif /* __PINS_H_ */
