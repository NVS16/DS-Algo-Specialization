#include <bits/stdc++.h>

using namespace std;

int get_change(int m) {
  int n = 0;
  n += m / 10;
  m = m % 10;
  n += m / 5;
  m = m % 5;
  n += m / 1;
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
