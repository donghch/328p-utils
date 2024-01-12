#ifndef _SPI_H_
#define _SPI_H_

#include <stdint.h>

//Data order definition
#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 1

//Clock polarity definition
#define SPI_HIGH_IDLE 1
#define SPI_LOW_IDLE 0

//Clock phase definition
#define SPI_LEADING_EDGE_SAMPLE 0
#define SPI_FALLING_EDGE_SAMPLE 1

//Clock rate definition
#define SPI_CLK_RATE_4 0
#define SPI_CLK_RATE_16 1
#define SPI_CLK_RATE_64 2
#define SPI_CLK_RATE_128 3

//Low level function definitions

void spi_enable();

void spi_set_order(uint8_t order);

void spi_set_clk_polarity(uint8_t polarity);

void spi_set_clk_phase(uint8_t phase);

void spi_set_clk_rate(uint8_t rate);

void spi_interrupt_enable();

void spi_interrupt_disable();

uint8_t spi_transfer_done();

uint8_t spi_transfer_collision();

uint8_t spi_speed_double();

uint8_t spi_speed_halve();

uint8_t spi_set_data(uint8_t data);

void spi_select();

void spi_deselect();
#endif