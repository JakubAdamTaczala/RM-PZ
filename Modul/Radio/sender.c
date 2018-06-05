//
//
//#include "tm_stm32f4_nrf24l01.h"
//
///* Receiver address */
//uint8_t TxAddress[] = { 0xE7, 0xE7, 0xE7, 0xE7, 0xE7 };
//
///* My address */
//uint8_t MyAddress[] = { 0x7E, 0x7E, 0x7E, 0x7E, 0x7E };
//
//uint8_t dataOut[32], dataIn[32];
//
//int sender(void) {
//	TM_NRF24L01_Transmit_Status_t transmissionStatus;
//	char str[40];
//
//	/* Initialize NRF24L01+ on channel 15 and 32bytes of payload */
//	/* By default 2Mbps data rate and 0dBm output power */
//	/* NRF24L01 goes to RX mode by default */
//	TM_NRF24L01_Init(15, 32);
//
//	/* Set 2MBps data rate and -18dBm output power */
//	TM_NRF24L01_SetRF(TM_NRF24L01_DataRate_2M, TM_NRF24L01_OutputPower_M18dBm);
//
//	/* Set my address, 5 bytes */
//	TM_NRF24L01_SetMyAddress(MyAddress);
//	/* Set TX address, 5 bytes */
//	TM_NRF24L01_SetTxAddress(TxAddress);
//
//	while (1) {
//		/* Every 2 seconds */
//		/* Fill data with something */
//		sprintf((char *) dataOut, "abcdefghijklmnoszxABCDEFCBDA");
//		/* Display on USART */
//		printf("pinging:\n");
//		/* Reset time, start counting microseconds */
//		/* Transmit data, goes automatically to TX mode */
//		TM_NRF24L01_Transmit(dataOut);
//
//		/* Turn on led to indicate sending */
//		/* Wait for data to be sent */
//		do {
//			transmissionStatus = TM_NRF24L01_GetTransmissionStatus();
//		} while (transmissionStatus == TM_NRF24L01_Transmit_Status_Sending);
//		/* Turn off led */
//		/* Go back to RX mode */
//		TM_NRF24L01_PowerUpRx();
//
//		/* Wait received data, wait max 100ms, if time is larger, then data were probably lost */
//		while (!TM_NRF24L01_DataReady() /*&& TM_DELAY_Time() < 100*/) {
//			printf("waiting\n");
//			HAL_Delay(10);
//		}
//		/* Get data from NRF2L01+ */
//		TM_NRF24L01_GetData(dataIn);
//
//		/* Check transmit status */
//		if (transmissionStatus == TM_NRF24L01_Transmit_Status_Ok) {
//			/* Transmit went OK */
//			printf(": OK\n");
//		} else if (transmissionStatus == TM_NRF24L01_Transmit_Status_Lost) {
//			/* Message was LOST */
//			printf(": LOST\n");
//		} else {
//			/* This should never happen */
//			printf(": SENDING\n");
//		}
//		HAL_Delay(1000);
//	}
//}
