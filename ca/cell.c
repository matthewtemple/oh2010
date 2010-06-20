#include "oh/ca/cell.h"
#include "oh/external/external.h"

h_ca_t h_ca_copy(h_ca_t cell)
{
  h_ca_t h_ca_copy;

  h_ca_copy.value = cell.value;
  h_ca_copy.rule = cell.rule;

  return h_ca_copy;
}

void h_ca_init(h_ca_t *cell, unsigned long value, unsigned long rule)
{
  assert(cell);

  cell->value = value;
  cell->rule = rule;
}
