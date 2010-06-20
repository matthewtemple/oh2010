#include "oh/ca/state.h"
#include "oh/external/external.h"

struct h_ca_state_t {
  h_ca_t *cells;
  unsigned long cell_count;
};

int h_ca_state_compare(void *state_object_a, void *state_object_b)
{
  h_core_trace_exit("TODO: implement");
  return 0;
}

void *h_ca_state_copy(void *state_object)
{
  assert(state_object);
  h_ca_state_t *state;
  h_ca_state_t *state_copy;
  unsigned long cells_memory_size;

  state = state_object;
  cells_memory_size = sizeof(h_ca_t) * state->cell_count;

  state_copy = malloc(sizeof *state_copy);
  if (state_copy) {
    state_copy->cell_count = state->cell_count;
    state_copy->cells = malloc(cells_memory_size);
    if (state_copy->cells) {
      memcpy(state_copy->cells, state->cells, cells_memory_size);
    } else {
      h_core_trace("malloc");
    }
  } else {
    h_core_trace("malloc");
  }

  return state_copy;
}

h_ca_state_t *h_ca_state_create(unsigned long cell_count)
{
  h_ca_state_t *state;

  state = malloc(sizeof *state);
  if (state) {
    state->cell_count = cell_count;
    state->cells = malloc(sizeof(h_ca_t) * cell_count);
    if (!state->cells) {
      h_core_trace("malloc");
    }
  } else {
    h_core_trace("malloc");
  }

  return state;
}

h_ca_state_t *h_ca_state_create_from_cells(h_ca_t *cells,
    unsigned long cell_count)
{
  h_ca_state_t *state;
  unsigned long cells_memory_size;

  cells_memory_size = sizeof(h_ca_state_t) * cell_count;

  state = malloc(sizeof *state);
  if (state) {
    state->cell_count = cell_count;
    state->cells = malloc(cells_memory_size);
    if (state->cells) {
      memcpy(state->cells, cells, cells_memory_size);
    } else {
      h_core_trace("malloc");
    }
  } else {
    h_core_trace("malloc");
  }

  return state;
}

void h_ca_state_destroy(void *state_object)
{
  assert(state_object);
  h_ca_state_t *state;

  state = state_object;

  free(state->cells);
  free(state);
}

char *h_ca_state_get_as_string(void *state_object)
{
  assert(state_object);
  h_ca_state_t *state;
  unsigned long each_cell;
  char *string;
  char c;
  h_ca_t *cell;
  unsigned long h_ca_value;
  unsigned long cell_count;

  state = state_object;
  cell_count = state->cell_count;

  string = malloc(cell_count + 1);
  if (string) {
    for (each_cell = 0; each_cell < cell_count; each_cell++) {
      cell = &(*(state->cells + each_cell));
      h_ca_value = cell->value;
      if (h_ca_value < 10) {
        c = 48 + h_ca_value;
      } else {
        c = 120;
      }
      *(string + each_cell) = c;
    }
    *(string + cell_count) = '\0';
  } else {
    h_core_trace("malloc");
  }

  return string;
}

h_ca_t *h_ca_state_get_cell(h_ca_state_t *state,
    unsigned long cell_index)
{
  return state->cells + cell_index;
}

unsigned long h_ca_state_get_cell_count(h_ca_state_t *state)
{
  return state->cell_count;
}

unsigned long h_ca_state_get_cell_rule(h_ca_state_t *state,
    unsigned long cell_index)
{
  return (*(state->cells + cell_index)).rule;
}

unsigned long h_ca_state_get_cell_value(h_ca_state_t *state,
    unsigned long cell_index)
{
  return (*(state->cells + cell_index)).value;
}

void h_ca_state_print(h_ca_state_t *state)
{
  h_core_print(state, h_ca_state_get_as_string);
}

void h_ca_state_set_cell(h_ca_state_t *state, unsigned long cell_index,
    h_ca_t *cell)
{
  *(state->cells + cell_index) = h_ca_copy(*cell);
}

void h_ca_state_set_cell_rule(h_ca_state_t *state,
    unsigned long cell_index, unsigned long h_ca_rule)
{
  (*(state->cells + cell_index)).rule = h_ca_rule;
}

void h_ca_state_set_cell_value(h_ca_state_t *state,
    unsigned long cell_index, unsigned long h_ca_value)
{
  (*(state->cells + cell_index)).value = h_ca_value;
}
