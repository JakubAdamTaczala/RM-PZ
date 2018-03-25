/*
 * spi_facade.h
 *
 *  Created on: 24.03.2018
 *      Author: Piotr Gogola
 */

#ifndef SPI_FACADE_C_
#define SPI_FACADE_C_

#include "defines.h"

uint8_t TM_SPI_Send(SPI_HandleTypeDef* SPIx, uint8_t data) {
	uint8_t received = 0;
	HAL_SPI_TransmitReceive(SPIx, &data, &received, 1, 10);
//	HAL_SPI_Receive(SPIx, &received, 1, 10);
	printf("TM_SPI_Send return : %d \n", received);
	return received;
}

void TM_SPI_ReadMulti(SPI_HandleTypeDef* SPIx, uint8_t *dataIn, uint8_t dummy,
		uint32_t count) {
	for (int i = 0; i < count; i++) {
		HAL_SPI_TransmitReceive(SPIx, &dummy, &dataIn[i], 1, 10);
//		HAL_SPI_Receive(SPIx, &dataIn[i], 1, 10);
		printf("M_SPI_ReadMulti return : %d \n", dataIn[i]);
	}
}

void TM_SPI_SendMulti(SPI_HandleTypeDef* SPIx, uint8_t* dataOut,
		uint8_t* dataIn, uint32_t count) {
	for (int i = 0; i < count; i++) {
		HAL_SPI_TransmitReceive(SPIx, &dataOut[i], &dataIn[i], 1, 10);
//		HAL_SPI_Receive(SPIx, &dataIn[i], 1, 10);
		printf("M_SPI_SendMulti return : %d \n", dataIn[i]);
	}
}

void TM_SPI_WriteMulti(SPI_HandleTypeDef* SPIx, uint8_t* dataOut,
		uint32_t count) {
	uint8_t receive = 0;
	for (int i = 0; i < count; i++) {
		HAL_SPI_TransmitReceive(SPIx, &dataOut[i], &receive, 1, 10);
		//		HAL_SPI_Receive(SPIx, &dataIn[i], 1, 10);
		printf("TM_SPI_WriteMulti return : %d \n", receive);
	}
}

#endif /* SPI_FACADE_C_ */
