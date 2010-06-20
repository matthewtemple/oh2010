#ifndef oh_box_testmod_h
#define oh_box_testmod_h

#include "oh/external/external.h"

struct oh_box_testmod_t;
typedef struct oh_box_testmod_t oh_box_testmod_t;

oh_box_testmod_t *oh_box_testmod_create();

void oh_box_testmod_destroy(void *testmod_void);

#endif
