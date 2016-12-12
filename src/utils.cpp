#include <utils.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void init_random() {
  static bool seeded = false;

  if (!seeded) {
    srand (time (0));
    seeded = true;
  }
}

int random_int(int from, int to) {
  int rand_value = rand ();
  return floor (map (rand_value, 0, RAND_MAX, from, to));
}

// Naive implementation. Don't check for overflows
float map(float src, float src_from, float src_to, float dst_from, float dst_to) {
  return dst_from + (dst_to - dst_from) * ((src - src_from) / (src_to - src_from));
}
