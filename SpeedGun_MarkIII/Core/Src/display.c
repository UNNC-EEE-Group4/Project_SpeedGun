// **********************************************
// Codes for Results Display on MicroController *
// **********************************************

#include "display.h"

void gui(void)
{
    BSP_LCD_GLASS_Clear();
    BSP_LCD_GLASS_DisplayString("GUI");
    char ch_gui[10][100] = {"**********************************************************************************",
                            "*   *****    *****    *****   *****  ******    *****   *     *  *     *          *",
                            "*  *        *     *  *       *       *     *  *        *     *  **    *          *",
                            "*  *        *     *  *       *       *     *  *        *     *  * *   *          *",
                            "*   *****   ******    *****   *****  *     *  *  ***   *     *  *  *  *          *",
                            "*        *  *        *       *       *     *  *     *  *     *  *   * *          *",
                            "*        *  *        *       *       *     *  *     *  *     *  *    **          *",
                            "*   *****   *         *****   *****  ******    *****    *****   *     * MARK III *",
                            "**********************************************************************************"};
    for (int i = 0; i < 9; i++)
    {
        uart_print(ch_gui[i]);
    }
    uart_print("Bonjour!");
    uart_print("Press RIGHT joystick button to continue...");
    return;
}

void uart_print(char msg2uart[])
{
    int len = strlen(msg2uart);
    HAL_UART_Transmit(&huart2, "\n", 3, 0xffff);
    HAL_UART_Transmit(&huart2, msg2uart, len, 0xffff);
    return;
}
