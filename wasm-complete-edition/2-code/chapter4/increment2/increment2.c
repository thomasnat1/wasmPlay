#include <stdio.h>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE int increment(int num) {
  num++;
  printf("%d\n", num);
  return 0;
}
