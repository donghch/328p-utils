/*
 * library.c
 *
 * Created: 1/23/2024 4:35:00 PM
 *  Author: diesh
 */ 

#include <xc.h>
#include "lcd1602.h"

#ifndef F_CPU
#define F_CPU 8000000
#endif 
#include <util/delay.h>

void lcd1602_send_data() {
	_delay_us(200);
	LCD1602_E_P |= 1 << LCD1602_E_PN;
	_delay_us(650);
	LCD1602_E_P &= ~(1 << LCD1602_E_PN);
	_delay_us(650);
}

void lcd1602_set_data(uint8_t data) {
	
	if (data & (1 << 7)) {
		LCD1602_D7_P |= (1 << LCD1602_D7_PN);
	} else{
		LCD1602_D7_P &= ~(1 << LCD1602_D7_PN);
	}
	
	if (data & (1 << 6)) {
		LCD1602_D6_P |= (1 << LCD1602_D6_PN);
		} else{
		LCD1602_D6_P &= ~(1 << LCD1602_D6_PN);
	}
	
	if (data & (1 << 5)) {
		LCD1602_D5_P |= (1 << LCD1602_D5_PN);
		} else{
		LCD1602_D5_P &= ~(1 << LCD1602_D5_PN);
	}
	
	if (data & (1 << 4)) {
		LCD1602_D4_P |= (1 << LCD1602_D4_PN);
		} else{
		LCD1602_D4_P &= ~(1 << LCD1602_D4_PN);
	}
	
	if (data & (1 << 3)) {
		LCD1602_D3_P |= (1 << LCD1602_D3_PN);
		} else{
		LCD1602_D3_P &= ~(1 << LCD1602_D3_PN);
	}
	
	if (data & (1 << 2)) {
		LCD1602_D2_P |= (1 << LCD1602_D2_PN);
		} else{
		LCD1602_D2_P &= ~(1 << LCD1602_D2_PN);
	}
	
	if (data & (1 << 1)) {
		LCD1602_D1_P |= (1 << LCD1602_D1_PN);
		} else{
		LCD1602_D1_P &= ~(1 << LCD1602_D1_PN);
	}
	
	if (data & (1 << 0)) {
		LCD1602_D0_P |= (1 << LCD1602_D0_PN);
		} else{
		LCD1602_D0_P &= ~(1 << LCD1602_D0_PN);
	}
	
}

void lcd1602_setup() {
	
	LCD1602_E_D |= 1 << LCD1602_E_PN;
	LCD1602_RS_D |= 1 << LCD1602_RS_PN;
	LCD1602_D7_D |= 1 << LCD1602_D7_PN;
	LCD1602_D6_D |= 1 << LCD1602_D6_PN;
	LCD1602_D5_D |= 1 << LCD1602_D5_PN;
	LCD1602_D4_D |= 1 << LCD1602_D4_PN;
	LCD1602_D3_D |= 1 << LCD1602_D3_PN;
	LCD1602_D2_D |= 1 << LCD1602_D2_PN;
	LCD1602_D1_D |= 1 << LCD1602_D1_PN;
	LCD1602_D0_D |= 1 << LCD1602_D0_PN;
	
}

void lcd1602_clear() {
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	lcd1602_set_data(0b1);
	lcd1602_send_data();
}

void lcd1602_home() {
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	lcd1602_set_data(0b10);
	lcd1602_send_data();
}

void lcd1602_set_entry_mode(uint8_t mode) {
	
	uint8_t temp_data = 0b100;
	
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	if (mode & LCD1602_CURSOR_MOVE_RIGHT) {
		temp_data |= 0b10;
	} 
	if (mode & LCD1602_DISPLAY_SHIFT_ENABLE) {
		temp_data |= 0b1;
	}
	lcd1602_set_data(temp_data);
	lcd1602_send_data();
}

void lcd1602_set_display(uint8_t options) {
	uint8_t temp_data = 0b1000;
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	if (options | LCD1602_DISPLAY_ON) {
		temp_data |= 0b100;
	}
	if (options | LCD1602_CURSOR_ON) {
		temp_data |= 0b10;
	}
	if (options | LCD1602_CURSOR_BLINK_ON) {
		temp_data |= 0b1;
	}
	lcd1602_set_data(temp_data);
	lcd1602_send_data();
}

void lcd1602_set_shift(uint8_t options) {
	
}

void lcd1602_set_function(uint8_t options) {
	
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	uint8_t temp_data = 0b110000;
	if (options | LCD1602_TWO_LINE) {
		temp_data |= 0b1000;
	}
	if (options | LCD1602_5x11_FONT) {
		temp_data |= 0b100;
	}
	lcd1602_set_data(temp_data);
	lcd1602_send_data();
}

void lcd1602_set_cgram_addr(uint8_t data) {
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	lcd1602_set_data((data & 0b111111) | 0b1000000);
	lcd1602_send_data();
}

void lcd1602_set_ddram_addr(uint8_t data) {
	LCD1602_RS_P &= ~(1 << LCD1602_RS_PN);
	lcd1602_set_data((data & 0b1111111) | 0b10000000);
	lcd1602_send_data();
}

void lcd1602_write_ram(uint8_t data) {
	LCD1602_RS_P |= 1 << LCD1602_RS_PN;
	lcd1602_set_data(data);
	lcd1602_send_data();
}
