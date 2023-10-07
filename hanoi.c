#include <stdio.h>

void hanoi(long long* count, int n, int start, int end) {
  int other = 6 - start - end;
  if (n == 0) return;
  hanoi(n - 1, start, other);
  (*count)++;
  printf("%d %d\n", start, end);
  hanoi(n - 1, other, end);
}

int main(void) {
  int n;
  long long count;
  scanf("%d", &n);
  hanoi(&count, n, 1, 3);
}
