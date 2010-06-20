#ifndef oh_box_system_h
#define oh_box_system_h

#include "oh/box/coordinate.h"
#include "oh/external/external.h"

typedef void * (*oh_box_object_get_cell_f)(void *object);

typedef void (*oh_box_object_set_cell_f)(void *object, void *cell);

struct oh_box_system_t;
typedef struct oh_box_system_t oh_box_system_t;

void oh_box_system_add(oh_box_system_t *system,
    oh_box_coordinate_t *coordinate, void *object);

void oh_box_system_add_random(oh_box_system_t *system, void *object);

oh_box_system_t *oh_box_system_create
(oh_box_coordinate_t *dimension_coordinate,
    oh_box_object_get_cell_f get_cell, oh_box_object_set_cell_f set_cell,
    h_core_compare_f compare_objects, h_core_copy_f copy_object,
    h_core_destroy_f destroy_object, h_audit_log_t *log);

void oh_box_system_destroy(oh_box_system_t *system);

void *oh_box_system_find(oh_box_system_t *system,
    oh_box_coordinate_t *coordinate);

void *oh_box_system_find_random(oh_box_system_t *system);

void *oh_box_system_find_relative(oh_box_system_t *system, void *object,
    oh_box_coordinate_t *relative_coordinate);

unsigned long oh_box_system_get_volume(oh_box_system_t *system);

void *oh_box_system_iterate_next(oh_box_system_t *system);

void oh_box_system_iterate_start(oh_box_system_t *system);

void oh_box_system_move_absolute(oh_box_system_t *system, void *object,
    oh_box_coordinate_t *destination_coordinate);

void oh_box_system_move_relative(oh_box_system_t *system, void *object,
    oh_box_coordinate_t *relative_coordinate);

void oh_box_system_remove(oh_box_system_t *system,
    oh_box_coordinate_t *coordinate);

void oh_box_system_replace(oh_box_system_t *system, void *destination_object,
    void *source_object);

void oh_box_system_replace_random(oh_box_system_t *system, void *object);

void oh_box_system_swap(oh_box_system_t *system, void *object_a,
    void *object_b);

#endif
