#include <vector>
#include "my_algorithms.h"

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
        if (table.size() < n){
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

    template<class T>
    int DivideAndConquer<T>::binary_search(const std::vector<T> &vector, T x){
        int i = 0;
        int j = vector.size() - 1;

        while (i < j){
            int k = (i+j)/2;
            if (x < vector[k])
                j = k - 1;
            else if (x > vector[k])
                i = k + 1;
            else{
                return k;
            }
        }
        return -1;
    }

    template<class T>
    void DivideAndConquer<T>::max_min (const std::vector<T> &vector, T &max, T &min){
        max_min(vector, 0, vectro.size()-1, max, min);
    }

    template<class T>
    void DivideAndConquer<T>::max_min (const std::vector<T> &vector, const int i, 
    const int j, T &max, T &min){
        if (i == j){
            max = vector[i];
            min = vector[j];
        } else if (i = j-1){
            max = (vector[i] > vector[j]) ? vector[i] : vector[j];
            min = (vector[i] < vector[j]) ? vector[i] : vector[j];
        } else {
            int middle = (i + j)/2;
            int max1, min1, max2, min2;
            max_min(vector, i, middle-1, max1, min1);
            max_min(vector, middle, j, max2, min2);
            max = (max1 > max2) ? max1 : max2;
            min = (min1 < min2) ? min1 : min2;
        }
    }

    template<class T>
    void DivideAndConquer<T>::quicksort(std::vector<T> &vector){
        quicksort(vector, 0, vector.size());
    }
    
    template<class T>
    void DivideAndConquer<T>::quicksort(std::vector<T> &vector, int i, int j){
        int i_ = i, j_ = j, k;
        T x = vector[(i + j)/2];

        do{
            while (vector[i_] < x)
                i_++
            while (vector[j_] > x)
                j_--
            if (i_ <= j_){
                T aux = vector[i_];
                vector[i_] = vector[j_];
                vector[j_] = aux;
                i_++;
                j_--;
            }
        } while ( i_ <= j_);

        if (i < j_)
            quicksort(vector, i, j_);
        if (i_ < j)
            quicksort(vector, i_, j)
    }
}
