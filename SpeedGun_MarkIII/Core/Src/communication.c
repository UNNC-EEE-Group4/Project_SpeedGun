// ***************************************
// Codes for Communication with Computer *
// ***************************************

#include "communication.h"

/*
    @Brief: The printf() can be used to output debug info to serial monitor
    @Param: default
*/

//redefine printf to output to serial monitor via uart
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}
