#include "DivideAndConquer.hpp"

namespace my_algorithms {

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
}