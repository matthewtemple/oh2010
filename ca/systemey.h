#ifndef h_ca_systemey_h
#define h_ca_systemey_h

#include "oh/ca/cell.h"
#include "oh/ca/declarations.h"
#include "oh/external/external.h"

#define H_CA_NO_CREATE_CONTEXT_FUNCTION NULL
#define H_CA_NO_DESTROY_CONTEXT_FUNCTION NULL
#define H_CA_NO_GET_CELL_COLOR_FUNCTION NULL
#define H_CA_NO_END_TIME_STEP_FUNCTION NULL
#define H_CA_NO_START_TIME_STEP_FUNCTION NULL

typedef h_ca_t (*h_ca_system_calculate_new_cell_state_f)
(h_ca_system_t *system, unsigned long cell_index);

typedef void *(*h_ca_system_create_context_f)(void *name_object);

typedef void (*h_ca_system_destroy_context_f)(void *context_object);

typedef void (*h_ca_system_end_time_step_f)(h_ca_system_t *system);

typedef void (*h_ca_system_get_cell_color_f)(h_ca_t *cell,
    h_core_color_t *color);

typedef unsigned long (*h_ca_system_get_relative_cell_index_f)
(h_ca_system_t *system, unsigned long cell_index,
    unsigned long relationship);

typedef void (*h_ca_system_start_time_step_f)(h_ca_system_t *system);

struct h_ca_systemey_t {
  void *name_object;

  h_ca_system_calculate_new_cell_state_f calculate_new_cell_state;
  h_ca_system_create_context_f create_context;
  h_ca_system_destroy_context_f destroy_context;
  h_ca_system_end_time_step_f end_time_step;
  h_ca_system_get_cell_color_f get_cell_color;
  h_ca_system_get_relative_cell_index_f get_relative_cell_index;
  h_ca_system_start_time_step_f start_time_step;
};
typedef struct h_ca_systemey_t h_ca_systemey_t;

void h_ca_systemey_init(h_ca_systemey_t *systemey,
    void *name_object,
    h_ca_system_calculate_new_cell_state_f calculate_new_cell_state,
    h_ca_system_create_context_f create_context,
    h_ca_system_destroy_context_f destroy_context,
    h_ca_system_end_time_step_f end_time_step,
    h_ca_system_get_cell_color_f get_cell_color,
    h_ca_system_get_relative_cell_index_f get_relative_cell_index,
    h_ca_system_start_time_step_f start_time_step);

#endif
