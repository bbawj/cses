#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(void) {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> applicants;
  for (ll i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    applicants.push_back(x);
  }

  vector<ll> apartments;
  for (ll i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    apartments.push_back(x);
  }

  sort(applicants.begin(), applicants.end());
  sort(apartments.begin(), apartments.end());
  vector<ll>::iterator a = applicants.begin();
  ll res = 0;
  for (vector<ll>::iterator it = apartments.begin();
       it != apartments.end() && a != applicants.end(); ++it) {

    if (*it > *a + k) {
      --it;
      ++a;
    } else if (*it < *a - k) {
      continue;
    } else if (*it <= *a + k && *it >= *a - k) {
      ++res;
      ++a;
    }
  }
  cout << res;
}
