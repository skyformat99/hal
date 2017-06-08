/**
 * @file systick.h
 * Provide access to the system tick with 1 millisecond resolution
 */

#ifndef SYSTICK_H
#define SYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 
/**
 * Get the elapsed milliseconds since start up
 * @return the elapsed milliseconds
 */
uint32_t systick_get(void);


/**
 * Get the elapsed milliseconds science a previous time stamp
 * @param prev_tick a previous time stamp from 'systick_get'
 * @return the elapsed milliseconds since 'prev_tick'
 */
uint32_t systick_elaps(uint32_t prev_tick);

/**
 * Add a callback function to the systick interrupt (optional, used by a few spwial misc. library modules)
 * @param cb a function pointer
 * @return true: 'cb' added to the systick callbacks, false: 'cb' not added
 */
bool systick_add_cb(void (*cb) (void));

/**
 * Remove a callback function from the systick callbacks (optional, used by a few spwial misc. library modules)
 * @param cb a function pointer (added with 'systick_add_cb')
 */
void systick_rem_cb(void (*cb) (void));

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
