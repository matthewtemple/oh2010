#ifndef oh_box_coordinate_h
#define oh_box_coordinate_h

#include "oh/external/external.h"

struct oh_box_coordinate_t {
  unsigned short x;
  unsigned short y;
  unsigned short z;
};
typedef struct oh_box_coordinate_t oh_box_coordinate_t;

void oh_box_coordinate_copy(oh_box_coordinate_t *destination,
    oh_box_coordinate_t *source);

void oh_box_coordinate_free(oh_box_coordinate_t *coordinate);

void oh_box_coordinate_init_with_coordinate(oh_box_coordinate_t *coordinate,
    oh_box_coordinate_t *initial_coordinate);

void oh_box_coordinate_init_with_random(oh_box_coordinate_t *coordinate,
    oh_box_coordinate_t *dimension_coordinate);

void oh_box_coordinate_init_with_xyz(oh_box_coordinate_t *coordinate,
    unsigned short x, unsigned short y, unsigned short z);

#endif
