
/**
 * @file hal_disp.c
 *
 * @description HAL layer for display driver
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stddef.h>
#include "hal_disp.h"
#include "misc/mem/dyn_mem.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
typedef struct _disp_drv_node_t {
    disp_drv_t *driver;
    struct _disp_drv_node_t *next;
} disp_drv_node_t;

static disp_drv_node_t *disp_drv_list = NULL;
static disp_drv_t *active;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Register Display driver
 *
 * @param driver Display driver structure
 * @return 0 on success, -ve on error
 */
int32_t hal_disp_drv_register(disp_drv_t *driver)
{
    disp_drv_node_t *node;

    node = dm_alloc(sizeof(disp_drv_node_t));
    if (!node)
        return -HAL_ERR_NOMEM;

    node->driver = driver;
    node->next = NULL;

    if (disp_drv_list == NULL) {
        disp_drv_list = node;

        /* Set first display as active by default */
        active = driver;
    } else {
        disp_drv_node_t *last = disp_drv_list;
        while (last->next)
            last = last->next;

        last->next = node;
    }

    return HAL_OK;
}

/*
 * Set Active Display by ID
 *
 * @param id Display ID to set as active
 * @return 0 on success, -ve on error
 */
int32_t hal_disp_set_active(int32_t id)
{
    int32_t i;
    disp_drv_node_t *node;

    if (id < 0)
        return -HAL_ERR_INVAL;

    i = 0;
    node = disp_drv_list;
    while (node) {
        if (i == id) {
            active = node->driver;
            break;
        }
        node = node->next;
        i++;
    }

    return node ? HAL_OK : -HAL_ERR_NODEV;
}

/**
 * Get Active Display
 *
 * @return Active ID of display on success else -ve on error
 */
int32_t hal_disp_get_active(void)
{
    int32_t i;
    disp_drv_node_t *node;

    i = 0;
    node = disp_drv_list;
    while (node) {
        if (node->driver == active)
            break;
        node = node->next;
        i++;
    }

    return node ? i : -HAL_ERR_NODEV;
}

/**
 * Following HAL Functions are called from lvgl Library
 */


/**
 * Fill a rectangular area with a color
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color fill color
 */
void hal_disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color)
{
    if (active && active->fill)
        active->fill(x1, y1, x2, y2, color);
}

/**
 * Put a color map to a rectangular area
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
void hal_disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const color_t * color_p)
{
    if (active && active->map)
        active->map(x1, y1, x2, y2, color_p);
}

#if DISP_HW_ACC != 0

/**
 * Copy pixels to destination memory using opacity with GPU (hardware accelerator)
 * @param dest a memory address. Copy 'src' here.
 * @param src pointer to pixel map. Copy it to 'dest'.
 * @param length number of pixels in 'src'
 * @param opa opacity (0, OPA_TRANSP: transparent ... 255, OPA_COVER, fully cover)
 */
void hal_disp_color_cpy(color_t * dest, const color_t * src, uint32_t length, opa_t opa)
{
    if (active && active->color_cpy)
        active->color_cpy(x1, y1, x2, y2, color_p);
}

#endif
/**********************
 *   STATIC FUNCTIONS
 **********************/

