/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

int main(void)
{
    volatile uint32_t delay = 1000000;
    volatile uint32_t color = 0;

    // Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);

    // Set P1.0 to output direction
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    // Set P2.0 to output direction
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2);

    while (true)
    {
        // Toggle P1.0 output
        GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);

        // Toggle P2.0, P2.1, P2.2 output (red, green, blue, yellow, cyan, magenta)
        switch (color)
        {
        case 0: // red
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        case 1: // green
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        case 2: // blue
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        case 3: // yellow
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        case 4: // cyan
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        case 5: // magenta
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        default:
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        }

        // Set which color lights up on-board
        if (color < 5)
        {
            color++;
        }
        else
        {
            color = 0;
        }

        // Delay
        for (volatile uint32_t i = delay; i > 0; i--);

    }
}
