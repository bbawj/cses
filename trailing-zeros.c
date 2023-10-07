#include <stdio.h>

int main(void) {
  long long n;
  scanf("%lld", &n);
  long long res = 5;
  long long count = 0;

  while (n >= res) {
    count += n / res;
    res *= 5;
  }
  printf("%lld", count);
}
