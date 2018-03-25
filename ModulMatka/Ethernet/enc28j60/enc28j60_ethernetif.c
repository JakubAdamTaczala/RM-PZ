/**
 * @file
 * Ethernet Interface Initialization file
 *
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#include <enc28j60_ethernetif.h>
#include <string.h>

extern Enc28j60SPI enc28j60spi;

static void low_level_init(struct netif *netif) {
	netif->hwaddr_len = ETHARP_HWADDR_LEN;

	/* set MAC hardware address */
	netif->hwaddr[0] = MACADDRESS1;
	netif->hwaddr[1] = MACADDRESS2;
	netif->hwaddr[2] = MACADDRESS3;
	netif->hwaddr[3] = MACADDRESS4;
	netif->hwaddr[4] = MACADDRESS5;
	netif->hwaddr[5] = MACADDRESS6;

	/* maximum transfer unit */
	netif->mtu = MAX_FRAMELEN;

	/* device capabilities */
	/* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
	netif->flags =
	NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

	/* Initialize enc28j60. */
	enc28j60Init(ENC28J60_SPI, ENC28J60_CS_PORT, ENC28J60_CS_PIN);
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become available since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */

static err_t low_level_output(struct netif *netif, struct pbuf *p) {
	struct pbuf *q;

	printf("out fun\n");
	while (enc28j60ReadOp(ENC28J60_READ_CTRL_REG, ECON1) & ECON1_TXRTS) {
		// Reset the transmit logic problem. See Rev. B4 Silicon Errata point 12.
		if ((enc28j60CtrlRegRead(EIR) & EIR_TXERIF)) {
			enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRST);
			enc28j60WriteOp(ENC28J60_BIT_FIELD_CLR, ECON1, ECON1_TXRST);
		}
	}

	printf("Writing len=%d\n", p->tot_len);

	// Initialize transmit pointer
	enc28j60CtrlRegWrite(EWRPTL, TXSTART_INIT & 0xFF);
	enc28j60CtrlRegWrite(EWRPTH, TXSTART_INIT >> 8);

	// Initialize transmit buffor end to correspond with packet length
	enc28j60CtrlRegWrite(ETXNDL, (TXSTART_INIT + p->tot_len + 1) & 0xFF);
	enc28j60CtrlRegWrite(ETXNDH, (TXSTART_INIT + p->tot_len + 1) >> 8);

	// write per-packet control byte (0x00 means use macon3 settings)
	enc28j60WriteOp(ENC28J60_WRITE_BUF_MEM, 0, 0x00);

	for (q = p; q != NULL; q = q->next) {
		/* Send the data from the pbuf to the interface, one pbuf at a
		 time. The size of the data in each pbuf is kept in the ->len
		 variable. */
		// Write data to buffor
		enc28j60WriteBuffer(q->payload, q->len);
		printf("writing\n");
	}

	printf("send\n");
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_TXRTS);
	return ERR_OK;
}

/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static struct pbuf *
low_level_input(struct netif *netif) {

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

	uint16_t len;
	uint16_t rxstat;
	// read the packet length (see datasheet page 43)
	len = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	len |= enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8;

	printf("len=%d\n", len);

	struct pbuf *p, *q;

	len -= 4; //remove the CRC count
	// read the receive status (see datasheet page 43)
	rxstat = enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0);
	rxstat |= (enc28j60ReadOp(ENC28J60_READ_BUF_MEM, 0) << 8);
	// limit retrieve length
	if (len > MAX_FRAMELEN - 1) {
		len = MAX_FRAMELEN - 1;
	}

	// check CRC and symbol errors (see datasheet page 44, table 7-3):
	// The ERXFCON.CRCEN is set by default. Normally we should not
	// need to check this.
	if ((rxstat & 0x80) == 0) {
		// invalid
		len = 0;
	} else {

		p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
		if (p != NULL) {
			for (q = p; q != NULL; q = q->next) {
				// copy the packet from the receive buffer
				enc28j60ReadBuffer(q->payload, q->len);
			}
		}
	}
	// Move the RX read pointer to the start of the next received packet
	// This frees the memory we just read out
	enc28j60CtrlRegWrite(ERXRDPTL, (enc28j60spi.nextPacketPointer));
	enc28j60CtrlRegWrite(ERXRDPTH, (enc28j60spi.nextPacketPointer) >> 8);

	// decrement the packet counter indicate we are done with this packet
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON2, ECON2_PKTDEC);

	//set EIE_INITE bit, to set receive next interrupt
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE);

	return p;
}

/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
void ethernetif_input(struct netif *netif) {
	struct pbuf *p;
	/* move received packet into a new pbuf */
	p = low_level_input(netif);
	/* if no packet could be read, silently ignore this */
	if (p != NULL) {
		/* pass all packets to ethernet_input, which decides what packets it supports */
		if (netif->input(p, netif) != ERR_OK) {
			LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_input: IP input error\n"));
			pbuf_free(p);
			p = NULL;
		}
	}
}

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t enc28j60_netif_init(struct netif *netif) {
	netif->name[0] = IFNAME0;
	netif->name[1] = IFNAME1;
	/* We directly use etharp_output() here to save a function call.
	 * You can instead declare your own function an call etharp_output()
	 * from it if you have to do some checks before sending (e.g. if link
	 * is available...) */
	netif->output = etharp_output;
	netif->linkoutput = low_level_output;

	low_level_init(netif);

	return ERR_OK;
}
