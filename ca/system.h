#ifndef h_ca_system_h
#define h_ca_system_h

#include "oh/ca/state.h"
#include "oh/ca/systemey.h"

h_ca_system_t *h_ca_system_create
(h_container_array_t *initial_state_history,
    unsigned long initial_time_step_count, h_ca_systemey_t *systemey);

void h_ca_system_default_get_cell_color(h_ca_t *cell,
    h_core_color_t *color);

void h_ca_system_destroy(h_ca_system_t *system);

unsigned long h_ca_system_get_age_in_time_steps(h_ca_system_t *system);

unsigned long h_ca_system_get_cell_count(h_ca_system_t *system);

h_ca_t *h_ca_system_get_cell(h_ca_system_t *system,
    unsigned long time_step, unsigned long cell_index);

void h_ca_system_get_cell_color_binary(h_ca_t *cell,
    h_core_color_t *color);

void *h_ca_system_get_context(h_ca_system_t *system);

h_ca_t *h_ca_system_get_current_cell(h_ca_system_t *system,
    unsigned long cell_index);

h_ca_state_t *h_ca_system_get_current_state(h_ca_system_t *system);

void *h_ca_system_get_name(h_ca_system_t *system);

h_ca_t *h_ca_system_get_relative_cell(h_ca_system_t *system,
    long relative_time_step, unsigned long cell_index);

h_ca_state_t *h_ca_system_get_state(h_ca_system_t *system,
    unsigned long time_step);

void h_ca_system_run(h_ca_system_t *system, h_core_run_t *run);

h_core_bool_t h_ca_system_save_snapshot_jpeg(h_ca_system_t *system,
    char *filename);

h_core_bool_t h_ca_system_save_snapshot_text(h_ca_system_t *system,
    char *filename);

void h_ca_system_set_cell(h_ca_system_t *system, unsigned long time_step,
    unsigned long cell_index, h_ca_t *cell);

void h_ca_system_set_current_cell(h_ca_system_t *system,
    unsigned long cell_index, h_ca_t *cell);

void h_ca_system_set_random_seed(h_ca_system_t *system,
    unsigned long seed);

void h_ca_system_set_relative_cell(h_ca_system_t *system,
    long relative_time_step, unsigned long cell_index, h_ca_t *cell);

#endif
