#include "oh/box/coordinate.h"

void oh_box_coordinate_copy(oh_box_coordinate_t *destination,
    oh_box_coordinate_t *source)
{
  assert(destination);
  assert(source);

  destination->x = source->x;
  destination->y = source->y;
  destination->z = source->z;
}

void oh_box_coordinate_free(oh_box_coordinate_t *coordinate) {}

void oh_box_coordinate_init_with_coordinate(oh_box_coordinate_t *coordinate,
    oh_box_coordinate_t *initial_coordinate)
{
  assert(coordinate);

  coordinate->x = initial_coordinate->x;
  coordinate->y = initial_coordinate->y;
  coordinate->z = initial_coordinate->z;
}

void oh_box_coordinate_init_with_random(oh_box_coordinate_t *coordinate,
    oh_box_coordinate_t *dimension_coordinate)
{
  assert(coordinate);
  assert(dimension_coordinate);

  coordinate->x = random() % dimension_coordinate->x;
  coordinate->y = random() % dimension_coordinate->y;
  coordinate->z = random() % dimension_coordinate->z;
}

void oh_box_coordinate_init_with_xyz(oh_box_coordinate_t *coordinate,
    unsigned short x, unsigned short y, unsigned short z)
{
  assert(coordinate);

  coordinate->x = x;
  coordinate->y = y;
  coordinate->z = z;
}
