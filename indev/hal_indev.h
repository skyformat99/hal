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

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum _indev_type_e {
    INDEV_TYPE_TOUCH,
    INDEV_TYPE_POINTER,
    INDEV_TYPE_KEYPAD,
} indev_type_e;

typedef enum _pointer_button_e {
    POINTER_BUTTON_NONE,
    POINTER_BUTTON_LEFT,
    POINTER_BUTTON_RIGHT,
    POINTER_BUTTON_MIDDLE,
} pointer_button_e;

typedef enum _keypad_state_e {
    KEYPAD_STATE_KEYUP,
    KEYPAD_STATE_KEYDOWN,
    KEYPAD_STATE_REPEAT,
} keypad_state_e;

typedef struct _indev_touch_t {
    int16_t x;
    int16_t y;
    int32_t longpress; /* 1 if its a long press, 0 short press */
} indev_touch_e;

typedef struct _indev_pointer_t {
    int16_t x;
    int16_t y;
    pointer_button_e button;
} indev_pointer_t;

typedef struct _indev_keypad_t {
    int32_t code;
    keypad_state_e state;
} indev_keypad_t;

typedef union _indev_date_t {
    indev_touch_t touch;
    indev_pointer_t pointer;
    indev_keypad_t keypad;
} indev_data_t;

typedef struct _indev_t {
    indev_type_e type;
    indev_data_t data;
} indev_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
/**
 * User Input Device driver HAL interface
 */

/**
 * Input Device Driver struction to be registered with HAL
 */
typedef struct _indev_drv_t {
    const char *name;
    indev_type_e type;
    void (*init)(void);
} indev_drv_t;

/**
 * Register Input Device driver
 *
 * @param driver Input Device driver structure
 * @return 0 on success, -ve on error
 */
int32_t hal_indev_drv_register(indev_drv_t *driver);

/**
 * Input device data report from driver
 * 
 * @description Input device driver must call this function to report new data
 *              from input device.
 *              TODO: Function is not thread safe
 * @param data Input device data
 * @return 0 on success, -ve on error
 */
int32_t hal_indev_report(indev_t *data);

/**
 * Enable device by type
 *
 * @description Enable all input device defined by type
 *
 * @param type Input device type
 */
void hal_indev_enable(indev_type_e type);

/**
 * Disable device by type
 *
 * @description Disable all input device defined by type
 *
 * @param type Input device type
 */
void hal_indev_disable(indev_type_e type);

/**
 * Following functions are called internally from lvgl core
 */

/**
 * Initialize your input devices here
 */
void hal_indev_init(void);

/**
 * Read an input data reported by Input devices
 * This function must be called multiple times till all the reports
 * are read
 *
 * @param data Pointer to indev_t where data from input device will be stored
 *
 * @return 0 on success, -ve on error
 */
int32_t hal_indev_get(indev_t *data);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
