#include <iostream>

int fibonacci_sum_eff(long long n) {
    if (n <= 1)
        return n;
    
    n = (n + 2) % 60;
    
    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return (current - 1) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_eff(n) << std::endl;
}
