#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

typedef struct {
  unsigned long size;
  unsigned long cap;
  char **data;
} Arr;

void solve(Arr *res, int counts[26], unsigned long max, char *current) {
  if (strlen(current) + 1 == max) {
    if (res->size + 1 > res->cap) {
      res->data = (char**) realloc(res->data, sizeof(char*) * res->cap * 2);
      assert(res->data);
      res->cap *= 2;
    }  
    res->data[res->size++] = strdup(current);
    return;
  }

  for (int i = 0; i < 26; ++i) {
    if (counts[i] > 0) {
      counts[i]--;
      char next[max];
      snprintf(next, max, "%s%c", current, 'a'+i);
      solve(res, counts, max, next);
      counts[i]++;
    }
  }
}

int main(void) {
  char n[LEN];
  scanf("%s", n);
  unsigned long len = strlen(n);
  int counts[26];
  memset(counts, 0, 26 * sizeof(int));
  for (int i = 0; i < len; ++i) {
    counts[n[i] - 'a'] += 1;
  }

  Arr res = {0};
  res.cap = 8;
  res.data = (char**) malloc(8 * sizeof(char*));
  solve(&res, counts, len + 1, "");

  printf("%zu\n", res.size);
  for (int i = 0; i < res.size; ++i) {
    printf("%s\n", res.data[i]);
  }

  return 0;
}

