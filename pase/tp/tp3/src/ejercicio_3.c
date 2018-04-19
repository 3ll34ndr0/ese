/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

/*****************************************************************************
 * Varible global para suspender/reanudar una tarea.
 ****************************************************************************/
	xTaskHandle  xHandle_task1;

/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);
	Board_LED_Set(3, false);
	Board_LED_Set(4, false);
}

/* Hilo de la Tarea 1*/
static void vHolaMundoTarea1(void *pvParameters) {
	bool LedState = false;
	while (1) {
        Board_LED_Set(0, LedState);
		LedState = (bool) !LedState;
		//DEBUGOUT("Tarea 1 - ");
		vTaskDelay(configTICK_RATE_HZ / 2);
	}
}

/* Hilo de la Tarea 2*/
static void vHolaMundoTarea2(void *pvParameters) {
	bool LedState = false;
	while (1) {
        Board_LED_Set(1, LedState);
		LedState = (bool) !LedState;
		//DEBUGOUT("Tarea 2 - ");
        vTaskDelay(configTICK_RATE_HZ / 2);
	}
}

/* Hilo de la Tarea 3*/
static void vHolaMundoTarea3(void *pvParameters) {
	bool LedState = false;
	while (1) {
        Board_LED_Set(2, LedState);
		LedState = (bool) !LedState;
		//DEBUGOUT("Tarea 3 - ");
        vTaskDelay(configTICK_RATE_HZ / 2);
	}
}


/* Hilo de la Tarea 4*/
static void vHolaMundoTarea4(void *pvParameters) {
	bool LedState = false;
	while (1) {
        Board_LED_Set(3, LedState);
		LedState = (bool) !LedState;
		//DEBUGOUT("Tarea 4 - ");
        vTaskDelay(configTICK_RATE_HZ / 2);
	}
}
/* Hilo de la Tarea 5*/
/* Cada 5 veces que se ejecuta, suspende/reanuda la tarea 1 */
static void vHolaMundoTarea5(void *pvParameters) {
	int tickCnt = 0;
	bool LedState = false;
	while (1) {
        tickCnt++;
        Board_LED_Set(4, LedState);
		LedState = (bool) !LedState;
		//DEBUGOUT("TAREA 5 ");
		if ((tickCnt%5)==0)
		   {
			if ((tickCnt%10)==0)
			   {
				//DEBUGOUT("- Reanudo la tarea 1 ");
				vTaskResume(xHandle_task1);
			   }
			else
			   {
				//DEBUGOUT("- Suspendo la tarea 1 ");
		        vTaskSuspend(xHandle_task1);
			   }
		    }
		//DEBUGOUT("\r\n");
		vTaskDelay(configTICK_RATE_HZ / 2);
	}
}

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();

	xTaskCreate(vHolaMundoTarea1, (signed char *) "vHolaMundoTarea1",
					configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 3UL),
					&xHandle_task1);

	xTaskCreate(vHolaMundoTarea2, (signed char *) "vHolaMundoTarea2",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 5UL),
				(xTaskHandle *) NULL);

	xTaskCreate(vHolaMundoTarea3, (signed char *) "vHolaMundoTarea3",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	xTaskCreate(vHolaMundoTarea4, (signed char *) "vHolaMundoTarea4",
					configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2UL),
					(xTaskHandle *) NULL);

	xTaskCreate(vHolaMundoTarea5, (signed char *) "vHolaMundoTarea5",
						configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 4UL),
						(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
