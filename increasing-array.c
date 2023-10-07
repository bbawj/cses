#include <stdio.h>
#include <stdlib.h>
int main(void) {
  unsigned long n;
  scanf("%ld", &n);
  unsigned long prev;
  scanf("%ld", &prev);

  unsigned long moves = 0;
  for (int i = 1; i < n; ++i) {
    unsigned long cur;
    scanf("%ld", &cur);
    if (cur >= prev) {
      prev = cur;
      continue;
    } else {
      moves += prev - cur;
    }
  }

  printf("%ld", moves);
  return 0;
}
