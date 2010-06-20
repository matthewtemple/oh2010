#include "oh/ca/state.h"
#include "oh/ca/tools.h"
#include "oh/external/external.h"

static unsigned long h_ca_select_rule_random();

h_container_array_t *h_ca_create_initial_state(unsigned long cell_count,
    unsigned long time_steps, h_ca_select_initial_rule_f select_initial_rule,
    h_ca_select_initial_value_f select_initial_value)
{
  h_container_array_t *initial_state;
  unsigned long each_time_step;
  unsigned long each_cell;
  h_ca_state_t *cell_state;
  h_ca_t *cells;

  initial_state = h_container_array_create(time_steps, h_ca_state_compare,
      h_ca_state_copy, h_ca_state_destroy);
  if (initial_state) {
    cells = malloc(sizeof(h_ca_t) * cell_count);
    if (cells) {
      for (each_time_step = 0; each_time_step < time_steps; each_time_step++) {
        for (each_cell = 0; each_cell < cell_count; each_cell++) {
          (*(cells + each_cell)).value = select_initial_value();
          (*(cells + each_cell)).rule = select_initial_rule();
        }
        cell_state = h_ca_state_create_from_cells(cells, cell_count);
        if (cell_state) {
          h_container_array_add(initial_state, each_time_step, cell_state);
        } else {
          h_core_trace("h_ca_state_create_from_cells");
        }
      }
      free(cells);
    } else {
      h_core_trace("malloc");
    }
  } else {
    h_core_trace("h_container_array_create");
  }

  return initial_state;
}

h_container_array_t *h_ca_create_initial_state_from_bitarray
(h_core_bitarray_t *bitarray)
{
  assert(bitarray);
  h_container_array_t *initial_state;
  unsigned long each_cell;
  h_ca_state_t *cell_state;
  h_ca_t *cells;
  h_core_bit_t bit;
  unsigned long cell_count;

  cell_count = h_core_bitarray_get_size(bitarray);

  initial_state = h_container_array_create(1, h_ca_state_compare,
      h_ca_state_copy, h_ca_state_destroy);
  if (initial_state) {
    cells = malloc(sizeof(h_ca_t) * cell_count);
    if (cells) {
      for (each_cell = 0; each_cell < cell_count; each_cell++) {
        bit = h_core_bitarray_get_bit(bitarray, each_cell);
        (*(cells + each_cell)).value = bit;
        (*(cells + each_cell)).rule = 0;
      }
      cell_state = h_ca_state_create_from_cells(cells, cell_count);
      if (cell_state) {
        h_container_array_add(initial_state, 0, cell_state);
      } else {
        h_core_trace("h_ca_state_create_from_cells");
      }
      free(cells);
    } else {
      h_core_trace("malloc");
    }
  } else {
    h_core_trace("h_container_array_create");
  }

  return initial_state;
}

h_container_array_t *h_ca_create_initial_state_salt_and_pepper_binary
(unsigned long cell_count, unsigned long time_steps)
{
  return h_ca_create_initial_state(cell_count, time_steps,
      h_ca_select_rule_random, h_ca_select_value_salt_and_pepper);
}

h_container_array_t *h_ca_create_initial_state_single_cell_binary
(unsigned long cell_count, unsigned long time_steps)
{
  h_container_array_t *initial_state;
  unsigned long single_cell_index;
  h_ca_state_t *cell_state;
  unsigned long each_time_step;

  initial_state = h_ca_create_initial_state(cell_count, time_steps,
      h_ca_select_rule_random, h_ca_select_value_0);
  if (initial_state) {
    single_cell_index = cell_count / 2;
    for (each_time_step = 0; each_time_step < time_steps; each_time_step++) {
      cell_state = h_container_array_find(initial_state, each_time_step);
      if (cell_state) {
        h_ca_state_set_cell_value(cell_state, single_cell_index, 1);
      } else {
        h_core_trace("h_container_array_find");
      }
    }
  } else {
    h_core_trace("h_ca_create_initial_state");
  }

  return initial_state;
}

h_container_array_t *h_ca_create_initial_state_single_cell_k3
(unsigned long cell_count)
{
  h_container_array_t *initial_state;
  unsigned long single_cell_index;
  h_ca_state_t *cell_state;

  initial_state = h_ca_create_initial_state(cell_count, 1,
      h_ca_select_rule_0, h_ca_select_value_0);
  if (initial_state) {
    single_cell_index = cell_count / 2;
    cell_state = h_container_array_find_last(initial_state);
    h_ca_state_set_cell_value(cell_state, single_cell_index, 7);
  } else {
    h_core_trace("h_ca_create_initial_state");
  }

  return initial_state;
}

unsigned long h_ca_select_rule_0()
{
  return 0;
}

unsigned long h_ca_select_rule_random()
{
  return random();
}

unsigned long h_ca_select_value_0()
{
  return 0;
}

unsigned long h_ca_select_value_salt_and_pepper()
{
  return h_core_coin_toss();
}
