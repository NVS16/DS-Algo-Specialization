#include <iostream>
#include <vector>

using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {

    if (to <= 1)
        return to;

    long from_curr = 1;
    from = (from + 1) % 60;
    to = (to + 2) % 60;



    long long previous = 0;
    long long current  = 1;


    for (int i = 0; i < to - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        if(i == from - 2 && from != 1)
            from_curr = current;
    }
    return (current - from_curr) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
