/**
 * @file wifi.c
 * 
 */

#include "wifi.h"

/*********************
 *      INCLUDES
 *********************/

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

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
 
/**
 * Initialize the WIFI module
 */ 
void wifi_init(void)
{

}

/**
 * List the visible WiFi networks
 * @param cp a function to call when ready or on error (Continuously give the SSID and "" at the end)
 * @return WIFI_STATE_BUSY or WIFI_STATE_OK
 */ 
wifi_state_t wifi_netw_list(wifi_cb_t cb)
{
    return WIFI_STATE_OK;
}

/**
 * Connect to a WIFI network using a given APN
 * @param apn the APN
 * @param cp a function to call when ready or on error
 * @return WIFI_STATE_BUSY or WIFI_STATE_OK
 */
wifi_state_t wifi_netw_con(const char * ssid, const char * pwd, wifi_cb_t cb)
{
    return WIFI_STATE_OK;
}

/**
 * Leave WIFI network
 * @param cp a function to call when ready or on error
 * @return WIFI_STATE_BUSY or WIFI_STATE_OK
 */
wifi_state_t wifi_netw_leave(wifi_cb_t cb)
{
    return WIFI_STATE_ERROR;
}

/**
 * Get the SSID of the current network
 * @param cp a function to call when ready or on error
 * @return WIFI_STATE_BUSY or WIFI_STATE_OK
 */
wifi_state_t wifi_netw_get_ssid(wifi_cb_t cb)
{
    return WIFI_STATE_OK;
}

/**
 * Connect to a TCP server using a given IP and port
 * @param ip IP address of the server
 * @param port destination port on IP
 * @param cp a function to cally when ready or on error
 * @return WIFI_STATE_BUSY or WIFI_STATE_OK
 */
wifi_state_t wifi_tcp_con(const char * ip, const char * port, wifi_cb_t cb)
{
    return WIFI_STATE_OK;
}

/**
 * Leave the TCP server
 * @param cp a function to call when ready or on error
 * @return WIFI_STATE_BUSY or WIFI_STATE_OK
 */
wifi_state_t wifi_tcp_leave(wifi_cb_t cb)
{
    return WIFI_STATE_OK;
}

/**
 * Send data via TCP and wait for answer. 
 * @param data data to send
 * @param len length of data in bytes
 * @param cb a function call when ready or on error
 */
wifi_state_t wifi_tcp_transf(const void * data, uint16_t len, wifi_cb_t cb)
{
    return WIFI_STATE_OK;
}

/**
 * Check the WIFI is busy or not
 * @return false:idle, true: busy
 */
bool wifi_busy(void)
{
    return false;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
