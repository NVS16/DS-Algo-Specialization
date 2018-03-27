#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(long a, long b)
{
  if(b == 0)
    return a;
  long long r = a % b;
  return gcd_fast(b, r);
}

int main() {
  long a, b;
  std::cin >> a >> b;
  long long gcd = gcd_fast(a, b);
  long long result = a * b / gcd; 
  std::cout <<  result << std::endl;
  return 0;
}
