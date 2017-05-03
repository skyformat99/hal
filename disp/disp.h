/**
 * @file disp.h
 * 
 */

#ifndef DISP_H
#define DISP_H

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "misc/gfx/color.h"

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
void disp_init(void);
void disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color);
void disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t * color_p);

/**********************
 *      MACROS
 **********************/

#endif
