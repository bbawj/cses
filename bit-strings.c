#include <stdio.h>

int main(void) {
  long long n;
  scanf("%lld", &n);

  long long res = 1;
  for (int i = 0; i < n; i++) {
    res = 2*res % (1000000007);
  }
  printf("%lld", res);
}
