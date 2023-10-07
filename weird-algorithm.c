/*
 * Consider an algorithm that takes as input a positive integer n. 
 * If n is even, the algorithm divides it by two, and if n is odd, the algorithm 
 * multiplies it by three and adds one. The algorithm repeats this, until n is one. 
 * For example, the sequence for n=3 is as follows:
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned long input;
  scanf("%ld", &input);
  printf("%ld", input);
  while (input != 1) {
    if (input % 2 == 0) {
      input /= 2;
    } else {
      input *= 3;
      input += 1;
    }
    printf(" %ld", input);
  }
  return 0;
}
