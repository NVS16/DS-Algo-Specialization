#include <bits/stdc++.h>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  for(int i = 1; i <= n; i++) {
    summands.push_back(i);
    n -= i;
  }
  summands[summands.size() - 1] += n;
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
