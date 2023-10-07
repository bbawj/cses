#include <stdio.h>
#include <string.h>

int main(void) {
  long long counts[26];
  memset(counts, 0, sizeof(long long) * 26);
  char buf[1000000];

  scanf("%s", buf);
  char *ptr = buf;
  while(*ptr != '\0') {
    counts[*ptr - 'A']++;
    ptr++;
  }

  ptr = buf;
  char odd = '\0';
  for (int i = 0; i < 26; i++) {
    if (counts[i] % 2 == 1) {
      if (odd != '\0') {
        printf("NO SOLUTION\n");
        return 0;
      }
      odd = 'A' + i;
    }     
    counts[i] /= 2;
    memset(ptr, 'A' + i, counts[i]);
    ptr += counts[i];
  }

  if (odd != '\0') {
    *ptr++ = odd;
  }
  for (int i = 25; i >= 0; i--) {
    memset(ptr, 'A' + i, counts[i]);
    ptr += counts[i];
  }
  printf("%s\n", buf);
}
