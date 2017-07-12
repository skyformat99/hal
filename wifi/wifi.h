/**
 * @file wifi.h
 * 
 */

#ifndef WIFI_H
#define WIFI_H

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
    WIFI_STATE_OK = 0,
    WIFI_STATE_BUSY,
    WIFI_STATE_ERROR,
    WIFI_STATE_NUM,
    WIFI_STATE_INV = 0xFF
}wifi_state_t;

/*Callback after operations: state + string (result, error text)*/
typedef void (*wifi_cb_t)(wifi_state_t, const char *); 

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 
/**
 * Initialize the GSM module
 */ 
void wifi_init(void);

/**
 * List the visible WiFi networks
 * @param cp a function to call when ready or on error (Continuously give the SSID and "" at the end)
 */ 
wifi_state_t wifi_netw_list(wifi_cb_t cb);

/**
 * Connect to a GSM network using a given APN
 * @param apn the APN
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
wifi_state_t wifi_netw_con(const char * ssid, const char * pwd, wifi_cb_t cb);

/**
 * Leave GSM network
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
wifi_state_t wifi_netw_leave(wifi_cb_t cb);

/**
 * Get the SSID of the current network
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
wifi_state_t wifi_netw_get_ssid(wifi_cb_t cb);

/**
 * Connect to a TCP server using a given IP and port
 * @param ip IP address of the server
 * @param port destination port on IP
 * @param cp a function to cally when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
wifi_state_t wifi_tcp_con(const char * ip, const char * port, wifi_cb_t cb);

/**
 * Leave the TCP server
 * @param cp a function to call when ready or on error
 * @return GSM_STATE_BUSY or GSM_STATE_OK
 */
wifi_state_t wifi_tcp_leave(wifi_cb_t cb);

/**
 * Send data via TCP and wait for answer. 
 * @param data data to send
 * @param len length of data in bytes
 * @param cb a function call when ready or on error
 */
wifi_state_t wifi_tcp_transf(const void * data, uint16_t len, wifi_cb_t cb);

/**
 * Check the GSM is busy or not
 * @return false:idle, true: busy
 */
bool wifi_busy(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
