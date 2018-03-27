#include <bits/stdc++.h>

using namespace std;

bool isGreater(int num, int maxNum) {
  stringstream st, sx;
  string maxStr, Str;
  st << maxNum;
  st << num;
  sx << num;
  sx << maxNum;
  sx >> num;
  st >> maxNum;
  return num > maxNum;
}

string largest_number(vector<int> a) {
  //write your code here
  stringstream ret;
  int maxNum, maxi;
  while(a.size() != 0) {
    maxNum = a[0];
    maxi = 0;
    for (size_t i = 1; i < a.size(); i++) {
      if(isGreater(a[i], maxNum)) {
        maxNum = a[i];
        maxi = i;
      }
    }
    ret << maxNum;
    a.erase(a.begin() + maxi);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
}
