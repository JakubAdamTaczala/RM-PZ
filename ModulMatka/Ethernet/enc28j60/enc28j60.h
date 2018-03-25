/**
 * \file
 * Ethernet enc28j60 controller driver
 */
#ifndef ENC28J60_ENC28J60_H_
#define ENC28J60_ENC28J60_H_

#include <stdint.h>
#include "../stm32f4xx_hal.h"

/**
 * MAC address is 00:15:42:BF:F0:51
 */

#define MACADDRESS1 0x00
#define MACADDRESS2 0x15
#define MACADDRESS3 0x42
#define MACADDRESS4 0xBF
#define MACADDRESS5 0xF0
#define MACADDRESS6 0x51

// ENC28J60 Control Registers
// Control register definitions are a combination of address,
// bank number, and Ethernet/MAC/PHY indicator bits.
// - Register address       (bits 0-4)
// - Bank number        	(bits 5-6)
// - MAC/PHY indicator      (bit 7)
#define ADDR_MASK        0x1F	// 0b00011111
#define BANK_MASK        0x60	// 0b01100000
#define SPRD_MASK        0x80	// 0b10000000

// All-bank registers
#define EIE              0x1B
#define EIR              0x1C
#define ESTAT            0x1D
#define ECON2            0x1E
#define ECON1            0x1F

// Banks:
#define BANK0 			 0x00	// 0b00000000
#define BANK1			 0x20	// 0b00100000
#define BANK2			 0x40	// 0b01000000
#define BANK3			 0x60	// 0b01100000

#define DUMMY			 0x80	// 0b10000000

// Bank 0 registers
#define ERDPTL           (0x00|BANK0)
#define ERDPTH           (0x01|BANK0)
#define EWRPTL           (0x02|BANK0)
#define EWRPTH           (0x03|BANK0)
#define ETXSTL           (0x04|BANK0)
#define ETXSTH           (0x05|BANK0)
#define ETXNDL           (0x06|BANK0)
#define ETXNDH           (0x07|BANK0)
#define ERXSTL           (0x08|BANK0)
#define ERXSTH           (0x09|BANK0)
#define ERXNDL           (0x0A|BANK0)
#define ERXNDH           (0x0B|BANK0)
#define ERXRDPTL         (0x0C|BANK0)
#define ERXRDPTH         (0x0D|BANK0)
#define ERXWRPTL         (0x0E|BANK0)
#define ERXWRPTH         (0x0F|BANK0)
#define EDMASTL          (0x10|BANK0)
#define EDMASTH          (0x11|BANK0)
#define EDMANDL          (0x12|BANK0)
#define EDMANDH          (0x13|BANK0)
#define EDMADSTL         (0x14|BANK0)
#define EDMADSTH         (0x15|BANK0)
#define EDMACSL          (0x16|BANK0)
#define EDMACSH          (0x17|BANK0)

// Bank 1 registers
#define EHT0             (0x00|BANK1)
#define EHT1             (0x01|BANK1)
#define EHT2             (0x02|BANK1)
#define EHT3             (0x03|BANK1)
#define EHT4             (0x04|BANK1)
#define EHT5             (0x05|BANK1)
#define EHT6             (0x06|BANK1)
#define EHT7             (0x07|BANK1)
#define EPMM0            (0x08|BANK1)
#define EPMM1            (0x09|BANK1)
#define EPMM2            (0x0A|BANK1)
#define EPMM3            (0x0B|BANK1)
#define EPMM4            (0x0C|BANK1)
#define EPMM5            (0x0D|BANK1)
#define EPMM6            (0x0E|BANK1)
#define EPMM7            (0x0F|BANK1)
#define EPMCSL           (0x10|BANK1)
#define EPMCSH           (0x11|BANK1)
#define EPMOL            (0x14|BANK1)
#define EPMOH            (0x15|BANK1)
#define EWOLIE           (0x16|BANK1)
#define EWOLIR           (0x17|BANK1)
#define ERXFCON          (0x18|BANK1)
#define EPKTCNT          (0x19|BANK1)

// Bank 2 registers
#define MACON1           (0x00|BANK2|DUMMY)
#define MACON3           (0x02|BANK2|DUMMY)
#define MACON4           (0x03|BANK2|DUMMY)
#define MABBIPG          (0x04|BANK2|DUMMY)
#define MAIPGL           (0x06|BANK2|DUMMY)
#define MAIPGH           (0x07|BANK2|DUMMY)
#define MACLCON1         (0x08|BANK2|DUMMY)
#define MACLCON2         (0x09|BANK2|DUMMY)
#define MAMXFLL          (0x0A|BANK2|DUMMY)
#define MAMXFLH          (0x0B|BANK2|DUMMY)
#define MICMD            (0x12|BANK2|DUMMY)
#define MIREGADR         (0x14|BANK2|DUMMY)
#define MIWRL            (0x16|BANK2|DUMMY)
#define MIWRH            (0x17|BANK2|DUMMY)
#define MIRDL            (0x18|BANK2|DUMMY)
#define MIRDH            (0x19|BANK2|DUMMY)

// Bank 3 registers ??
#define MAADR5           (0x00|BANK3|DUMMY)
#define MAADR6           (0x01|BANK3|DUMMY)
#define MAADR3           (0x02|BANK3|DUMMY)
#define MAADR4           (0x03|BANK3|DUMMY)
#define MAADR1           (0x04|BANK3|DUMMY)
#define MAADR2           (0x05|BANK3|DUMMY)
#define EBSTSD           (0x06|BANK3)
#define EBSTCON          (0x07|BANK3)
#define EBSTCSL          (0x08|BANK3)
#define EBSTCSH          (0x09|BANK3)
#define MISTAT           (0x0A|BANK3|DUMMY)
#define EREVID           (0x12|BANK3)
#define ECOCON           (0x15|BANK3)
#define EFLOCON          (0x17|BANK3)
#define EPAUSL           (0x18|BANK3)
#define EPAUSH           (0x19|BANK3)

// PHY registers
#define PHCON1           0x00
#define PHSTAT1          0x01
#define PHID1            0x02
#define PHID2            0x03
#define PHCON2           0x10
#define PHSTAT2          0x11
#define PHIE             0x12
#define PHIR             0x13
#define PHLCON           0x14

// ENC28J60 ERXFCON Register Bit Definitions
#define ERXFCON_UCEN     0x80
#define ERXFCON_ANDOR    0x40
#define ERXFCON_CRCEN    0x20
#define ERXFCON_PMEN     0x10
#define ERXFCON_MPEN     0x08
#define ERXFCON_HTEN     0x04
#define ERXFCON_MCEN     0x02
#define ERXFCON_BCEN     0x01
// ENC28J60 EIE Register Bit Definitions
#define EIE_INTIE        0x80
#define EIE_PKTIE        0x40
#define EIE_DMAIE        0x20
#define EIE_LINKIE       0x10
#define EIE_TXIE         0x08
#define EIE_WOLIE        0x04
#define EIE_TXERIE       0x02
#define EIE_RXERIE       0x01
// ENC28J60 EIR Register Bit Definitions
#define EIR_PKTIF        0x40
#define EIR_DMAIF        0x20
#define EIR_LINKIF       0x10
#define EIR_TXIF         0x08
#define EIR_WOLIF        0x04
#define EIR_TXERIF       0x02
#define EIR_RXERIF       0x01
// ENC28J60 ESTAT Register Bit Definitions
#define ESTAT_INT        0x80
#define ESTAT_LATECOL    0x10
#define ESTAT_RXBUSY     0x04
#define ESTAT_TXABRT     0x02
#define ESTAT_CLKRDY     0x01
// ENC28J60 ECON2 Register Bit Definitions
#define ECON2_AUTOINC    0x80
#define ECON2_PKTDEC     0x40
#define ECON2_PWRSV      0x20
#define ECON2_VRPS       0x08
// ENC28J60 ECON1 Register Bit Definitions
#define ECON1_TXRST      0x80
#define ECON1_RXRST      0x40
#define ECON1_DMAST      0x20
#define ECON1_CSUMEN     0x10
#define ECON1_TXRTS      0x08
#define ECON1_RXEN       0x04
#define ECON1_BSEL1      0x02
#define ECON1_BSEL0      0x01
// ENC28J60 MACON1 Register Bit Definitions
#define MACON1_LOOPBK    0x10
#define MACON1_TXPAUS    0x08
#define MACON1_RXPAUS    0x04
#define MACON1_PASSALL   0x02
#define MACON1_MARXEN    0x01
// ENC28J60 MACON2 Register Bit Definitions
#define MACON2_MARST     0x80
#define MACON2_RNDRST    0x40
#define MACON2_MARXRST   0x08
#define MACON2_RFUNRST   0x04
#define MACON2_MATXRST   0x02
#define MACON2_TFUNRST   0x01
// ENC28J60 MACON3 Register Bit Definitions
#define MACON3_PADCFG2   0x80
#define MACON3_PADCFG1   0x40
#define MACON3_PADCFG0   0x20
#define MACON3_TXCRCEN   0x10
#define MACON3_PHDRLEN   0x08
#define MACON3_HFRMLEN   0x04
#define MACON3_FRMLNEN   0x02
#define MACON3_FULDPX    0x01
// ENC28J60 MICMD Register Bit Definitions
#define MICMD_MIISCAN    0x02
#define MICMD_MIIRD      0x01
// ENC28J60 MISTAT Register Bit Definitions
#define MISTAT_NVALID    0x04
#define MISTAT_SCAN      0x02
#define MISTAT_BUSY      0x01
// ENC28J60 PHY PHCON1 Register Bit Definitions
#define PHCON1_PRST      0x8000
#define PHCON1_PLOOPBK   0x4000
#define PHCON1_PPWRSV    0x0800
#define PHCON1_PDPXMD    0x0100
// ENC28J60 PHY PHSTAT1 Register Bit Definitions
#define PHSTAT1_PFDPX    0x1000
#define PHSTAT1_PHDPX    0x0800
#define PHSTAT1_LLSTAT   0x0004
#define PHSTAT1_JBSTAT   0x0002
// ENC28J60 PHY PHCON2 Register Bit Definitions
#define PHCON2_FRCLINK   0x4000
#define PHCON2_TXDIS     0x2000
#define PHCON2_JABBER    0x0400
#define PHCON2_HDLDIS    0x0100

// ENC28J60 Packet Control Byte Bit Definitions
#define PKTCTRL_PHUGEEN  0x08
#define PKTCTRL_PPADEN   0x04
#define PKTCTRL_PCRCEN   0x02
#define PKTCTRL_POVERRIDE 0x01

// SPI operation codes
#define ENC28J60_READ_CTRL_REG       0x00
#define ENC28J60_READ_BUF_MEM        0x3A
#define ENC28J60_WRITE_CTRL_REG      0x40
#define ENC28J60_WRITE_BUF_MEM       0x7A
#define ENC28J60_BIT_FIELD_SET       0x80
#define ENC28J60_BIT_FIELD_CLR       0xA0
#define ENC28J60_SOFT_RESET          0xFF

// The RXSTART_INIT should be zero. See Rev. B4 Silicon Errata
// buffer boundaries applied to internal 8K ram
// the entire available packet buffer space is allocated
//

/**
 * \brief start with recbuf at 0
 */
#define RXSTART_INIT     0x0

/**
 * \brief receive buffer end
 */
#define RXSTOP_INIT      0X19FE		//(0x1FFF-0x0600-1)

/**
 * start TX buffer at 0x1FFF-0x0600, pace for one full ethernet frame (~1500 bytes)
 */
#define TXSTART_INIT     0X19FF		//(0x1FFF-0x0600)
/**
 *  stop TX buffer at end of mem
 */
#define TXSTOP_INIT      0x1FFF

/**
 * max frame length which the conroller will accept
 */
#define        MAX_FRAMELEN        1500        // (note: maximum ethernet frame length would be 1518)
//#define MAX_FRAMELEN     600


/**
 * \brief enc28j60 Ethernet controller struct
 */
typedef struct {
	SPI_HandleTypeDef *spi;			//!< SPI structure
	GPIO_TypeDef *CSPort;			//!< port with chip select pin
	uint16_t CSPin;					//!< chip select pin
	uint8_t currentBank;			//!< current register bank
	uint16_t nextPacketPointer;		//!< pointer to the next receiver packet
} Enc28j60SPI;

/**
 * \brief Initialize SPI connection with ENC28J60 module
 * \param hspi Pointer to SPI struct
 * \param chipSelectPort Pointer to STM32 port with select chip pin
 * \param chipSelectPin Select chip pin
 */
void enc28j60Init(SPI_HandleTypeDef* hspi, GPIO_TypeDef* chipSelectPort, uint16_t chipSelectPin);

/**
* \brief When chip select is high then transmit is disabled
*/
void enc28j60ChipSelectHigh();

/**
 * \brief When chip select is low then transmit is enabled
 */
void enc28j60ChipSelectLow();

/**
 * \brief Read single byte from ENC28J60 module
 * \return Received byte
 */
uint8_t enc28j60ReceiveByte();

/**
 * \brief Write single byte to ENC28J60 module
 * \param data Byte data to transmit
 */
void enc28j60TransmitByte(uint8_t data);

/**
 * \brief write opcode instruction with single byte of data
 * \param opcode Write operation code
 * \param address Address of register
 * \param data Byte of data to write inside register
 */
void enc28j60WriteOp(uint8_t opcode, uint8_t address, uint8_t data);

/**
 * \brief Read opcode instruction returns data from address
 * \param opcode Read operation code
 * \param address Address of register
 * \return Value in register
 */
uint8_t enc28j60ReadOp(uint8_t opcode, uint8_t address);

/**
 * \brief Set register bank
 * \param address Register address or bank definition
 */
void enc28j60SetBank(uint8_t address);

/**
 * \brief Write control register
 * \param address Control register address
 * \param data Byte data to register
 */
void enc28j60CtrlRegWrite(uint8_t address, uint8_t data);

/**
 * \brief Read control register
 * \param address Control register address
 * \return Value in control register
 */
uint8_t enc28j60CtrlRegRead(uint8_t address);


/**
 * \brief Write data to controller buffer
 * \param data Pointer to data to write
 * \param len Size of data
 */
void enc28j60WriteBuffer(uint8_t* data, uint16_t len);

/**
 * \brief Read data to controller buffer
 * \param data Pointer to buffer for data
 * \param len Maximum size of data
 */
void enc28j60ReadBuffer(uint8_t* data, uint16_t len);

/**
 * \brief Write PHY register
 * \param address PHY register address
 * \param data Value to register
 */
void enc28j60PHYWrite(uint8_t address, uint16_t data);

/**
 * \brief Read PHY register
 * \param address PHY register address
 * \return Value in register
 */
uint16_t enc28j60PHYRead(uint8_t address);

/**
 * \brief Send packet of data
 * \param data Pointer to packet
 * \param len Size of packet
 */
void enc28j60SendPacket(uint8_t* data, uint16_t len);

/**
 * \brief Receive packet of data
 * \param data Pointer to buffer for packet
 * \param maxlen Maximum packet size
 */
uint16_t enc28j60ReceivePacket(uint8_t* data, uint16_t maxlen);

#endif /* ENC28J60_ENC28J60_H_ */
