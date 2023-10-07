// 5
// 3 2 7 4 1
// Output: 1
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int n;
  scanf("%d", &n);
  long long weights[n];
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    long long c;
    scanf("%lld", &c);
    weights[i] = c;
    total += c;
  }

  // min weight difference between 2 groups for a set of n apples = 
  // abs(min for a set of n - 1 apples - weight[n])

  long long min = total;
  // loop through all combinations 2^n
  for (int i = 0; i < (2 << n); ++i) {
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        sum += weights[j];
      }
    }
    long long diff = llabs(sum - (total - sum));
    if (diff < min) {
      min = diff;
    }
  }
  printf("%lld", min);
}
