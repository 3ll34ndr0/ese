## Ejemplo de tipos de datos abstractos.
### Aplicado al uso de interrupciones externas.


En la cabecera [pins.h](https://github.com/3ll34ndr0/ese/blob/master/apse/tp/tfinal/src/pins.h) definimos el tipo de dato **Pin**:

Variable | Tipo | Descripción
---|:---:|---
number | `uint8_t` | Número de pin (`LED0`, `LED1`,..., `LED7`, `SWITCH_2`, `SWITCH_3`) 
input  | `uint8_t` | 1: estrada, 0: salida
interrupt | uint8_t` | 1: interrumpe si es entrada 
mode   | `uint8_t` | 1: Sensible por flanco 0: Sensible por nivel
polarity | `uint8_t` | 1: Flanco de subida (por alto si `mode==0`) 0: Flanco de bajada (bajo)
priority | `uint8_t` | 0-32: Prioridad que tendrá la interrupción
address | `LPC_GPIO_TypeDef *` | Estructura que contiene todos los registros de configuración del pin.

#### El código para implementar el tipo **Pin** es el siguiente:
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

Las los *getters* y *setters* de este tipo de dato abstracto son los siguientes:

```c
/* Encabezados de las funciones auxiliares para el tipo de dato Pin */
/* todo: No todas están implementadas, pero el ejemplo funciona. */
Pin * pinInit(uint8_t pinNumber);
void setPinNumber(Pin * pin, uint8_t number);
void setPinAsInput(Pin * pin);
void setPinAsOutput(Pin * pin);
void setPinValue(Pin * pin);
void clearPinValue(Pin * pin);
uint8_t getPinValue(Pin * pin);
void setRisingInterrupt(Pin * pin);
void setFallingInterrupt(Pin * pin);
void setLevelHighInterrupt(Pin * pin);
void setLevelLowInterrupt(Pin * pin);
void setInterruptPriority(Pin * pin, uint8_t priority);
void readPin(Pin * pin); /*todo: No implementada */
void configurePin(Pin * pin);

```

## Cómo usar:
En el `main` podemos definir un **button switch** de los 2 disponibles en la placa para que generen una interrupción:

```c
Pin * sw2 = pinInit(SWITCH_2); /* El otro es SWITCH_3 */
setPinAsInput(sw2);
setRisingInterrupt(sw2); /* pin interrups on positive edge*/
setInterruptPriority(sw2, 3);
configurePin(sw2); /* Do the actual configuration */
```

También podemos definir **8 leds distintos** (`LED0`, ..., `LED7`) de forma transparente para el usuario, por ejemplo con las siguietes funciones:
```c
/* Ahora configuro un led como salida */
Pin * led2 = pinInit(LED6);
setPinAsOutput(led2); 
configurePin(led2); /* Ejecuta las configuraciónes que quedan pendientes*/
```

Para atender la interrupción que genera `SWITCH_2` o `SWITCH_3` hemos implementado una sola ISR externa (en `void EINT3_IRQHandler() {`) y allí por ejemplo encendemos y apagamos un led definido anteriormente en el `main`:

Encendemos o apagamos simplemente con `setPinValue(led)` y `clearPinValue(led)`, siendo la variable `led` un puntero al **tipo de dato abstracto** `Pin`.

El ejemplo completo de uso de este tipo de dato abstracto se puede ver en [extIntTF.c](src/extIntTF.c)
