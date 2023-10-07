#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ll long long

//a b
//x: number of 1 coin move
//y: number of 2 coin moves
// a = x + 2y, b = 2x + y
// 2a - b = 3y

int main(void) {
  ll t;
  scanf("%lld", &t);
  bool res[t];
  for (ll i = 0; i < t; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);

    ll t = 2 * a - b;
    if (t % 3 == 0) {
      ll y = t / 3;
      ll x = a - 2 * y;
      res[i] = y >= 0 && x >= 0;
    } else {
      res[i] = false;
    }
  }
  for (ll i = 0; i < t; i++) {
    if (res[i]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }  
  }
}
