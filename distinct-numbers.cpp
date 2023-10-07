#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main(void) {
  set<long long> set;

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    set.insert(x);
  }

  cout << set.size();
}
