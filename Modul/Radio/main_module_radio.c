/*
 * main_module_radio.c
 *
 *  Created on: 29.03.2018
 *      Author: Piotr Gogola
 */

#include "main_module_radio.h"

/* My address */
uint8_t MainModuleAddress[] = { 0xE7, 0xE7, 0xE7, 0xE7, 0xE7 };
/* Receiver address */
uint8_t HandAddress[] = { 0x7E, 0x7E, 0x7E, 0x7E, 0x7E };

void mainModuleRadioInit() {
	TM_NRF24L01_Init(15, 32);

	/* Set RF settings, Data rate to 2Mbps, Output power to -18dBm */
	TM_NRF24L01_SetRF(TM_NRF24L01_DataRate_2M, TM_NRF24L01_OutputPower_M18dBm);

	/* Set my address, 5 bytes */
	TM_NRF24L01_SetMyAddress(MainModuleAddress);
	/* Set TX address, 5 bytes */
	TM_NRF24L01_SetTxAddress(HandAddress);
}
