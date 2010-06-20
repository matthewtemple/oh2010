#ifndef oh_computer_system_h
#define oh_computer_system_h

#include "oh/computer/output.h"

struct oh_computer_system_t;
typedef struct oh_computer_system_t oh_computer_system_t;

typedef void (*oh_computer_logic_f)(unsigned long input,
    oh_computer_output_t *output);

oh_computer_output_t *oh_computer_system_compute(oh_computer_system_t *system,
    unsigned long input);

oh_computer_system_t *oh_computer_system_create(unsigned long order,
    oh_computer_logic_f logic);

oh_computer_system_t *oh_computer_system_create_from_file(char *filename);

void oh_computer_system_destroy(void *system_object);

char *oh_computer_system_get_as_string(void *system_object);

void oh_computer_system_print(oh_computer_system_t *system);

h_core_bool_t oh_computer_system_save_as_file(oh_computer_system_t *system,
    char *filename);

#endif
