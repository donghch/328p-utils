
#ifndef _W25QXX_H_
#define _W25QXX_H_

#include "spi.h"
#include <xc.h>
#include <inttypes.h>

#ifndef CS_PIN_D
#define CS_PIN_D DDRB
#endif

#ifndef CS_PIN_NUM
#define CS_PIN_NUM PORTB2
#endif

#ifndef CS_PIN
#define CS_PIN PORTB
#endif


void w25q_write_enable();

void w25q_volatile_sr_write_enable();

void w25q_write_disable();

void w25q_chip_erase();

void w25q_suspend();

void w25q_resume();

void w25q_power_down();

void w25q_enable_reset();

void w25q_reset();

uint8_t w25q_read_sr1();

uint8_t w25q_read_sr2();

void w25q_write_sr(uint8_t lower_byte, uint8_t upper_byte);

int w25q_page_program(uint32_t addr, uint8_t *buf, uint16_t buf_size);

int w25q_sector_erase(uint32_t addr);

int w25q_block_erase_32(uint32_t addr);

int w25q_block_erase_64(uint32_t addr);

void w25q_read_data(uint32_t addr, uint8_t *buf, uint16_t buf_size);




#endif