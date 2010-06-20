#ifndef h_ca_cell_h
#define h_ca_cell_h

#define H_CA_NO_RULE 0

struct h_ca_t {
  unsigned long value;
  unsigned long rule;
};
typedef struct h_ca_t h_ca_t;

h_ca_t h_ca_copy(h_ca_t cell);

void h_ca_init(h_ca_t *cell, unsigned long value, unsigned long rule);

#endif
