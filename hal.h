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

/*********************
 *      DEFINES
 *********************/
 #include "disp/hal_disp.h"

/**********************
 *      TYPEDEFS
 **********************/
typedef enum _hal_ret_e {
    HAL_OK,
    HAL_ERR_INVAL,
    HAL_ERR_NOMEM,
    HAL_ERR_NODEV,
    HAL_ERR_LISTFULL,
    HAL_ERR_LISTEMPTY,
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
