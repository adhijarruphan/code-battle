/* Compile with:
 *      clang++ -std=c++11 -O3 solution.cpp
 * Execute with:
 *      ./a.out
 */
#include <iostream>
#include <iomanip>
#include <iterator>
#include <fstream>
#include <vector>


template< typename I >
struct S {
    S(I i) : b(i) {}
    I begin() const { return b; }
    I end() const { return I(); }
private:
    I b;
};

template< typename I >
S<I> C(I i) { return S<I>(i); }


int main() {
    std::vector<int> numbers(1000000, 0);
    std::ifstream data("numbers.txt");
    for ( auto number : C(std::istream_iterator<int>(data)) ) {
        data >> number;
        ++numbers[number];
    }
    for ( int index = 0; index < numbers.size(); ++index ) {
        if ( numbers[index] > 1 ) {
            std::cout << "\"";
            std::cout << std::setfill('0') << std::setw(6) << index;
            std::cout << "\",";
            std::cout << numbers[index] << '\n';
        }
    }
}

