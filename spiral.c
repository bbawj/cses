#include <stdio.h>
int main(void) {
  int n;
  scanf("%d", &n);
  unsigned long res[n];
  for (int i = 0; i < n; ++i) {
    unsigned long row, col;
    scanf("%ld", &row);
    scanf("%ld", &col);

    if (row >= col) {
      if (row % 2 == 0) {
        res[i] = row * row - col + 1;
      } else {
        res[i] = (row - 1) * (row - 1) + col;
      }
    } else {
      if (col % 2 == 0) {
        res[i] = (col - 1) * (col - 1) + row;
      } else {
        res[i] = col * col - row + 1;
      }
    }

  }
  for (int i = 0; i < n; ++i) {
    printf("%ld\n", res[i]);
  }
  return 0;
}
