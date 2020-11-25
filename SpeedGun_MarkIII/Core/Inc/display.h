// ****************************************************
// Header file for Results Display on MicroController *
// ****************************************************

#ifndef __DISPLAY_H
#define __DISPLAY_H

//includes
#include "usart.h"
#include "string.h"

//global variables

//function headers
/*
    @Brief: Display GUI in Serial Monitor via UART
    @Param: None
*/
void gui(void);
/*
    @Brief: Send msg to serial monitor via UART
    @Param: msg2uart->cstring type msg
*/
void uart_print(char msg2uart[]);

#endif /*__DISPLAY_H*/
