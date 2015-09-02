#ifndef _CONFIG_H_
#define _CONFIG_H_

/*
 * Here be Configuration
 */

// Number of channels
#define TWINKL_CHANNEL_COUNT 512

// Number of priority levels
#define TWINKL_LEVEL_COUNT 8


/*
 * Only automagic below this point
 */

// ceil(TWINKL_CHANNEL_COUNT / 8)
#define TWINKL_MASK_BYTES ((TWINKL_CHANNEL_COUNT + 7) / 8)


#endif
