/**
 * @file eth.h
 * 
 */

#ifndef ETH_H
#define ETH_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum 
{
    ETH_STATE_OK = 0,
    ETH_STATE_BUSY,
    ETH_STATE_ERROR,
    ETH_STATE_NUM,
    ETH_STATE_INV = 0xFF
}eth_state_t;

/*Callback after operations: state + string (result, error text)*/
typedef void (*eth_cb_t)(eth_state_t, const char *); 

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 
/**
 * Initialize Ethernet module
 */ 
void eth_init(void);

/**
 * Send data via TCP and wait for answer. The IP and port has to be opened by the driver 
 * @param data data to send
 * @param len length of data in bytes
 * @param cb a function call when ready or on error
 */
eth_state_t eth_tcp_transf(const void * data, uint16_t len, eth_cb_t cb);

/**
 * Check the Ethernet is busy or not
 * @return false:idle, true: busy
 */
bool eth_busy(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
