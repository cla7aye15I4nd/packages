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
#ifndef __HAL_SLEEP_H__
#define __HAL_SLEEP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "plat_types.h"

enum HAL_CPU_WAKE_LOCK_USER_T {
    HAL_CPU_WAKE_LOCK_USER_RTOS,
    HAL_CPU_WAKE_LOCK_USER_EXTERNAL,
    HAL_CPU_WAKE_LOCK_USER_AUDIOFLINGER,
    HAL_CPU_WAKE_LOCK_USER_3,
    HAL_CPU_WAKE_LOCK_USER_4,
    HAL_CPU_WAKE_LOCK_USER_5,
    HAL_CPU_WAKE_LOCK_USER_6,
    HAL_CPU_WAKE_LOCK_USER_7,
    HAL_CPU_WAKE_LOCK_USER_8,
    HAL_CPU_WAKE_LOCK_USER_9,
    HAL_CPU_WAKE_LOCK_USER_10,
    HAL_CPU_WAKE_LOCK_USER_11,
    HAL_CPU_WAKE_LOCK_USER_12,
    HAL_CPU_WAKE_LOCK_USER_13,
    HAL_CPU_WAKE_LOCK_USER_14,
    HAL_CPU_WAKE_LOCK_USER_15,
    HAL_CPU_WAKE_LOCK_USER_16,
    HAL_CPU_WAKE_LOCK_USER_17,
    HAL_CPU_WAKE_LOCK_USER_18,
    HAL_CPU_WAKE_LOCK_USER_19,
    HAL_CPU_WAKE_LOCK_USER_20,
    HAL_CPU_WAKE_LOCK_USER_21,
    HAL_CPU_WAKE_LOCK_USER_22,
    HAL_CPU_WAKE_LOCK_USER_23,
    HAL_CPU_WAKE_LOCK_USER_24,
    HAL_CPU_WAKE_LOCK_USER_25,
    HAL_CPU_WAKE_LOCK_USER_26,
    HAL_CPU_WAKE_LOCK_USER_27,
    HAL_CPU_WAKE_LOCK_USER_28,
    HAL_CPU_WAKE_LOCK_USER_29,
    HAL_CPU_WAKE_LOCK_USER_30,
    HAL_CPU_WAKE_LOCK_USER_31,

    HAL_CPU_WAKE_LOCK_USER_QTY
};

enum HAL_SYS_WAKE_LOCK_USER_T {
    HAL_SYS_WAKE_LOCK_USER_INTERSYS,
    HAL_SYS_WAKE_LOCK_USER_INTERSYS_HCI,
    HAL_SYS_WAKE_LOCK_USER_KEY,
    HAL_SYS_WAKE_LOCK_USER_CODEC,
    HAL_SYS_WAKE_LOCK_USER_4,
    HAL_SYS_WAKE_LOCK_USER_5,
    HAL_SYS_WAKE_LOCK_USER_6,
    HAL_SYS_WAKE_LOCK_USER_7,
    HAL_SYS_WAKE_LOCK_USER_8,
    HAL_SYS_WAKE_LOCK_USER_9,
    HAL_SYS_WAKE_LOCK_USER_10,
    HAL_SYS_WAKE_LOCK_USER_11,
    HAL_SYS_WAKE_LOCK_USER_12,
    HAL_SYS_WAKE_LOCK_USER_13,
    HAL_SYS_WAKE_LOCK_USER_14,
    HAL_SYS_WAKE_LOCK_USER_15,
    HAL_SYS_WAKE_LOCK_USER_16,
    HAL_SYS_WAKE_LOCK_USER_17,
    HAL_SYS_WAKE_LOCK_USER_18,
    HAL_SYS_WAKE_LOCK_USER_19,
    HAL_SYS_WAKE_LOCK_USER_20,
    HAL_SYS_WAKE_LOCK_USER_21,
    HAL_SYS_WAKE_LOCK_USER_22,
    HAL_SYS_WAKE_LOCK_USER_23,
    HAL_SYS_WAKE_LOCK_USER_24,
    HAL_SYS_WAKE_LOCK_USER_25,
    HAL_SYS_WAKE_LOCK_USER_26,
    HAL_SYS_WAKE_LOCK_USER_27,
    HAL_SYS_WAKE_LOCK_USER_28,
    HAL_SYS_WAKE_LOCK_USER_29,
    HAL_SYS_WAKE_LOCK_USER_30,
    HAL_SYS_WAKE_LOCK_USER_31,

    HAL_SYS_WAKE_LOCK_USER_QTY
};

enum HAL_SLEEP_HOOK_USER_T {
    HAL_SLEEP_HOOK_USER_NVRECORD = 0,
    HAL_SLEEP_HOOK_USER_OTA,
    HAL_SLEEP_HOOK_NORFLASH_API,
    HAL_SLEEP_HOOK_DUMP_LOG,
    HAL_SLEEP_HOOK_USER_QTY
};

enum HAL_DEEP_SLEEP_HOOK_USER_T {
    HAL_DEEP_SLEEP_HOOK_USER_WDT = 0,
    HAL_DEEP_SLEEP_HOOK_USER_NVRECORD,
    HAL_DEEP_SLEEP_HOOK_USER_OTA,
    HAL_DEEP_SLEEP_HOOK_NORFLASH_API,
    HAL_DEEP_SLEEP_HOOK_DUMP_LOG,
    HAL_DEEP_SLEEP_HOOK_USER_QTY
};

enum HAL_SLEEP_STATUS_T {
    HAL_SLEEP_STATUS_DEEP,
    HAL_SLEEP_STATUS_SHALLOW,
};

struct CPU_USAGE_T {
    uint8_t busy;
    uint8_t shallow_sleep;
    uint8_t deep_sleep;
};

typedef int (*HAL_SLEEP_HOOK_HANDLER)(void);
typedef int (*HAL_DEEP_SLEEP_HOOK_HANDLER)(void);

int hal_sleep_irq_pending(void);

int hal_sleep_specific_irq_pending(const uint32_t *irq, uint32_t cnt);

enum HAL_SLEEP_STATUS_T hal_sleep_enter_sleep(void);

enum HAL_SLEEP_STATUS_T hal_sleep_shallow_sleep(void);

int hal_sleep_set_sleep_hook(enum HAL_SLEEP_HOOK_USER_T user, HAL_SLEEP_HOOK_HANDLER handler);

int hal_sleep_set_deep_sleep_hook(enum HAL_DEEP_SLEEP_HOOK_USER_T user, HAL_DEEP_SLEEP_HOOK_HANDLER handler);

int hal_cpu_wake_lock(enum HAL_CPU_WAKE_LOCK_USER_T user);

int hal_cpu_wake_unlock(enum HAL_CPU_WAKE_LOCK_USER_T user);

int hal_sys_wake_lock(enum HAL_SYS_WAKE_LOCK_USER_T user);

int hal_sys_wake_unlock(enum HAL_SYS_WAKE_LOCK_USER_T user);

void hal_sleep_start_stats(uint32_t stats_interval_ms, uint32_t trace_interval_ms);

int hal_sleep_get_stats(struct CPU_USAGE_T *usage);

#ifdef __cplusplus
}
#endif

#endif

