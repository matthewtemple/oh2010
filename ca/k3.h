#ifndef h_ca_k3_h
#define h_ca_k3_h

#include "oh/ca/system.h"

h_ca_t h_ca_k3_calculate_new_cell_state(h_ca_system_t *system,
    unsigned long cell_index);

void *h_ca_k3_create_context(void *parameter_object);

void h_ca_k3_destroy_context(void *context_object);

void h_ca_k3_get_cell_color(h_ca_t *cell, h_core_color_t *color);

unsigned long h_ca_k3_get_relative_cell_index(h_ca_system_t *system,
    unsigned long cell_index, unsigned long relationship);

void h_ca_k3_init_systemey(h_ca_systemey_t *systemey, void *name_object);

#endif
