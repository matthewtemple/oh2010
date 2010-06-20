#include "oh/computer/system.h"
#include "oh/external/external.h"

/*
  static void and_logic(unsigned long input, oh_computer_output_t *output);
*/

static void or_logic(unsigned long input, oh_computer_output_t *output);

void and_logic(unsigned long input, oh_computer_output_t *output)
{
  assert(output);

  if (3 == input) {
    *(output->bits + 0) = 1;
  }
}

void or_logic(unsigned long input, oh_computer_output_t *output)
{
  assert(output);

  if (input != 0) {
    *(output->bits + 0) = 1;
  }
}

int main(int argc, char *argv[])
{
  oh_computer_system_t *oh_computer_system;
  oh_computer_output_t *oh_computer_output;
  unsigned short each_input;

  oh_computer_system = oh_computer_system_create(4, or_logic);
  if (!oh_computer_system) {
    h_core_trace_exit("oh_computer_system_create");
  }

  oh_computer_system_print(oh_computer_system);

  for (each_input = 0; each_input < 4; each_input++) {
    oh_computer_output = oh_computer_system_compute(oh_computer_system, each_input);
    printf("%i -> %i\n", each_input, *(oh_computer_output->bits + 0));
  }

  oh_computer_system_destroy(oh_computer_system);

  return 0;
}
