/*
 * global_def.c
 *
 *  Created on: 25.03.2018
 *      Author: Piotr Gogola
 */

#include "global_def.h"
#include <stm32f0xx_hal.h>
#include "main.h"

#if ENABLE_DEBUG
extern UART_HandleTypeDef huart1;

//int _write(int file, char * ptr, int len) {
//	HAL_UART_Transmit(&huart1, (uint8_t*) ptr, len, 50);
//	return len;
//}

int _write(int file, char * ptr, int len) {
	HAL_UART_Transmit(&huart1, (uint8_t*) ptr, len, 50);
	return len;
}

#endif

uint8_t RADIO_INT = 0;
uint8_t ETH_INT = 0;
uint8_t buffer[32];


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (ETH_INT_Pin == GPIO_Pin) {
//		ethernetif_input(&networkInterface);
		ETH_INT ++;
	}
}
