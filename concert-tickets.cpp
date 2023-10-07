#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main(void) {
  ll n, m;
  cin >> n >> m;

  map<ll, int> s;
  ll customers[m];
  for (ll i = 0; i < n; ++i) {
    ll t;
    cin >> t;
    auto it = s.find(t);
    if (it != s.end()) {
      it->second++;
    } else {
      s.insert({t, 1});
    }
  }
  for (ll i = 0; i < m; ++i) {
    cin >> customers[i];
  }

  // 3 5 5 7 8
  // ^       ^
  // ^   ^
  // ^ ^
  //   ^
  //
  // 3 5 7 8
  // ^     ^
  //     ^ ^
  //       ^
  //       ^ ^

  for (ll c = 0; c < m; ++c) {
    if (s.size() == 0) {
      cout << "-1\n";
      continue;
    }
    ll max = customers[c];
    auto ans = s.lower_bound(max + 1);
    if (ans == s.begin()) {
      cout << "-1\n";
      continue;
    }
    cout << prev(ans)->first << "\n";
    prev(ans)->second--;
    if (prev(ans)->second == 0)
      s.erase(prev(ans));
  }
}
