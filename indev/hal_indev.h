/**
 * @file hal_indev.h
 *
 * @description Input Device HAL interface layer header file
 * 
 */

#ifndef HAL_INDEV_H
#define HAL_INDEV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdint.h>
#include "misc/gfx/area.h"
#include "../hal.h"
#include "../../lv_obj/lv_dispi.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/*Possible input device types*/
typedef enum {
    LV_HAL_INDEV_TYPE_TOUCH,       /*Touch pad*/
    LV_HAL_INDEV_TYPE_POINTER,     /*Mouse or similar pointer device*/
    LV_HAL_INDEV_TYPE_KEYPAD,      /*Keypad or keyboard*/
    LV_HAL_INDEV_TYPE_BUTTON,      /*Hardware button assigned to a point on the screen*/
} lv_hal_indev_type_t;

/*State for input devices*/
typedef enum {
    LV_HAL_INDEV_STATE_PRESS,
    LV_HAL_INDEV_STATE_RELEASE
}lv_hal_indev_state_t;

/*Data read from an input device.  */
typedef struct {
    union {
        point_t point;  /*For INDEV_TYPE_TOUCH, INDEV_TYPE_POINTER, INDEV_TYPE_BUTTON*/
        uint32_t key;   /*For INDEV_TYPE_BUTTON*/
    };
    lv_hal_indev_state_t state;
}lv_hal_indev_data_t;

/*Initialized by the user and registered by 'lv_hal_indev_drv_register'*/
typedef struct {
    const char * name;                              /*Input device name*/
    lv_hal_indev_type_t type;                       /*Input device type*/
    bool (*get_data)(lv_hal_indev_data_t * data);   /*Function pointer to read data. Return 'true' if there is still data to be read (buffered)*/
}lv_hal_indev_drv_t;

typedef struct _lv_indev_t {
    lv_hal_indev_drv_t drv;
    lv_dispi_t dispi;
    uint8_t disable :1;
    struct _lv_indev_t *next;
} lv_indev_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Register Input Device driver
 *
 * @param driver Input Device driver structure
 * @return 0 on success, -ve on error
 */
int32_t lv_hal_indev_drv_register(lv_hal_indev_drv_t *driver);

/**
 * @brief Input device driver must call this function to report new data
 *              from input device.
 *              TODO: Function is not thread safe
 * @param data Input device data
 * @return 0 on success, -ve on error
 */
bool lv_hal_indev_get(lv_hal_indev_data_t *data);

/**
 * Enable device by type
 *
 * @description Enable all input device defined by type
 *
 * @param type Input device type
 */
void lv_hal_indev_enable(lv_hal_indev_type_t type, bool enable);

/**
 *
 * @param drv
 * @return
 */
lv_indev_t * lv_hal_indev_next(lv_indev_t * indev);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
