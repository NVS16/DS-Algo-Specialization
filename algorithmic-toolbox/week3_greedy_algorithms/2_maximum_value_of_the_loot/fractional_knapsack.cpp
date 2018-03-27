#include <bits/stdc++.h>

using namespace std;

struct vw {
  double value, weight;
};

typedef vector<vw>::iterator myItr;


bool comparator(vw one, vw two)
{
  return (one.value / one.weight) > (two.value / two.weight);
}

double get_optimal_value(double capacity, vector<vw> vws) {
  double tvalue = 0.0, a;
  int i = 0;
  for(myItr it = vws.begin(); it != vws.end(); it++, i++)
  {
    //cout << vws[i].value << " " << vws[i].weight << endl;
    if(!capacity)
      return tvalue;
    a = min(vws[i].weight, capacity);
    tvalue += a * vws[i].value / vws[i].weight;
    capacity -= a;
  }
  return tvalue;
}

int main() {
  int n;
  double capacity, value, weight;
  cin >> n >> capacity;
  vector<vw> vws(n);
  for (int i = 0; i < n; i++) {
    cin >> vws[i].value >> vws[i].weight;
  }
  sort(vws.begin(), vws.end(), comparator);
  double optimal_value = get_optimal_value(capacity, vws);
  /*int i = 0;
  for(myItr it = vws.begin(); it != vws.end(); it++, i++)
  {
    cout << vws[i].value << " " << vws[i].weight << endl;
  }*/
  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
