/**
 * @file eth.c
 * 
 */

#include "eth.h"

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
void eth_init(void)
{
   
}

/**
 * Connect to network
 * @param cp a function to call when ready or on error
 * @return ETH_STATE_BUSY or ETH_STATE_OK
 */
eth_state_t eth_netw_con(eth_cb_t cb)
{
    return ETH_STATE_OK;
}

/**
 * Leave ETH network
 * @param cp a function to call when ready or on error
 * @return ETH_STATE_BUSY or ETH_STATE_OK
 */
eth_state_t eth_netw_leave(eth_cb_t cb)
{
    return ETH_STATE_OK;
}

/**
 * Connect to a TCP server using a given IP and port
 * @param ip IP address of the server
 * @param port destination port on IP
 * @param cp a function to cally when ready or on error
 * @return ETH_STATE_BUSY or ETH_STATE_OK
 */
eth_state_t eth_tcp_con(const char * ip, const char * port, eth_cb_t cb)
{
    return ETH_STATE_OK;
}

/**
 * Leave the TCP server
 * @param cp a function to call when ready or on error
 * @return ETH_STATE_BUSY or ETH_STATE_OK
 */
eth_state_t eth_tcp_leave(eth_cb_t cb)
{
    return ETH_STATE_OK;
}


eth_state_t eth_tcp_transf(const void * data, uint16_t len, eth_cb_t cb)
{
    return ETH_STATE_OK;
}

bool eth_busy(void)
{
    return false;
}


/**********************
 *   STATIC FUNCTIONS
 **********************/
