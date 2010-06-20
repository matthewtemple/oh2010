#include "oh/computer/output.h"
#include "oh/external/external.h"

void oh_computer_output_free(oh_computer_output_t *output) {}

void oh_computer_output_init(oh_computer_output_t *output)
{
  memset(output->bits, 0, OH_COMPUTER_OUTPUT_BITS);
}
