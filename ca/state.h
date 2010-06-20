#ifndef h_ca_state_h
#define h_ca_state_h

#include "oh/ca/cell.h"

struct h_ca_state_t;
typedef struct h_ca_state_t h_ca_state_t;

int h_ca_state_compare(void *state_object_a, void *state_object_b);

void *h_ca_state_copy(void *state_object);

h_ca_state_t *h_ca_state_create(unsigned long cell_count);

h_ca_state_t *h_ca_state_create_from_cells(h_ca_t *cells,
    unsigned long cell_count);

void h_ca_state_destroy(void *state_object);

char *h_ca_state_get_as_string(void *state_object);

h_ca_t *h_ca_state_get_cell(h_ca_state_t *state,
    unsigned long cell_index);

unsigned long h_ca_state_get_cell_count(h_ca_state_t *state);

unsigned long h_ca_state_get_cell_rule(h_ca_state_t *state,
    unsigned long cell_index);

unsigned long h_ca_state_get_cell_value(h_ca_state_t *state,
    unsigned long cell_index);

void h_ca_state_print(h_ca_state_t *state);

void h_ca_state_set_cell(h_ca_state_t *state, unsigned long cell_index,
    h_ca_t *cell);

void h_ca_state_set_cell_rule(h_ca_state_t *state,
    unsigned long cell_index, unsigned long h_ca_rule);

void h_ca_state_set_cell_value(h_ca_state_t *state,
    unsigned long cell_index, unsigned long h_ca_value);

#endif
