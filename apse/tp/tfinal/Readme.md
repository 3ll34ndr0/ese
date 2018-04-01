## Ejemplo de tipos de datos externos.
### Aplicado al uso de interrupciones externas.


Definimos el tipo de dato Pin:

Variable | Tipo | Descripción
---|---|---
number | uint8_t | Número de pin
input  | uint8_t | 1: estrada, 0: salida
interrupt | uint8_t | 


El código que realiza ese tipo es el siguiente:
``` c

/* Defino una estructura que contenga las características
 * principales de un pin.
 */
typedef struct Pin{
   uint8_t number;
   uint8_t input;    /* 1 if input, 0 if output */
   uint8_t value;    /* Variable to store the value of the pin */
   uint8_t interrupt;/* If defined as input, seting this in 1  */
                     /* the pin will interrupt                 */
   LPC_GPIO_TypeDef * address;
   uint8_t mode; /* if 1, edge sensitive. If 0 level sensitive*/
   uint8_t polarity; /* if 1 active by high (or rising). If 0, active by low (or falling)*/
   uint8_t priority; /* From 1 to 4 */
                 }Pin;
```
