#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

#define ll long long

int main(void) {
  int n;
  cin >> n;
  array<ll, 2> s[int(2e5)];

  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    s[i][1] = a;
    s[i][0] = b;
  }

  sort(s, s + n);

  ll ans = 0, prev = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i][1] >= prev) {
      prev = s[i][0];
      ans++;
    }
  }

  cout << ans;
}
