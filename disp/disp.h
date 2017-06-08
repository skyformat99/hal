/**
 * @file disp.h
 * 
 */

#ifndef DISP_H
#define DISP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "../hal.h"

#define HAL_PATH(x) ../x/gfx/color.h
#define STR(x) _STR(x)
#define _STR(x)   #x

#include  STR(HAL_PATH(HAL_MISC_INCLUDE))

/*********************
 *      DEFINES
 *********************/
/*TODO define your screen size*/
#define TFT_HOR_RES 240
#define TFT_VER_RES 320

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 
/**
 * Initialize your display here
 */
void disp_init(void);

/**
 * Fill a rectangular area with a color
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color fill color
 */
void disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color);

/**
 * Put a color map to a rectangular area
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
void disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const color_t * color_p);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
