#include <stdio.h>
#include <string.h>

int main(void) {
  long n;
  scanf("%ld", &n);
  int v1[n];
  int v2[n];
  memset(v1, 0, n);
  memset(v2, 0, n);

  long long sum = n*(n+1)/2;
  if (sum % 2 == 1) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  long long mid = sum / 2;
  int n1 = 0;
  int n2 = 0;
  for (int i = n; i > 0; i--) {
    if (mid > 0 && mid - i >= 0) {
      v1[n1++] = i;
      mid -= i;
    } else {
      v2[n2++] = i;
    }
  }
  printf("%d\n", n1);
  for (int i = 0; i < n1; ++i) {
    printf("%d ", v1[i]);
  }
  printf("\n");
  printf("%d\n", n2);
  for (int i = 0; i < n2; ++i) {
    printf("%d ", v2[i]);
  }
}
