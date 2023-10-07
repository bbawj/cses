#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned long n;
  scanf("%ld", &n);
  unsigned long total = 0;
  for (int i = 0; i < n - 1; ++i) {
    unsigned long cur;
    scanf("%ld", &cur);
    total += cur;
  }
  
  unsigned long sum = (n * (n + 1))/2;
  printf("%ld", sum - total);
  return 0;
}
