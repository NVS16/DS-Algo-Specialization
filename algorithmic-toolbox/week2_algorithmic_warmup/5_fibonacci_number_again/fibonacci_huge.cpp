#include <iostream>

long long get_pisano_number(long long m)
{
    long long a = 0, b = 1, c;
    for(long long i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if(b == 1 && a == 0) 
            return i + 1;
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    
    n = n % get_pisano_number(m);
    if (n <= 1)
        return n;
    long long a = 0, b = 1, c;

    for(long long i = 0; i < n - 1; ++i) {
        c = (a + b) % m;
        a = b;
        b = c;
    }
    return b % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    long long result = get_fibonacci_huge_naive(n, m) ;
    std::cout << result << '\n';
}
