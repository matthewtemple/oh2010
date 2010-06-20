#ifndef oh_computer_output_h
#define oh_computer_output_h

#include "oh/external/external.h"

#define OH_COMPUTER_OUTPUT_BITS 32

struct oh_computer_output_t {
  h_core_bit_t bits[OH_COMPUTER_OUTPUT_BITS];
};
typedef struct oh_computer_output_t oh_computer_output_t;

void oh_computer_output_free(oh_computer_output_t *output);

void oh_computer_output_init(oh_computer_output_t *output);

#endif
