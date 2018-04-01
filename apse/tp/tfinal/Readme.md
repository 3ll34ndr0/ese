## Ejemplo de tipos de datos abstractos.
### Aplicado al uso de interrupciones externas.


En la cabecera [pins.h](https://github.com/3ll34ndr0/ese/blob/master/apse/tp/tfinal/src/pins.h) definimos el tipo de dato Pin:

Variable | Tipo | Descripción
---|---|---
number | `uint8_t` | Número de pin (`LED0`, `LED1`,..., `LED7`, `SWITCH_2`, `SWITCH_3`) 
input  | `uint8_t` | 1: estrada, 0: salida
interrupt | uint8_t` | 1: interrumpe si es entrada 
mode   | `uint8_t` | 1: Sensible por flanco 0: Sensible por nivel
polarity | `uint8_t` | 1: Flanco de subida (por alto si `mode==0`) 0: Flanco de bajada (bajo)
priority | `uint8_t` | 0-32: Prioridad que tendrá la interrupción
address | `LPC_GPIO_TypeDef *` | Estructura que contiene todos los registros de configuración del pin.

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
