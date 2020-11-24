// **********************************************
// Codes for Results Display on MicroController *
// **********************************************

#include "display.h"
#include "usart.h"

void gui(void)
{
    BSP_LCD_GLASS_Clear();
    BSP_LCD_GLASS_DisplayString("GUI");
    char ch_gui[10][40] = {"\n*********************************\n",
                           "*     *****     *     *  *****  *\n",
                           "*    *     *    *     *    *    *\n",
                           "*   *           *     *    *    *\n",
                           "*  *    ******  *     *    *    *\n",
                           "*   *       *   *     *    *    *\n",
                           "*    *     *    *     *    *    *\n",
                           "*     *****      *****   *****  *\n",
                           "*********************************"};
    for (int i = 0; i < 9; i++)
    {
        HAL_UART_Transmit(&huart2, &ch_gui[i], 40, 0xffff);
    }
    return;
}

void uart_print(char *msg2uart, int len)
{
    HAL_UART_Transmit(&huart2, "\n", 3, 0xffff);
    HAL_UART_Transmit(&huart2, &msg2uart, len, 0xffff);
    return;
}
