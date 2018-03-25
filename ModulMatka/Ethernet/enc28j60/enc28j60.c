/**
 * \file enc28j60.c
 *	Driver functions implementations
 *  Created on: 08.03.2018
 *      Author: Piotr Gogola
 */

#include "enc28j60.h"

static Enc28j60SPI enc28j60spi;

void getMACAddress(uint8_t* macAddress) {
	macAddress[0] = MACADDRESS1;
	macAddress[1] = MACADDRESS2;
	macAddress[2] = MACADDRESS3;
	macAddress[3] = MACADDRESS4;
	macAddress[4] = MACADDRESS5;
	macAddress[5] = MACADDRESS6;
}

void enc28j60Init(SPI_HandleTypeDef* hspi, GPIO_TypeDef* chipSelectPort,
		uint16_t chipSelectPin) {
	enc28j60spi.spi = hspi;
	enc28j60spi.CSPort = chipSelectPort;
	enc28j60spi.CSPin = chipSelectPin;
	enc28j60spi.currentBank = 1;
	enc28j60SetBank(BANK0);

	enc28j60ChipSelectHigh();
	HAL_Delay(100);

	//soft reset
	enc28j60WriteOp(ENC28J60_SOFT_RESET, ENC28J60_SOFT_RESET,
	ENC28J60_SOFT_RESET);

	// pointer to first received package
	enc28j60spi.nextPacketPointer = RXSTART_INIT;

	// Receive buffor start
	enc28j60CtrlRegWrite(ERXSTL, RXSTART_INIT & 0xFF);
	enc28j60CtrlRegWrite(ERXSTH, RXSTART_INIT >> 8);
	// Receive buffor end
	enc28j60CtrlRegWrite(ERXNDL, RXSTOP_INIT & 0xFF);
	enc28j60CtrlRegWrite(ERXNDH, RXSTOP_INIT >> 8);
	// Receive pointer address
	enc28j60CtrlRegWrite(ERXWRPTL, RXSTART_INIT & 0xFF);
	enc28j60CtrlRegWrite(ERXWRPTH, RXSTART_INIT >> 8);

	enc28j60CtrlRegWrite(ERXRDPTL, RXSTART_INIT & 0xFF);
	enc28j60CtrlRegWrite(ERXRDPTH, RXSTART_INIT >> 8);

	// TX start
	enc28j60CtrlRegWrite(ETXSTL, TXSTART_INIT & 0xFF);
	enc28j60CtrlRegWrite(ETXSTH, TXSTART_INIT >> 8);
	// TX end
	enc28j60CtrlRegWrite(ETXNDL, TXSTOP_INIT & 0xFF);
	enc28j60CtrlRegWrite(ETXNDH, TXSTOP_INIT >> 8);

	//disable all filters
	enc28j60CtrlRegWrite(ERXFCON, 0);
//	enc28j60CtrlRegWrite(ERXFCON, ERXFCON_UCEN | ERXFCON_CRCEN | ERXFCON_PMEN);
//	enc28j60CtrlRegWrite(EPMM0, 0x3f);
//	enc28j60CtrlRegWrite(EPMM1, 0x30);
//	enc28j60CtrlRegWrite(EPMCSL, 0xf9);
//	enc28j60CtrlRegWrite(EPMCSH, 0xf7);

	// enable MAC receive
	enc28j60CtrlRegWrite(MACON1, MACON1_MARXEN | MACON1_TXPAUS | MACON1_RXPAUS);
	// enable automatic padding to 60bytes and CRC operations
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, MACON3,
	MACON3_PADCFG0 | MACON3_TXCRCEN | MACON3_FRMLNEN);
	// set inter-frame gap (non-back-to-back)
	enc28j60CtrlRegWrite(MAIPGL, 0x12);
	enc28j60CtrlRegWrite(MAIPGH, 0x0C);
	// set inter-frame gap (back-to-back)
	enc28j60CtrlRegWrite(MABBIPG, 0x12);
	// Set the maximum packet size which the controller will accept
	// Do not send packets longer than MAX_FRAMELEN:
	enc28j60CtrlRegWrite(MAMXFLL, MAX_FRAMELEN & 0xFF);
	enc28j60CtrlRegWrite(MAMXFLH, MAX_FRAMELEN >> 8);
	// do bank 3 stuff
	// write MAC address
	// NOTE: MAC address in ENC28J60 is byte-backward
	enc28j60CtrlRegWrite(MAADR6, MACADDRESS1);
	enc28j60CtrlRegWrite(MAADR5, MACADDRESS2);
	enc28j60CtrlRegWrite(MAADR4, MACADDRESS3);
	enc28j60CtrlRegWrite(MAADR3, MACADDRESS4);
	enc28j60CtrlRegWrite(MAADR2, MACADDRESS5);
	enc28j60CtrlRegWrite(MAADR1, MACADDRESS6);

	// no loopback of transmitted frames
	enc28j60PHYWrite(PHCON2, PHCON2_HDLDIS);
	// switch to bank 0
	enc28j60SetBank(ECON1);
	// enable interrutps when packed received
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE | EIE_PKTIE);
	//clear INT bit coubled with ~INT pin
	// enable packet reception
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);

}

void enc28j60ChipSelectHigh() {
	HAL_GPIO_WritePin(enc28j60spi.CSPort, enc28j60spi.CSPin, GPIO_PIN_SET);
}

void enc28j60ChipSelectLow() {
	HAL_GPIO_WritePin(enc28j60spi.CSPort, enc28j60spi.CSPin, GPIO_PIN_RESET);
}

uint8_t enc28j60ReceiveByte() {
	uint8_t receive = 0;
	HAL_SPI_Receive(enc28j60spi.spi, &receive, 1, 10);
	return receive;
}

void enc28j60TransmitByte(uint8_t data) {
	HAL_SPI_Transmit(enc28j60spi.spi, &data, 1, 10);
}

void enc28j60WriteOp(uint8_t opcode, uint8_t address, uint8_t data) {
	enc28j60ChipSelectLow();
	uint8_t byte0 = opcode | (address & ADDR_MASK);
	enc28j60TransmitByte(byte0);
	enc28j60TransmitByte(data);
	enc28j60ChipSelectHigh();
}

uint8_t enc28j60ReadOp(uint8_t opcode, uint8_t address) {
	enc28j60ChipSelectLow();
	uint8_t byte0 = opcode | (address & ADDR_MASK);
	enc28j60TransmitByte(byte0);

	if (address & SPRD_MASK) {
		enc28j60ReceiveByte();
	}

	uint8_t receive = enc28j60ReceiveByte();
	enc28j60ChipSelectHigh();
	return receive;
}

void enc28j60SetBank(uint8_t address) {
	address = ((address & BANK_MASK) >> 5);
	if (address != enc28j60spi.currentBank) {
		enc28j60spi.currentBank = address;
		enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1,
				(ECON1_BSEL0 | ECON1_BSEL1));
		enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, address);
	}
}

void enc28j60CtrlRegWrite(uint8_t address, uint8_t data) {
	enc28j60SetBank(address);
	enc28j60WriteOp(ENC28J60_WRITE_CTRL_REG, address, data);
}

uint8_t enc28j60CtrlRegRead(uint8_t address) {
	enc28j60SetBank(address);
	return enc28j60ReadOp(ENC28J60_READ_CTRL_REG, address);
}

void enc28j60WriteBuffer(uint8_t* data, uint16_t len) {
	enc28j60ChipSelectLow();
	enc28j60TransmitByte(ENC28J60_WRITE_BUF_MEM);
	while (len > 0) {
		len--;
		enc28j60TransmitByte(*data);
		data++;
	}
	enc28j60ChipSelectHigh();
}

void enc28j60ReadBuffer(uint8_t* data, uint16_t len) {
	enc28j60ChipSelectLow();
	enc28j60TransmitByte(ENC28J60_READ_BUF_MEM);
	while (len > 0) {
		len--;
		(*data) = enc28j60ReceiveByte();
		data++;
	}
	enc28j60ChipSelectHigh();
}

void enc28j60PHYWrite(uint8_t address, uint16_t data) {
	enc28j60CtrlRegWrite(MIREGADR, address);
	enc28j60CtrlRegWrite(MIWRL, (0xFF & data));
	enc28j60CtrlRegWrite(MIWRH, (data >> 8));
	while (enc28j60ReadOp(ENC28J60_READ_CTRL_REG, MISTAT) & MISTAT_BUSY) {
		asm("nop");
	}
}

uint16_t enc28j60PHYRead(uint8_t address) {
	enc28j60CtrlRegWrite(MIREGADR, address);
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, MICMD, MICMD_MIIRD);
	while (enc28j60CtrlRegRead(MISTAT) & MISTAT_BUSY) {
		asm("nop");
	}
	enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, MICMD, MICMD_MIIRD);
	uint16_t mirdl = enc28j60CtrlRegRead(MIRDL);
	uint16_t mirdh = enc28j60CtrlRegRead(MIRDH);
	uint16_t receive = ((mirdh << 8) | mirdl);
	return receive;
}

void enc28j60SendPacket(uint8_t* data, uint16_t len) {

	while (enc28j60ReadOp(ENC28J60_READ_CTRL_REG, ECON1) & ECON1_TXRTS) {
		// Reset the transmit logic problem. See Rev. B4 Silicon Errata point 12.
		if ((enc28j60CtrlRegRead(EIR) & EIR_TXERIF)) {
			enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRST);
			enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRST);
		}
	}

	// Initialize transmit pointer
	enc28j60CtrlRegWrite(EWRPTL, TXSTART_INIT & 0xFF);
	enc28j60CtrlRegWrite(EWRPTH, TXSTART_INIT >> 8);

	// Initialize transmit buffor end to correspond with packet length
	enc28j60CtrlRegWrite(ETXNDL, (TXSTART_INIT + len + 1) & 0xFF);
	enc28j60CtrlRegWrite(ETXNDH, (TXSTART_INIT + len + 1) >> 8);

	// write per-packet control byte (0x00 means use macon3 settings)
	enc28j60WriteOp(ENC28J60_WRITE_BUF_MEM, 0, 0x00);

	// Write data to buffor
	enc28j60WriteBuffer(data, len);

	// Clear EIR.TXIF, set EIE.TXIE and set EIE.INTIE to enable an interrupt when done
//	enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, EIR, EIR_TXIF);
//	enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, EIE, EIE_TXIE|EIE_INTIE);

	// Start transmition
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);

	// Reset the transmit logic problem. See Rev. B4 Silicon Errata point 12.
//	if ((enc28j60CtrlRegRead(EIR) & EIR_TXERIF)) {
//		enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRTS);
//	}
}

uint16_t enc28j60ReceivePacket(uint8_t* packet, uint16_t maxlen) {
	uint16_t rxstat;
	uint16_t len;

	// check if a packet has been received and buffered
	//if( !(enc28j60Read(EIR) & EIR_PKTIF) ){
	// The above does not work. See Rev. B4 Silicon Errata point 6.
	if (enc28j60CtrlRegRead(EPKTCNT) == 0) {
		return (0);
	}

	//clear EIR_PKTIF bit, to receive next interrupt
	enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, EIR, EIR_PKTIF);
	//clear EIE_INTIE bit, to reset interrupts (~INT goes up)
	enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, EIE, EIE_INTIE);

	// Set the read pointer to the start of the received packet
	enc28j60CtrlRegWrite(ERDPTL, (enc28j60spi.nextPacketPointer));
	enc28j60CtrlRegWrite(ERDPTH, (enc28j60spi.nextPacketPointer) >> 8);

	// read the next packet pointer
	enc28j60spi.nextPacketPointer = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	enc28j60spi.nextPacketPointer |= (enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0)
			<< 8);

	// read the packet length (see datasheet page 43)
	len = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	len |= enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8;

	len -= 4; //remove the CRC count
	// read the receive status (see datasheet page 43)
	rxstat = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	rxstat |= (enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8);
	// limit retrieve length
	if (len > maxlen - 1) {
		len = maxlen - 1;
	}

	// check CRC and symbol errors (see datasheet page 44, table 7-3):
	// The ERXFCON.CRCEN is set by default. Normally we should not
	// need to check this.
	if ((rxstat & 0x80) == 0) {
		// invalid
		len = 0;
	} else {
		// copy the packet from the receive buffer
		enc28j60ReadBuffer(packet, len);
	}
	// Move the RX read pointer to the start of the next received packet
	// This frees the memory we just read out
	enc28j60CtrlRegWrite(ERXRDPTL, (enc28j60spi.nextPacketPointer));
	enc28j60CtrlRegWrite(ERXRDPTH, (enc28j60spi.nextPacketPointer) >> 8);

	// decrement the packet counter indicate we are done with this packet
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PKTDEC);

	//set EIE_INITE bit, to set receive next interrupt
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE);

	return len;
}
