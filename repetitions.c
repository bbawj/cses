#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  nread = getline(&line, &len, stdin);

  int max = 1;
  char prev = line[0];
  int count = 1;
  for (int i = 1; i < nread; ++i) {
    if (line[i] == prev) {
      count++; 
    } else {
      if (count > max) max = count;
      count = 1;
      prev = line[i];
    }
  }

  printf("%d", max);
}
