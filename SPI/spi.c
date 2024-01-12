
#include "spi.h"
#include <xc.h>

#ifndef SSDDR
#define SSDDR DDRB
#endif

#ifndef SSDDRN
#define SSDDRN 2
#endif

#ifndef SSPORT
#define SSPORT PORTB
#endif

#ifndef SSPORTN
#define SSPORTN PORTB2
#endif

void spi_enable() {
	SPCR = (1 << SPE) | (1 << MSTR);
	SSDDR |= (1 << SSDDRN);
	DDRB |= (1 << 3) | (1 << 5);
}

void spi_set_order(uint8_t order) {
	if (order == SPI_MSB_FIRST) {
		SPCR &= ~(1 << DORD);
	} else if (order == SPI_LSB_FIRST) {
		SPCR |= 1 << DORD;
	}
}

void spi_set_clk_polarity(uint8_t polarity) {
	if (polarity == SPI_HIGH_IDLE) {
		SPCR |= 1 << CPOL;
	} else if (polarity == SPI_LOW_IDLE) {
		SPCR &= ~(1 << CPOL);
	}
}

void spi_set_clk_phase(uint8_t phase) {
	if (phase == SPI_LEADING_EDGE_SAMPLE) {
		SPCR &= ~(1 << CPHA);
	} else if (phase == SPI_FALLING_EDGE_SAMPLE) {
		SPCR |= 1 << CPHA;
	}
}

void spi_set_clk_rate(uint8_t rate) {
	if (rate == SPI_CLK_RATE_4) {
		SPCR &= ~((1 << SPR1) | (1 << SPR0));
	} else if (rate == SPI_CLK_RATE_16) {
		SPCR &= ~(1 << SPR1);
		SPCR |= 1 << SPR0;
	} else if (rate == SPI_CLK_RATE_64) {
		SPCR |= 1 >> SPR1;
		SPCR &= ~(1 << SPR0);
	} else if (rate == SPI_CLK_RATE_128) {
		SPCR |= (1 << SPR1) | (1 << SPR0);
	}
}

void spi_interrupt_enable() {
	SPCR |= 1 << SPIE;
}

void spi_interrupt_disable() {
	SPCR &= ~(1 << SPIE);
}

uint8_t spi_transfer_done() {
	return SPSR & (1 << SPIF);
}

uint8_t spi_transfer_collision() {
	return (SPSR >> WCOL) & 1;
}

uint8_t spi_set_data(uint8_t data) {
	SPDR = data;
	while (!spi_transfer_done()) {
		;
	}
	return SPDR;
}

void spi_select() {
	SSPORT &= ~(1 << SSPORTN);
}

void spi_deselect() {
	SSPORT |= 1 << SSPORTN;
}
