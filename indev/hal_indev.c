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
typedef struct _indev_drv_node_t {
    indev_drv_t *driver;
    int32_t disable;
    struct _indev_drv_node_t *next;
} indev_drv_node_t;

static indev_drv_node_t *indev_drv_list = NULL;

/**********************
 *  STATIC VARIABLES
 **********************/
static ll_dsc_t indev_reports;
static int32_t indev_max_reports = 10;  /*TODO FIFO might better then linked list? (less overhead)*/
static int32_t indev_report_count = 0;

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
int32_t hal_indev_drv_register(indev_drv_t *driver)
{
    indev_drv_node_t *node;

    node = dm_alloc(sizeof(indev_drv_node_t));
    if (!node)
        return -HAL_ERR_NOMEM;

    node->driver = driver;
    node->disable = 0;
    node->next = NULL;

    if (indev_drv_list == NULL) {
        indev_drv_list = node;
    } else {
        indev_drv_node_t *last = indev_drv_list;
        while (last->next)
            last = last->next;

        last->next = node;
    }

    return HAL_OK;
}

/**
 * Input device data report from driver
 * 
 * @description Input device driver must call this function to report new data
 *              from input device.
 *              TODO: Function is not thread safe
 * @param data Input device data
 * @return 0 on success, -ve on error
 */
int32_t hal_indev_report(indev_t *data)
{
    indev_t *report;

    if (indev_report_count >= indev_max_reports)
        return HAL_ERR_LISTFULL;

    report = ll_ins_tail(&indev_reports);

    memcpy(report, data, sizeof(indev_t));
    indev_report_count++;

    return HAL_OK;
}

/**
 * Enable device by type
 *
 * @description Enable all input device defined by type
 *
 * @param type Input device type
 */
void hal_indev_enable(indev_type_e type)
{
    indev_drv_node_t *node = indev_drv_list;
    indev_drv_t *drv;

    while (node) {
        if (node->driver->type == type)
            node->disable = 0;
        node = node->next;
    }
}

/**
 * Disable device by type
 *
 * @description Disable all input device defined by type
 *
 * @param type Input device type
 */
void hal_indev_disable(indev_type_e type)
{
    indev_drv_node_t *node = indev_drv_list;
    indev_drv_t *drv;

    while (node) {
        if (node->driver->type == type)
            node->disable = 1;
        node = node->next;
    }
}

/**
 * Initialize registered input device drivers
 *
 * @param Maximum allowed reports (default 10)
 */
void hal_indev_init(int32_t max_reports)
{
    indev_drv_node_t *node = indev_drv_list;
    indev_drv_t *drv;

    while (node) {
        drv = node->driver;
        if (drv->init)
            drv->init();
        node = node->next;
    }

    /* Initialize LL to store data reports from driver */
    ll_init(&indev_reports, sizeof(indev_t));
    indev_max_reports = max_reports ? max_reports : 10;
}

/**
 * Read an input data reported by Input devices
 * This function must be called multiple times till all the reports
 * are read
 *
 * @param data Pointer to indev_t where data from input device will be stored
 *
 * @return 0 on success, -ve on error
 */
int32_t hal_indev_get(indev_t *data)
{
    indev_t *report = ll_get_head(&indev_reports);

    if (!report)
        return -HAL_ERR_LISTEMPTY;

    memcpy(data, report, sizeof(indev_t));
    ll_rem(&indev_reports, report);
    dm_free(report);
    indev_report_count--;

    return HAL_OK;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
