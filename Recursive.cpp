#include <vector>
#include "Recursive.hpp"

namespace my_algorithms {

    long double Recursive::fib (const int n, const int start){
        if (n <= 2 && !start){
            return n-1;
        } else if (n <= 2 && start){
            return n;
        } else {
            return fib(n-1, start) + fib(n-2, start);
        }
    }

    long double Recursive::fib (const int n, std::vector<long double> &table){
        if (table.size() < (unsigned int) n){
            table.push_back(fib(n-1, table) + table[n-3]);
        }
        return table[n-1];
    }

    long double Recursive::city_map (const int x, const int y){
        if (x == 0 || y == 0) {
            return 1;
        } else {
            return city_map(x-1, y) + city_map(x, y-1);
        }
    }

    long double Recursive::city_map(const int x, const int y,
    std::vector< std::vector<long double> > matrix){
        if (matrix[x][y] == -1){
            matrix[x][y] = city_map(x-1, y, matrix) + city_map(x, y-1, matrix);
        }
        return matrix[x][y];
    }
}
