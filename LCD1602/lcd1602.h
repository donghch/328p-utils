/*
 * lcdLCD1602.h
 *
 * Created: 2024-01-23 4:36:09 PM
 *  Author: diesh
 */ 

#include <xc.h>
#include <inttypes.h>

#ifndef _LCDLCD1602_H_
#define _LCDLCD1602_H_


/* Control Bus Definitions */

#ifndef LCD1602_RS_D
#define LCD1602_RS_D DDRB 
#endif

#ifndef LCD1602_RS_P
#define LCD1602_RS_P PORTB
#endif

#ifndef LCD1602_RS_PN
#define LCD1602_RS_PN PORTB1
#endif

#ifndef LCD1602_E_D
#define LCD1602_E_D DDRB
#endif

#ifndef LCD1602_E_P
#define LCD1602_E_P PORTB
#endif

#ifndef LCD1602_E_PN
#define LCD1602_E_PN PORTB2
#endif

/* Data bus Definitions */

#ifndef LCD1602_D7_D
#define LCD1602_D7_D DDRD
#endif

#ifndef LCD1602_D7_P
#define LCD1602_D7_P PORTD
#endif

#ifndef LCD1602_D7_PN
#define LCD1602_D7_PN PORTD7
#endif

#ifndef LCD1602_D6_D
#define LCD1602_D6_D DDRD
#endif

#ifndef LCD1602_D6_P
#define LCD1602_D6_P PORTD
#endif

#ifndef LCD1602_D6_PN
#define LCD1602_D6_PN PORTD6
#endif

#ifndef LCD1602_D5_D
#define LCD1602_D5_D DDRD
#endif

#ifndef LCD1602_D5_P
#define LCD1602_D5_P PORTD
#endif

#ifndef LCD1602_D5_PN
#define LCD1602_D5_PN PORTD5
#endif

#ifndef LCD1602_D4_D
#define LCD1602_D4_D DDRD
#endif

#ifndef LCD1602_D4_P
#define LCD1602_D4_P PORTD
#endif

#ifndef LCD1602_D4_PN
#define LCD1602_D4_PN PORTD4
#endif

#ifndef LCD1602_D3_D
#define LCD1602_D3_D DDRD
#endif

#ifndef LCD1602_D3_P
#define LCD1602_D3_P PORTD
#endif

#ifndef LCD1602_D3_PN
#define LCD1602_D3_PN PORTD3
#endif

#ifndef LCD1602_D2_D
#define LCD1602_D2_D DDRD
#endif

#ifndef LCD1602_D2_P
#define LCD1602_D2_P PORTD
#endif

#ifndef LCD1602_D2_PN
#define LCD1602_D2_PN PORTD2
#endif

#ifndef LCD1602_D1_D
#define LCD1602_D1_D DDRD
#endif

#ifndef LCD1602_D1_P
#define LCD1602_D1_P PORTD
#endif

#ifndef LCD1602_D1_PN
#define LCD1602_D1_PN PORTD1
#endif

#ifndef LCD1602_D0_D
#define LCD1602_D0_D DDRD
#endif

#ifndef LCD1602_D0_P
#define LCD1602_D0_P PORTD
#endif

#ifndef LCD1602_D0_PN
#define LCD1602_D0_PN PORTD0
#endif

/* Options definitions */
#define LCD1602_CURSOR_MOVE_LEFT 0
#define LCD1602_CURSOR_MOVE_RIGHT 1

#define LCD1602_DISPLAY_SHIFT_ENABLE 2

#define LCD1602_DISPLAY_ON 4
#define LCD1602_CURSOR_ON 8
#define LCD1602_CURSOR_BLINK_ON 16

/* Function Set Options */

#define LCD1602_ONE_LINE 0
#define LCD1602_TWO_LINE 1

#define LCD1602_5x8_FONT 0
#define LCD1602_5x11_FONT 2




/* Function Definitions */ 

void lcd1602_setup();

void lcd1602_clear();

void lcd1602_home();

void lcd1602_set_entry_mode(uint8_t mode);

void lcd1602_set_display(uint8_t options);

void lcd1602_set_shift(uint8_t options);

void lcd1602_set_function(uint8_t options);

void lcd1602_set_cgram_addr(uint8_t data);

void lcd1602_set_ddram_addr(uint8_t data);

void lcd1602_write_ram(uint8_t data);

uint8_t lcd1602_read_ram();

void lcd1602_set_data(uint8_t data);

void lcd1602_send_data();


#endif /* _LCDLCD1602_H_ */