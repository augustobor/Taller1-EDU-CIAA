/* Copyright 2015, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* Date: 2015-09-23 */

#ifndef _SAPI_H_
#define _SAPI_H_

/*==================[inclusions]=============================================*/

#include "sapi_datatypes.h"
#include "sapi_peripheral_map.h"

//#include "sapi_isr_vector.h"

// Peripheral Drivers

#include "sapi_board.h"                  // Use clock peripheral

#include "sapi_gpio.h"                   // Use GPIO peripherals
#include "sapi_uart.h"                   // Use UART peripherals
#include "sapi_adc.h"                    // Use ADC0 peripheral
#include "sapi_dac.h"                    // Use DAC peripheral
#include "sapi_i2c.h"                    // Use I2C0 peripheral
#include "sapi_spi.h"                    // Use SPI0 peripheral

#include "sapi_sleep.h"                  // Use ARM ASM instructions
#include "sapi_cyclesCounter.h"          // Use ARM Debug Registers


// High Level drivers

#include "sapi_stdio.h"                  // Use sapi_uart module

#include "sapi_print.h"                  // Use sapi_uart module
#include "sapi_debugPrint.h"             // Use sapi_print module
#include "sapi_consolePrint.h"           // Use sapi_print module

#include "sapi_convert.h"                // Use <string.h>

#include "sapi_delay.h"                  // Use sapi_tick module

#include "sapi_circularBuffer.h"         // It has no dependencies

#include "sapi_button.h"                 // Use sapi_gpio module

// External Peripheral Drivers


#include "sapi_imu_mpu9250.h"            // Use sapi_i2c module
#include "sapi_imu_mpu60X0.h"            // Use sapi_i2c module


/*==================[c++]====================================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[c++]====================================================*/
#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* _SAPI_H_ */
