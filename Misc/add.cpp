#include <iostream>
#include <utility>

template <typename T>
void print(std::pair<T, T> p)  // compile error, CTAD can't be used here
{
    std::cout << p.first << ' ' << p.second << '\n';
}

int main() {
    std::pair p{1, 2};  // p deduced to std::pair<int, int>
    print(p);

    return 0;
}
