#ifndef h_ca_fly_h
#define h_ca_fly_h

#include "oh/ca/system.h"

h_ca_t h_ca_fly_calculate_new_cell_state(h_ca_system_t *system,
    unsigned long cell_index);

unsigned long h_ca_fly_get_relative_cell_index(h_ca_system_t *system,
    unsigned long cell_index, unsigned long relationship);

void h_ca_fly_init_systemey(h_ca_systemey_t *systemey, void *name_object);

#endif
