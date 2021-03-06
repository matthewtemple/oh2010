#include "oh/ca/eca.h"
#include "oh/ca/k3.h"
#include "oh/external/external.h"

struct k3_cell_t {
  h_core_bit_t a;
  h_core_bit_t b;
  h_core_bit_t c;
};
typedef struct k3_cell_t k3_cell_t;

struct k3_context_t {
  h_core_bit_t rule[24];
  k3_cell_t map[8];
};
typedef struct k3_context_t k3_context_t;

h_ca_t h_ca_k3_calculate_new_cell_state(h_ca_system_t *system,
    unsigned long cell_index)
{
  assert(system);
  unsigned long neighbor_0_index;
  unsigned long neighbor_1_index;
  unsigned long neighbor_2_index;
  h_ca_t *neighbor_0_cell;
  h_ca_t *neighbor_1_cell;
  h_ca_t *neighbor_2_cell;
  unsigned long new_cell_value;
  h_ca_t new_cell_state;
  h_core_bit_t in_a;
  h_core_bit_t in_b;
  h_core_bit_t in_c;
  h_core_bit_t link_number;
  h_core_bit_t out_a;
  h_core_bit_t out_b;
  h_core_bit_t out_c;
  k3_context_t *context;

  context = h_ca_system_get_context(system);

  neighbor_0_index
    = h_ca_eca_get_relative_cell_index(system, cell_index, 0);
  neighbor_1_index
    = h_ca_eca_get_relative_cell_index(system, cell_index, 1);
  neighbor_2_index
    = h_ca_eca_get_relative_cell_index(system, cell_index, 2);

  neighbor_0_cell = h_ca_system_get_current_cell(system, neighbor_0_index);
  neighbor_1_cell = h_ca_system_get_current_cell(system, neighbor_1_index);
  neighbor_2_cell = h_ca_system_get_current_cell(system, neighbor_2_index);

  in_a = neighbor_0_cell->value / 4;
  in_b = (neighbor_1_cell->value / 2) % 2;
  in_c = neighbor_2_cell->value % 2;

  link_number = (in_a) + (in_b * 2) + (in_c * 4);
  out_a = context->map[link_number].a;
  out_b = context->map[link_number].b;
  out_c = context->map[link_number].c;

  new_cell_value = (out_a) + (out_b * 2) + (out_c * 4);

  new_cell_state.value = new_cell_value;
  h_ca_init(&new_cell_state, new_cell_value, H_CA_NO_RULE);

  return new_cell_state;
}

void *h_ca_k3_create_context(void *parameter_object)
{
  k3_context_t *context;
  unsigned long rule_number;
  unsigned long value;
  unsigned long place_value;
  unsigned short each_bit;
  unsigned short each_link;
  unsigned long div;

  context = malloc(sizeof *context);
  if (context) {
    rule_number = *((unsigned long *) parameter_object);

    value = rule_number;
    place_value = 8388608;  /*  2^23  */
    for (each_bit = 0; each_bit < 24; each_bit++) {
      div = value / place_value;
      *(context->rule + each_bit) = div;
      value = value % place_value;
      place_value /= 2;
      if (0 == place_value) {
        break;
      }
    }

    for (each_link = 0; each_link < 8; each_link++) {
      (*(context->map + each_link)).a = *(context->rule + (each_link * 3) + 0);
      (*(context->map + each_link)).b = *(context->rule + (each_link * 3) + 1);
      (*(context->map + each_link)).c = *(context->rule + (each_link * 3) + 2);
    }
  } else {
    h_core_trace("malloc");
  }

  return context;
}

void h_ca_k3_destroy_context(void *context_object)
{
  free(context_object);
}

void h_ca_k3_get_cell_color(h_ca_t *cell, h_core_color_t *color)
{
  h_core_bit_t a;
  h_core_bit_t b;
  h_core_bit_t c;

  a = cell->value % 2;
  b = (cell->value / 2) % 2;
  c = cell->value / 4;

  if (0 == a) {
    color->red = H_CORE_MAX_COLOR;
  } else {
    color->red = 0;
  }
  if (0 == b) {
    color->green = H_CORE_MAX_COLOR;
  } else {
    color->green = 0;
  }
  if (0 == c) {
    color->blue = H_CORE_MAX_COLOR;
  } else {
    color->blue = 0;
  }
}

unsigned long h_ca_k3_get_relative_cell_index(h_ca_system_t *system,
    unsigned long cell_index, unsigned long relationship)
{
  return h_ca_eca_get_relative_cell_index(system, cell_index, relationship);
}

void h_ca_k3_init_systemey(h_ca_systemey_t *systemey, void *name_object)
{
  h_ca_systemey_init(systemey, name_object,
      h_ca_k3_calculate_new_cell_state, h_ca_k3_create_context,
      h_ca_k3_destroy_context, H_CA_NO_END_TIME_STEP_FUNCTION,
      h_ca_k3_get_cell_color, h_ca_k3_get_relative_cell_index,
      H_CA_NO_START_TIME_STEP_FUNCTION);
}
