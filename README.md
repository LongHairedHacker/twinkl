twinkl
======

A simple multiclient network protocol for your blinkenlights.




Pseudocode Client
-----------------

```C
#include "twinkl.h"

char twinkl_server[] = "127.0.0.1:1337";

struct twinkl_message msg;

// Initialization (required if msg is on the heap, optional here)
twinkl_init_message(&msg);

twinkl_set_priority(&msg, 0);

twinkl_set_value(&msg, 23, 42);
twinkl_set_value(&msg, 46, 5);
// ... more stuff

// Just send it to your twinkl server somehow
udp_send_stuff(twinkl_server, &msg, sizeof(twinkl_msg));
```



Pseudocode Server
-----------------

```C
#include "twinkl.h"

twinkl_init();

struct twinkl_message msg;

unit8_t buffer[TWINKL_CHANNEL_COUNT];

while(1) {
	while(!twinkl_has_changes()) {
		if(upd_receive_stuff(&msg, sizeof(twinkl_msg))) {
			twinkl_process_message(&msg);
		}
	}

	twinkl_render(buffer);

	update_your_lights(buffer);
}
```

