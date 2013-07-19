/* Compile with:
 *      clang++ -std=c++11 solution.cpp
 * Execute with:
 *      ./a.out
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int main() {
    std::ifstream data("q1.txt");
    std::vector<bool> numbers(10000);
    while ( data.good() ) {
        int number;
        std::cin >> number;
        numbers[number] = true;
    }
    for ( int index = 0; index < numbers.size(); ++index ) {
        if ( not numbers[index] ) {
            std::cout << std::setfill('0') << std::setw(4);
            std::cout << index << std::endl;
        }
    }
}

