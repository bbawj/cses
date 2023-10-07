// 000
// 001
// 011
// 010
// 110
// 111
// 101
// 100
#include <stdio.h>
#include <string.h>

int main(void) {
  int n;
  scanf("%d", &n);
  char res[1 << n][n+1];

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      strcpy(res[0], "0");
      strcpy(res[1], "1");
    } else {
      long long count = 1 << (i+1);
      for (long long j = 0; j < count / 2; j++) {
        snprintf(res[count - 1 - j], n+1, "%s", res[j]);
      }
      for (long long j = 0; j < count; j++) {
        char temp[n+1];
        if (j < count / 2) {
          snprintf(temp, n+1, "0%s\n", res[j]);
          snprintf(res[j], n+1, "%s", temp);
        } else {
          snprintf(temp, n+1, "1%s\n", res[j]);
          snprintf(res[j], n+1, "%s", temp);
        }
      }
    }
  }
  for (long long j = 0; j < 1 << n; j++) {
    printf("%s\n", res[j]);
  }
}


