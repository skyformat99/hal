/**
 * @file gsm.h
 * 
 */

#ifndef GSM_H
#define GSM_H

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
    GSM_STATE_OK = 0,
    GSM_STATE_BUSY,
    GSM_STATE_ERROR,
    GSM_STATE_NUM,
    GSM_STATE_INV = 0xFF
}gsm_state_t;

/*Callback after operations: state + string (result, error text)*/
typedef void (*gsm_cb_t)(gsm_state_t, const char *); 

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 
/**
 * Initialize the GSM module
 */ 
void gsm_init(void);

/**
 * Connect to a GSM network using a given APN
 * @param apn the APN
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
gsm_state_t gsm_netw_con(const char * apn, gsm_cb_t cb);

/**
 * Leave GSM network
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
gsm_state_t gsm_netw_leave(gsm_cb_t cb);

/**
 * Connect to a TCP server using a given IP and port
 * @param ip IP address of the server
 * @param port destination port on IP
 * @param cp a function to cally when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
gsm_state_t gsm_tcp_con(const char * ip, const char * port, gsm_cb_t cb);

/**
 * Leave the TCP server
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
gsm_state_t gsm_tcp_leave(gsm_cb_t cb);

/**
 * Send data via TCP and wait for answer. 
 * @param data data to send
 * @param len length of data in bytes
 * @param cb a function call when ready or on error
 */
gsm_state_t gsm_tcp_transf(const void * data, uint16_t len, gsm_cb_t cb);

/**
 * Check the GSM is busy or not
 * @return false:idle, true: busy
 */
bool gsm_busy(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
