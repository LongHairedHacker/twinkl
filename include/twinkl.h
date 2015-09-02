#ifndef _TWINKL_H_
#define _TWINKL_H_

#include <stdint.h>

#include "message.h"

void twinkl_init(void);

void twinkl_process_message(struct twinkl_message* msg);

uint8_t twinkl_has_changes(void);

void twinkl_render(uint8_t *channels);


#endif
