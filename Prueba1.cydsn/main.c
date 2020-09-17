/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
char dato;
CY_ISR(InterruptRX)
 {
  dato=UART_1_GetChar();
  if(dato=='0'){
    UART_1_PutChar(5);
    OUTS_Write(0);}
  if (dato=='1'){OUTS_Write(1);}
 }

int main(void)
{
    UART_1_Start();
    ISR_RX_StartEx(InterruptRX);
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
    }
}

/* [] END OF FILE */
