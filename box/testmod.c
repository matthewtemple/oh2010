#include "oh/box/testmod.h"

struct oh_box_testmod_t {
};

oh_box_testmod_t *oh_box_testmod_create()
{
  oh_box_testmod_t *testmod;

  testmod = malloc(sizeof *testmod);
  if (testmod) {

  } else {
    h_core_trace("malloc");
  }

  return testmod;
}

void oh_box_testmod_destroy(void *testmod_void)
{
  assert(testmod_void);
  oh_box_testmod_t *testmod;

  testmod = testmod_void;

  free(testmod);
}
