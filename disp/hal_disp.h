/**
 * @file hal_disp.h
 *
 * @description Display Driver HAL interface header file
 *
 */

#ifndef HAL_DISP_H
#define HAL_DISP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "../hal.h"
#include "misc/gfx/color.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
/**
 * User Display driver HAL interface
 */

/**
 * Display Driver struction to be registered with HAL
 */
typedef struct _disp_drv_t {
    const char *name;
    int32_t h_res;
    int32_t v_res;
    void (*init)(void);
    void (*fill)(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color);
    void (*map)(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const color_t * color_p);
#if DISP_HW_ACC != 0
    void (*color_cpy)(color_t * dest, const color_t * src, uint32_t length, opa_t opa);
#endif
} disp_drv_t;

/**
 * Register Display driver
 *
 * @param driver Display driver structure
 * @return 0 on success, -ve on error
 */
int32_t hal_disp_drv_register(disp_drv_t *driver);

/*
 * Set Active Display by ID
 *
 * @param id Display ID to set as active
 * @return 0 on success, -ve on error
 */
int32_t hal_disp_set_active(int32_t id);

/**
 * Get Active Display
 *
 * @return Active ID of display on success else -ve on error
 */
int32_t hal_disp_get_active(void);

/**
 * Following functions are called internally from lvgl core
 */

/**
 * Initialize your display here
 */
void hal_disp_init(void);

/**
 * Fill a rectangular area with a color
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color fill color
 */
void hal_disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color);

/**
 * Put a color map to a rectangular area
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
void hal_disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const color_t * color_p);

#if DISP_HW_ACC != 0
/**
 * Copy pixels to destination memory using opacity with GPU (hardware accelerator)
 * @param dest a memory address. Copy 'src' here.
 * @param src pointer to pixel map. Copy it to 'dest'.
 * @param length number of pixels in 'src'
 * @param opa opacity (0, OPA_TRANSP: transparent ... 255, OPA_COVER, fully cover)
 */
void hal_disp_color_cpy(color_t * dest, const color_t * src, uint32_t length, opa_t opa);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
