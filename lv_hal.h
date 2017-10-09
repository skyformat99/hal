/**
 * @file hal.h
 *
 */

#ifndef HAL_H
#define HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lv_hal_disp.h"
#include "lv_hal_indev.h"
#include <lvgl/lv_hal/lv_hal_tick.h>
#include "lv_hal_indev_keycode.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum _hal_ret_e {
    LV_HAL_OK,
    LV_HAL_ERR_INV,
    LV_HAL_ERR_NOMEM,
    LV_HAL_ERR_NODEV,
} hal_ret_e;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
