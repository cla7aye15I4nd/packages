/***************************************************************************
 *
 * Copyright 2015-2019 BES.
 * All rights reserved. All unpublished rights reserved.
 *
 * No part of this work may be used or reproduced in any form or by any
 * means, or stored in a database or retrieval system, without prior written
 * permission of BES.
 *
 * Use of this work is governed by a license granted by BES.
 * This work contains confidential and proprietary information of
 * BES. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#ifndef __PLAT_ADDR_MAP_BEST1400_H__
#define __PLAT_ADDR_MAP_BEST1400_H__

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************
    ROM: 0x0001_FFFF ~ 0x0000_0000
**************************************************/
#define ROM_BASE                                0x00000000
#ifndef ROM_SIZE
/* Total ROM_SIZE: 128 KB; boot ROM: 48 KB */
#define ROM_SIZE                                0x0000C000
#endif


/*************************************************
    SRAM: 
        0x2003_FFFF ~ 0x2002_0000 (SRAM1 128 KB NC address)
        0x0023_FFFF ~ 0x0022_0000 (SRAM1 128 KB C  address)
        0x2001_FFFF ~ 0x2000_0000 (SRAM0 128 KB NC address)
        0x0021_FFFF ~ 0x0020_0000 (SRAM0 128 KB C  address)
*************************************************/
#define RAM0_BASE                               0x20000000  
#define RAMX0_BASE                              0x00200000
#define RAM1_BASE                               0x20020000      /* actually no RAM1 */
#define RAMX1_BASE                              0x00220000
#define RAM_BASE                                RAM0_BASE
#define RAMX_BASE                               RAMX0_BASE
#ifndef RAM_SIZE
#define RAM_SIZE                                (0x00040000)      /* 256 KB */
#endif


/************************************************
    Nor FLASH:
        0x3FFF_FFFF ~ 0x3C00_0000 (alias)
        0x3BFF_FFFF ~ 0x3800_0000 (alias)
        0x0FFF_FFFF ~ 0x0C00_0000
        0x0BFF_FFFF ~ 0x0800_0000
************************************************/
#define FLASH_BASE                              0x3C000000
#define FLASH_NC_BASE                           0x38000000
#define FLASHX_BASE                             0x0C000000
#define FLASHX_NC_BASE                          0x08000000


/************************************************
    CACHE
************************************************/
#define ICACHE_CTRL_BASE                        0x07FFE000
/* No data cache */


/************************************************
    AHB0 (APB0): 0x400F_FFFF ~ 0x4000_0000
************************************************/
/* CMU: 0x4000_0FFF ~ 0x4000_0000 */
#define CMU_BASE                                0x40000000
/* GPIO: 0x4000_1FFF ~ 0x4000_1000 */
#define GPIO_BASE                               0x40001000
/* WDT: 0x4000_2FFF ~ 0x4000_2000 */
#define WDT_BASE                                0x40002000
/* PWM: 0x4000_3FFF ~ 0x4000_3000 */
#define PWM_BASE                                0x40003000
/* TIMER0: 0x4000_4FFF ~ 0x4000_4000 */
#define TIMER0_BASE                             0x40004000
/* TIMER1: 0x4000_5FFF ~ 0x4000_5000 */
#define TIMER1_BASE                             0x40005000
/* I2C0: 0x4000_6FFF ~ 0x4000_6000 */
#define I2C0_BASE                               0x40006000
/* SPI: 0x4000_7FFF ~ 0x4000_7000 */
#define SPI_BASE                                0x40007000
/* Internal SPI: 0x4000_8FFF ~ 0x4000_8000 */
#define ISPI_BASE                               0x40008000
/* SPI for USB PHY = ISPI */
#define SPIPHY_BASE                             0x40008000
/* UART0: 0x4000_9FFF ~ 0x4000_9000 */
#define UART0_BASE                              0x40009000
/* UART1: 0x4000_AFFF ~ 0x4000_A000 */
#define UART1_BASE                              0x4000A000
/* I2S: 0x4000_BFFF ~ 0x4000_B000 */
#define I2S0_BASE                               0x4000B000
/* UART2: 0x4000_CFFF ~ 0x4000_C000 */
#define UART2_BASE                              0x4000C000
/* IOMUX: 0x4000_DFFF ~ 0x4000_D000 */
#define IOMUX_BASE                              0x4000D000
/* BTPCM: 0x4000_EFFF ~ 0x4000_E000 */
#define BTPCM_BASE                              0x4000E000

/* BT */
#define BT_SUBSYS_BASE                          0xA0000000
#define BT_RAM_BASE                             0xC0000000
#define BT_UART_BASE                            0xD0300000
#define BT_CMU_BASE                             0xD0330000

/***********************************************
    AHB1: 0x401F_FFFF ~ 0x4010_0000
***********************************************/
/* GPDMA: 0x4013_FFFF ~ 0x4013_0000 */
#define GPDMA_BASE                              0x40130000
/* AUDMA = GPDMA */
#define AUDMA_BASE                              0x40130000
/* FLASH: 0x4014_FFFF ~ 0x4014_0000 */
#define FLASH_CTRL_BASE                         0x40140000
/* BT DUMP: 0x4015_FFFF ~ 0x4015_0000 */
#define BTDUMP_BASE                             0x40150000
/* I2C_SLAVE_BASE: 0x4016_FFFF ~ 0x4016_0000 */
#define I2C_SLAVE_BASE                          0x40160000
/* USB OTG: 0x401C_FFFF ~ 0x4018_0000 */
#define USB_BASE                                0x40180000


/***********************************************
    CODEC: 0x403F_FFFF ~ 0x4030_0000
***********************************************/
#define CODEC_BASE                              0x40300000


/***********************************************
    For Linker Scripts
***********************************************/
#define VECTOR_SECTION_SIZE                     256     /* to store interrupt vectors */
#define REBOOT_PARAM_SECTION_SIZE               64      /* reserved for reboot param */
#define ROM_BUILD_INFO_SECTION_SIZE             40      /* for ROM build info */
#define ROM_EXPORT_FN_SECTION_SIZE              128     /* exported functions which could be called outside the ROM */


#ifdef __cplusplus
}
#endif

#endif
