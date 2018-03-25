//#include "tm_stm32f4_nrf24l01.h"
//#include "main.h"
//
//
//
///* My address */
//uint8_t MyAddress[] = { 0xE7, 0xE7, 0xE7, 0xE7, 0xE7 };
///* Receiver address */
//uint8_t TxAddress[] = { 0x7E, 0x7E, 0x7E, 0x7E, 0x7E };
//
//uint8_t dataOut[32], dataIn[32];
//
//int receiver(void) {
//	TM_NRF24L01_Transmit_Status_t transmissionStatus;
//
//	/* Initialize NRF24L01+ on channel 15 and 32bytes of payload */
//	/* By default 2Mbps data rate and 0dBm output power */
//	/* NRF24L01 goes to RX mode by default */
//	TM_NRF24L01_Init(15, 32);
//
//	/* Set RF settings, Data rate to 2Mbps, Output power to -18dBm */
//	TM_NRF24L01_SetRF(TM_NRF24L01_DataRate_2M, TM_NRF24L01_OutputPower_M18dBm);
//
//	/* Set my address, 5 bytes */
//	TM_NRF24L01_SetMyAddress(MyAddress);
//	/* Set TX address, 5 bytes */
//	TM_NRF24L01_SetTxAddress(TxAddress);
//
//	while (1) {
//		/* If data is ready on NRF24L01+ */
//		if (TM_NRF24L01_DataReady()) {
//			/* Get data from NRF24L01+ */
//			TM_NRF24L01_GetData(dataIn);
//			printf("data: %s", dataIn);
//			/* Send it back, automatically goes to TX mode */
//			TM_NRF24L01_Transmit(dataIn);
//
//			/* Wait for data to be sent */
//			do {
//				transmissionStatus = TM_NRF24L01_GetTransmissionStatus();
//			} while (transmissionStatus == TM_NRF24L01_Transmit_Status_Sending);
//
//			/* Go back to RX Mode */
//			TM_NRF24L01_PowerUpRx();
//		}
//	}
//
//}
