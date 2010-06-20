#ifndef h_ca_tools_h
#define h_ca_tools_h

#include "oh/external/external.h"

typedef unsigned long (*h_ca_select_initial_rule_f)();
typedef unsigned long (*h_ca_select_initial_value_f)();

h_container_array_t *h_ca_create_initial_state(unsigned long cell_count,
    unsigned long time_steps, h_ca_select_initial_rule_f select_initial_rule,
    h_ca_select_initial_value_f select_initial_value);

h_container_array_t *h_ca_create_initial_state_from_bitarray
(h_core_bitarray_t *bitarray);

h_container_array_t *h_ca_create_initial_state_salt_and_pepper_binary
(unsigned long cell_count, unsigned long time_steps);

h_container_array_t *h_ca_create_initial_state_single_cell_binary
(unsigned long cell_count, unsigned long time_steps);

h_container_array_t *h_ca_create_initial_state_single_cell_k3
(unsigned long cell_count);

unsigned long h_ca_select_rule_0();

unsigned long h_ca_select_value_0();

unsigned long h_ca_select_value_salt_and_pepper();

#endif
