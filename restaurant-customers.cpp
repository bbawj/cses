#include <cinttypes>
#include <iostream>
#include <map>

using namespace std;

#define ll long long

int main(void) {
  int n;
  cin >> n;

  map<ll, ll> times;

  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    times.insert({a, 1});
    times.insert({b, -1});
  }

  ll max = 1;
  ll cur = 0;
  for (auto it = times.begin(); it != times.end(); ++it) {
    cur += it->second;
    if (cur > max)
      max = cur;
  }
  cout << max;
}
