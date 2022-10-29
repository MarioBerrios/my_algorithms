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
        max_min(vector, 0, vector.size()-1, max, min);
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
        quicksort(vector, 0, vector.size()-1);
    }
    
    template<class T>
    void DivideAndConquer<T>::quicksort(std::vector<T> &vector, const int i, 
    const int j){
        int i_ = i, j_ = j, k;
        T aux, x = vector[(i + j)/2];

        do{
            while (vector[i_] < x)
                i_++;
            while (vector[j_] > x)
                j_--;
            if (i_ <= j_){
                aux = vector[i_];
                vector[i_] = vector[j_];
                vector[j_] = aux;
                i_++;
                j_--;
            }
        } while ( i_ <= j_);

        if (i < j_)
            quicksort(vector, i, j_);
        if (i_ < j)
            quicksort(vector, i_, j);
    }

    template<class T>
    std::vector<T> DivideAndConquer<T>::kminor(std::vector<T> &vector, const int k){
        kminor(vector, k, 0, vector.size()-1);
    }

    template<class T>
    std::vector<T> DivideAndConquer<T>::kminor(std::vector<T> &vector, const int k, 
    const int i, const int j){
        int i_ = i, j_ = j;
        T aux, x = vector[(i + j)/2];

        do{
            while (vector[i_] < x)
                i_++;
            while (vector[j_] > x)
                j_--;
            if (i_ <= j_){
                aux = vector[i_];
                vector[i_] = vector[j_];
                vector[j_] = aux;
                i_++;
                j_--;
            }
        } while ( i_ <= j_);

        if (k == i_)
            return std::vector<T> (vector.begin(), vector.begin()+k-1);
        else if (k < i_)
            kminor(vector, k, i, j_);
        else
            kminor(vector, k, i_, j);
    }

    template<class T>
    long double DivideAndConquer<T>::power(const T b, const T e){
        if (e == 1)
            return b;
        else if (e % 2 == 0){
            long double aux = power(b, e/2);
            return aux * aux;
        } else {
            return b * power(b, e-1);
        }
    }

    std::vector<long double> Greedy::change(const long double amount, 
    const std::vector<long double> &vector){
        std::vector<long double> solution;
        long double x, s = 0;

        while(s != amount){
            x = 0;
            for (auto item: vector){
                if (item > x && s + item <= amount)
                    x = item;
            }
            if (x != 0){
                solution.push_back(x);
                s += x;
            } else {
                solution.clear();
                return solution.push_back(-1);
            }
            
        }

        return solution;
    }


    void Greedy::bag(const long double volumen, std::vector<Item> &items){
        long double max_price, remain = volume;
        int max_material;
        bool mat_available;

        for (auto item: items)
            item.status = 0;

        do{
            max_price = 0;
            max_material = 0;
            mat_available = false;

            for (int i = 0; i < (int) items.size(); i++){
                if (items[i].status == 0){
                    mat_available = true;
                    if (items[i].price > max_price){
                        max_price = items[i].price;
                        max_material = i;
                    }
                }
            }

            if (mat_available == true){
                if (remain >= items[max_material].volume){
                    items[max_material].status = 2;
                    remain -= items[max_material].volume;
                } else {
                    items[max_material].status = 1;
                    remain = 0;
                }
            }
        } while (remain > 0 || mat_available)
    }
}
