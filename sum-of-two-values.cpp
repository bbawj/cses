#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
#define ll long long

int main(void) {
  int n, x;
  cin >> n >> x;

  array<ll, 2> arr[int(2e5)];

  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    arr[i] = {a, i + 1};
  }

  sort(arr, arr + n);

  int left = 0;
  int right = n - 1;

  while (left < right) {
    ll sum = arr[left][0] + arr[right][0];
    if (sum == x) {
      cout << arr[left][1] << " " << arr[right][1];
      return 0;
    } else if (sum < x) {
      ++left;
    } else {
      --right;
    }
  }
  cout << "IMPOSSIBLE";
}
