#ifndef h_ca_clear_h
#define h_ca_clear_h

#include "oh/ca/system.h"
#include "oh/external/external.h"

h_ca_t h_ca_clear_calculate_new_cell_state(h_ca_system_t *system,
    unsigned long cell_index);

void *h_ca_clear_create_context(void *name_object);

unsigned long h_ca_clear_get_relative_cell_index(h_ca_system_t *system,
    unsigned long cell_index, unsigned long relationship);

void h_ca_clear_destroy_context(void *context_object);

void h_ca_clear_end_time_step(h_ca_system_t *system);

void h_ca_clear_init_systemey(h_ca_systemey_t *systemey,
    void *name_object);

void h_ca_clear_start_time_step(h_ca_system_t *system);

#endif
