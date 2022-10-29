#ifndef MA_DIVIDEANDCONQUER_H
#define MA_DIVIDEANDCONQUER_H

    #include <vector>

    namespace my_algorithms{

        /**
         * @brief Group of alogrithms that the functionality is
         * based in the divide and conquer method.
         * 
         */
        template<class T>
        class DivideAndConquer{
            public:
                /**
                 * @brief Search for the given x in the given vector.
                 * 
                 * @param vector Vector where the search is done.
                 * @param x Searched value.
                 * @return int Position where the value is stored within the
                 * vector. Return -1 if the value is not find.
                 */
                static int binary_search(const std::vector<T> &vector, T x);

                /**
                 * @brief Seatch for the maximun and minimun of the given vector.
                 * 
                 * @param vector Vector where the search is done.
                 * @param max Variable where the max is going to be stored.
                 * @param min Variable where the min is going to be stored.
                 */
                static void max_min (const std::vector<T> &vector, T &max, T &min);

                /**
                 * @brief Seatch for the maximun and minimun of the given vector.
                 * 
                 * @param vector Vector where the search is done.
                 * @param i Start positition of the vector.
                 * @param j End position of the vector. 
                 * @param max Variable where the max is going to be stored.
                 * @param min Variable where the min is going to be stored.
                 */
                static void max_min (const std::vector<T> &vector, const int i, const int j,
                T &max, T &min);

                /**
                 * @brief Sort a vector.
                 * 
                 * @param vector Vector to be sorted.
                 */
                static void quicksort(std::vector<T> &vector);

                /**
                 * @brief Sort a vector.
                 * 
                 * @param vector Vector to be sorted.
                 * @param i Start positition of the vector.
                 * @param j End position of the vector. 
                 */
                static void quicksort(std::vector<T> &vector, const int i, 
                    const int j);

                /**
                 * @brief Search for the smallest k numbers in a vector
                 * 
                 * @param vector Vector where the seach is performed.
                 * @param k Number of smallest numbers.
                 * @return std::vector<T> Vector of size k containing the smallest 
                 * numbers.
                 */
                static std::vector<T> kminor(std::vector<T> &vector, const int k);

                /**
                 * @brief Search for the smallest k numbers in a vector
                 * 
                 * @param vector Vector where the seach is performed.
                 * @param k Number of smallest numbers.
                 * @param i Start positition of the vector.
                 * @param j End position of the vector. 
                 * @return std::vector<T> 
                 */
                static std::vector<T> kminor(std::vector<T> &vector, const int k, 
                const int i, const int j);

                /**
                 * @brief Calculate the power of a number
                 * 
                 * @param b Base of the power
                 * @param e Exponent of the power
                 * @return long double
                 */
                long double power(const T b, const T e);
        };
    }
#endif