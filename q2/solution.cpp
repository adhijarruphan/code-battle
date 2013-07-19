/* Compile with:
 *      clang++ -std=c++11 -O3 solution.cpp
 * Execute with:
 *      ./a.out
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int main() {
    std::ifstream data("numbers.txt");
    std::vector<int> numbers(1000000, 0);
    while ( data.good() ) {
        int number;
        data >> number;
        ++numbers[number];
    }
    for ( int index = 0; index < numbers.size(); ++index ) {
        if ( numbers[index] > 1 ) {
            std::cout << std::setfill('0') << std::setw(6);
            std::cout << index << std::endl;
        }
    }
}

