#include <bits/stdc++.h>

using namespace std;

struct Segment {
  int start, end;
};

bool compareOne (Segment one, Segment two) {
  return one.start < two.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int point;
  //write your code here
  sort(segments.begin(), segments.end(), compareOne);
  point = segments[0].end;
  for (size_t i = 0; i < segments.size(); ++i) {
    if(segments[i].start > point) {
      points.push_back(point);
      point = segments[i].end;
    } else if(segments[i].end < point) {
      point = segments[i].end;
    }
  }
  points.push_back(point);
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
