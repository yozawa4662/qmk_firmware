#include <stdio.h>
#include "quantum.h"

char timelog_str[24] = {};
int last_time = 0;
int elapsed_time = 0;

void set_timelog(void) {
  elapsed_time = timer_elapsed(last_time);
  last_time = timer_read();
  snprintf(timelog_str, sizeof(timelog_str), "TTerm: %dms", elapsed_time);
}

const char *read_timelog(void) {
  return timelog_str;
}
