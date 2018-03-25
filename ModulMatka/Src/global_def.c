/*
 * global_def.c
 *
 *  Created on: 25.03.2018
 *      Author: Piotr Gogola
 */

#include "global_def.h"
#include <stm32f4xx_hal.h>
#include "main.h"

#if ENABLE_DEBUG
extern UART_HandleTypeDef huart2;

int _write(int file, char * ptr, int len) {
	HAL_UART_Transmit(&huart2, (uint8_t*) ptr, len, 50);
	return len;
}
#endif
//
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	ethernetif_input(&networkInterface);
//}
