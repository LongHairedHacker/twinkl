#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <stdint.h>
#include <string.h>

#include "config.h"

struct twinkl_message {

	// Channel values from 0 to 255
	uint8_t values[TWINKL_CHANNEL_COUNT];

	/*
	 * Mask bits
	 *
	 * If the value of channel X should be set,
	 * set bit X % 8 in byte X / 8.
     */
	uint8_t mask[TWINKL_MASK_BYTES];

	// Priority of this message.
	uint8_t priority;
};


/*
 * Static helper functions for messages
 */ 
static inline void twinkl_init_message(struct twinkl_message *msg) {
	memset(msg->values, 0, TWINKL_CHANNEL_COUNT);
	memset(msg->mask, 0, TWINKL_MASK_BYTES);
	msg->priority = 0;
}

static inline void twinkl_set_value(struct twinkl_message *msg, uint16_t chan, uint8_t value) {
	if(chan < TWINKL_CHANNEL_COUNT) {
		msg->values[chan] = value;

		uint16_t byte = chan / 8;
		uint8_t bit = chan % 8;
		msg->mask[byte] |= (1 << bit);
	}
}

static inline void twinkl_unset_value(struct twinkl_message *msg, uint16_t chan) {
	if(chan < TWINKL_CHANNEL_COUNT) {
		msg->values[chan] = 0;

		uint16_t byte = chan / 8;
		uint8_t bit = chan % 8;
		msg->mask[byte] &= ~(1 << bit);
	}
}

static inline void twinkl_set_priority(struct twinkl_message *msg, uint8_t priority) {
	if(priority < TWINKL_LEVEL_COUNT) {
		msg->priority = priority;
	}
}

#endif
