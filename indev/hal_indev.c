/**
 * @file hal_indev.c
 *
 * @description Input device HAL interface
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "hal_indev.h"
#include "misc/mem/linked_list.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_indev_t *indev_list = NULL;

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Register Input Device driver
 *
 * @param driver Input Device driver structure
 * @return 0 on success, -ve on error
 */
int32_t lv_hal_indev_drv_register(lv_hal_indev_drv_t *driver)
{
    lv_indev_t *node;

    node = dm_alloc(sizeof(lv_indev_t));
    if (!node)
        return -HAL_ERR_NOMEM;

    memcpy(&node->drv, driver, sizeof(lv_hal_indev_drv_t));
    node->disable = 0;

    node->next = NULL;

    if (indev_list == NULL) {
        indev_list = node;
    } else {
        lv_indev_t *last = indev_list;
        while (last->next)
            last = last->next;

        last->next = node;
    }

    return HAL_OK;
}

/**
 * Enable device by type
 *
 * @description Enable all input device defined by type
 *
 * @param type Input device type
 */
void lv_hal_indev_enable(lv_hal_indev_type_t type, bool enable)
{
    lv_indev_t *node = indev_list;

    while (node) {
        if (node->drv.type == type) node->disable = enable == false ? 1 : 0;
        node = node->next;
    }
}

lv_indev_t * lv_hal_indev_next(lv_indev_t * drv)
{

    if(drv == NULL) {
        return &indev_list[0];
    } else {
        if(indev_list->next == NULL) return NULL;
        else return indev_list->next;
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
