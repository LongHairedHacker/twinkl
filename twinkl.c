#include <stdint.h>

#include "config.h"
#include "twinkl.h"


uint8_t twinkl_channels[TWINKL_LEVEL_COUNT][TWINKL_CHANNEL_COUNT];
uint8_t twinkl_masks[TWINKL_LEVEL_COUNT][TWINKL_MASK_BYTES];

uint8_t twinkl_has_changed;


void twinkl_init() {
	memset(twinkl_channels, 0, TWINKL_LEVEL_COUNT * TWINKL_CHANNEL_COUNT);
	memset(twinkl_masks, 0, TWINKL_LEVEL_COUNT * TWINKL_MASK_BYTES);

	twinkl_has_changed = 0;
}


void twinkl_process_message(struct twinkl_message *msg) {
	if(msg->priority < TWINKL_LEVEL_COUNT) {
		memcpy(twinkl_channels[msg->priority], msg->values, TWINKL_CHANNEL_COUNT);
		memcpy(twinkl_masks[msg->priority], msg->mask, TWINKL_MASK_BYTES);

		twinkl_has_changed = 1;
	}
}


uint8_t twinkl_has_changes() {
	return twinkl_has_changed;
}


uint8_t get_mask_bit(uint8_t level, uint16_t channel) {
	if(level >= TWINKL_LEVEL_COUNT && channel >= TWINKL_CHANNEL_COUNT) {
		return 0;
	}

	uint16_t byte = channel / 8;
	uint8_t bit = channel % 8;
	
	if((twinkl_masks[level][byte] & (1 << bit)) != 0) {
		return 1;
	}
	else {
		return 0;
	}
}


void twinkl_render(uint8_t *channels) {
	uint16_t chan;
	uint8_t level;

	for(chan = 0; chan < TWINKL_CHANNEL_COUNT; chan++) {
		for(level = 0; level < TWINKL_LEVEL_COUNT; level++) {
			if(get_mask_bit(level,chan)) {
				channels[chan] = twinkl_channels[level][chan];
				break;
			}
		}
	}

	twinkl_has_changed = 0;
}

