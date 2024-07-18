#include <iostream>
#include <string>

template <typename T, typename U, typename M>
class Triad {
   private:
    T m_first{};
    U m_second{};
    M m_third{};

   public:
    explicit Triad<T, U, M>(const T& first, const U& second, const M& third)
        : m_first{first}, m_second{second}, m_third{third} {}

    const T& first() const { return m_first; }
    const U& second() const { return m_second; }
    const M& third() const { return m_third; }
    void print() const;
};

template <typename T, typename U, typename M>
void Triad<T, U, M>::print() const {
    std::cout << "[" << m_first << ", " << m_second << ", " << m_third << ")\n";
}

int main() {
    Triad<int, int, int> t1{1, 2, 3};
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2{1, 2.3, "Hello"s};
    t2.print();
    std::cout << '\n';

    return 0;
}
