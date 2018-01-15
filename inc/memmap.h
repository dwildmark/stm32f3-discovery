/* *****************************************************************************
 * Copyright (c) 2017 Dennis Wildmark
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ****************************************************************************/

/*
 * Author(s): Dennis Wildmark <d.wildmark@gmail.com>
 */

#ifndef MEMMAP_H
#define MEMMAP_H

#define ADC3_4_BASE             0x50000400
#define ADC3_4_HIGH             0x500007FF

#define ADC1_2_BASE             0x50000000
#define ADC1_2_HIGH             0x500003FF

#define GPIO_A_BASE             0x48000000
#define GPIO_B_BASE             0x48000400
#define GPIO_C_BASE             0x48000800
#define GPIO_D_BASE             0x48000C00
#define GPIO_E_BASE             0x48001000
#define GPIO_F_BASE             0x48001400

#define DMA1_BASE               0x40020000
#define DMA2_BASE               0x40020400
#define RCC_BASE                0x40021000
#define FLASH_IF_BASE           0x40022000
#define CRC_BASE                0x40023000
#define TSC_BASE                0x40024000

#define SYSCFG_COMP_OPAMP_BASE  0x40010000
#define EXTI_BASE               0x40010400
#define TIM1_BASE               0x40012C00
#define SPI1_BASE               0x40013000
#define TIM8_BASE               0x40013400
#define USART1_BASE             0x40013800
#define TIM15_BASE              0x40014000
#define TIM16_BASE              0x40014400
#define TIM17_BASE              0x40014800

#define TIM2_BASE               0x40000000
#define TIM3_BASE               0x40000400
#define TIM4_BASE               0x40000800
#define TIM6_BASE               0x40001000
#define TIM7_BASE               0x40001400
#define RTC_BASE                0x40002800
#define WWDG_BASE               0x40002C00
#define IWDG_BASE               0x40003000
#define I2S2ext_BASE            0x40003400
#define SPI2_I2S2_BASE          0x40003800
#define SPI3_I2S3_BASE          0x40003C00
#define I2S3ext_BASE            0x40004000
#define USART2_BASE             0x40004400
#define USART3_BASE             0x40004800
#define UART4_BASE              0x40004C00
#define UART5_BASE              0x40005000
#define I2C1_BASE               0x40005400
#define I2C2_BASE               0x40005800
#define USB_DEV_FS_BASE         0x40005C00
#define USB_SRAM_BASE           0x40006000
#define BX_CAN_BASE             0x40006400
#define PWR_BASE                0x40007000
#define DAC1_BASE               0x40007400

#endif /* MEMMAP_H */
