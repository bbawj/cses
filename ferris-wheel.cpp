#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main(void) {
  ll n, x;
  cin >> n >> x;

  vector<ll> weights;
  for (ll i = 0; i < n; ++i) {
    ll w;
    cin >> w;
    weights.push_back(w);
  }

  sort(weights.begin(), weights.end());

  ll ans = 0;
  for (ll left = 0, right = n - 1; left < right;) {
    while (left < right && weights[left] + weights[right] > x) {
      right--;
    }
    if (left >= right)
      break;
    left++;
    right--;
    ans++;
  }

  cout << n - ans;
}
