#include <xc.h>
#include "w25qxx.h"
#include "spi.h"

void w25q_write_enable() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x6);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_volatile_sr_write_enable() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x50);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_write_disable() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x4);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_chip_erase() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0xc7);
	CS_PIN |= 1 << CS_PIN_NUM;
}


void w25q_suspend() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x75);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_resume() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x7a);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_power_down() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0xb9);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_enable_reset() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x66);
	CS_PIN |= 1 << CS_PIN_NUM;
}

void w25q_reset() {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x99);
	CS_PIN |= 1 << CS_PIN_NUM;
}

uint8_t w25q_read_sr1() {
	uint8_t result;
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x5);
	result = spi_set_data(0);
	CS_PIN |= 1 << CS_PIN_NUM;
	return result;
}

uint8_t w25q_read_sr2() {
	uint8_t result;
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x35);
	result = spi_set_data(0);
	CS_PIN |= 1 << CS_PIN_NUM;
	return result;
}

void w25q_write_sr(uint8_t lower_byte, uint8_t upper_byte) {
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x1);
	spi_set_data(lower_byte);
	spi_set_data(upper_byte);
	CS_PIN |= 1 << CS_PIN_NUM;
}

int w25q_page_program(uint32_t addr, uint8_t *buf, uint16_t buf_size) {
	
	if (buf_size > 256) {
		return 0;
	}
	
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x2);
	spi_set_data((uint8_t)((addr >> 16) & 0xff));
	spi_set_data((uint8_t)((addr >> 8) & 0xff));
	spi_set_data((uint8_t)(addr & 0xff));
	for (uint16_t i = 0; i < buf_size; i++) {
		spi_set_data(buf[i]);
	}
	CS_PIN |= (1 << CS_PIN_NUM);
	return 1;
}

int w25q_sector_erase(uint32_t addr) {
	
	if (addr & 0x111) {
		return 0;
	}
	
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x20);
	spi_set_data((uint8_t)((addr >> 16) & 0xff));
	spi_set_data((uint8_t)((addr >> 8) & 0xff));
	spi_set_data((uint8_t)(addr & 0xff));
	CS_PIN |= 1 << CS_PIN_NUM;
	return 1;
}

int w25q_block_erase_32(uint32_t addr) {
	
	if (addr & 0x1111) {
		return 0;
	}
	
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x52);
	spi_set_data((uint8_t)((addr >> 16) & 0xff));
	spi_set_data((uint8_t)((addr >> 8) & 0xff));
	spi_set_data((uint8_t)(addr & 0xff));
	CS_PIN |= 1 << CS_PIN_NUM;
	return 1;
}

int w25q_block_erase_64(uint32_t addr) {
	
	if (addr & 0x11111) {
		return 0;
	}
	
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0xd8);
	spi_set_data((uint8_t)((addr >> 16) & 0xff));
	spi_set_data((uint8_t)((addr >> 8) & 0xff));
	spi_set_data((uint8_t)(addr & 0xff));
	CS_PIN |= 1 << CS_PIN_NUM;
	return 1;
}

void w25q_read_data(uint32_t addr, uint8_t *buf, uint16_t buf_size) {
	
	CS_PIN &= ~(1 << CS_PIN_NUM);
	spi_set_data(0x03);
	spi_set_data((uint8_t)((addr >> 16) & 0xff));
	spi_set_data((uint8_t)((addr >> 8) & 0xff));
	spi_set_data((uint8_t)(addr & 0xff));
	for (uint16_t i = 0; i < buf_size; i++) {
		buf[i] = spi_set_data(0);
	}
	CS_PIN |= 1 << CS_PIN_NUM;
	
}