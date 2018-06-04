/*
 * Copyright (c) 2016 Stephan Linz <linz@li-pro.net>, Li-Pro.Net
 * All rights reserved.
 *
 * Based on examples provided by
 * Iwan Budi Kusnanto <ibk@labhijau.net> (https://gist.github.com/iwanbk/1399729)
 * Juri Haberland <juri@sapienti-sat.org> (https://lists.gnu.org/archive/html/lwip-users/2007-06/msg00078.html)
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
 * This file is part of and a contribution to the lwIP TCP/IP stack.
 *
 * Credits go to Adam Dunkels (and the current maintainers) of this software.
 *
 * Stephan Linz rewrote this file to get a basic echo example.
 */

/**
 * @file
 * UDP echo server example using raw API.
 *
 * Echos all bytes sent by connecting client,
 * and passively closes when client is done.
 *
 */

#include "lwip/opt.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/udp.h"
#include "udpecho_raw.h"

#include "netif/etharp.h"
#include "enc28j60_ethernetif.h"
#include "lwip/init.h"
#include "string.h"

#if LWIP_UDP

static struct udp_pcb *udpecho_raw_pcb;
static struct netif networkInterface;

CommunicationStatus communication;

static void udpecho_raw_recv(void *arg, struct udp_pcb *upcb, struct pbuf *p,
		const ip_addr_t *addr, u16_t port) {
	LWIP_UNUSED_ARG(arg);
	if (p != NULL) {
		communication.addr = *addr;
		communication.port = port;
		communication.len = p->len;
		memcpy(communication.buffer, p->payload, p->len);

		/* send received packet back to sender */
		udp_sendto(upcb, p, addr, port);
		/* free the pbuf */
		pbuf_free(p);
	}
}

void send_udp(uint8_t* data, uint8_t len) {
	struct pbuf* p = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_RAM);
	memcpy(p->payload, data, len);
	/* send received packet back to sender */
	udp_sendto(udpecho_raw_pcb, p, &(communication.addr),  communication.port);
	pbuf_free(p);
}

void udpecho_raw_init(void) {
	struct ip4_addr myIp, netmask, gw;
	IP4_ADDR(&myIp, 192, 168, 0, 33);
	IP4_ADDR(&netmask, 255, 255, 255, 0);
	IP4_ADDR(&gw, 192, 168, 0, 1);
	uint16_t port = 8080;

	lwip_init();
	netif_add(&networkInterface, &myIp, &netmask, &gw, NULL,
			enc28j60_netif_init, ethernet_input);
	netif_set_up(&networkInterface);
	udpecho_raw_pcb = udp_new();
	if (udpecho_raw_pcb != NULL) {
		err_t err;
		err = udp_bind(udpecho_raw_pcb, &myIp, port);
		if (err == ERR_OK) {
			udp_recv(udpecho_raw_pcb, udpecho_raw_recv, NULL);
		} else {
			/* abort? output diagnostic? */
		}
	} else {
		/* abort? output diagnostic? */
	}
}

void udpecho_poll() {
	ethernetif_input(&networkInterface);
}

#endif /* LWIP_UDP */
