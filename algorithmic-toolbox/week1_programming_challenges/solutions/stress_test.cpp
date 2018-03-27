#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

long long MaxPairwiseProductNAIVE(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFAST(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  int index1 = 0;
  for (int i = 0; i < n; ++i) {
      if(numbers[i] > numbers[index1]) {
          index1 = i;
      }
  }
  int index2 = 0;
  if(!index1)
    index2 = 1;
  for(int i = 0; i < n; i++) {
      if(numbers[i] > numbers[index2] && i != index1)
        index2 = i;
  }
  result = numbers[index1] * numbers[index2];
  return result;
}

int main() {

    while(true) {
        int n = rand() % 100 + 2;
        vector<int> numbers;
        for(int i = 0; i < n; i++) {
            numbers.push_back(rand() % 10000);
        }
        for(int i = 0; i < n; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        long long result1 = MaxPairwiseProductNAIVE(numbers);
        long long result2 = MaxPairwiseProductFAST(numbers);
        if(result1 == result2) {
            cout << "OK" << endl;
        } else {
            cout << "WRONG OUTPUT\n" << result1 << " " << result2 << endl;
            break;
        }
    }
    return 0;
}
