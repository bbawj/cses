#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int row, col;
} Pos;

unsigned long num_safe(int n, Pos p1) {
  int res = 0;
  if (p1.row + 2 < n) {
    if (p1.col + 1 < n) {
        res++;
    }
    if (p1.col - 1 >= 0) {
        res++;
    }
  }
  if (p1.col + 2 < n) {
    if (p1.row + 1 < n) {
        res++;
    }
  }
  if (p1.col - 2 >= 0) {
    if (p1.row + 1 < n) {
        res++;
    }
  }
  // safe = total - seen - unsafe unseen - current pos (1)
  return n*n - res - 1 - (n*p1.row + p1.col);
}

int main(void)
{
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      printf("0\n");
      continue;
    }

    unsigned long res = 0;
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < i; ++k) {
        res += num_safe(i, (Pos){j,k});
      }
    }
    printf("%ld\n", res);
  }

  return EXIT_SUCCESS;
}
