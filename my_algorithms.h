#ifndef MY_ALGORITHMS_H
#define MY_ALGORITHMS_H

    namespace my_algorithms{
        /**
         * @brief Group of alogrithms that the functionality is
         * based in the recursive method.
         * 
         */
        class Recursive{
            public:
                /**
                 * @brief Calculate the n position of Fibonacci sequence
                 * 
                 * @param n Position to calculate the value of.
                 * @param start Start value of the sequence. If different
                 * from 0, the start will be 1.
                 * @return unsigned long Value of the n position.
                 */
                static long double fib(const int n, const int start = 0);

                /**
                 * @brief Calculate the n position of Fibonacci sequence
                 * 
                 * @param n Position to calculate the value of.
                 * @param table Table of size 2 where the values are stored. The 
                 * two values must be the fib(1) and fib(2) solutions in order.
                 * @return unsigned long Value of the n position.
                 */
                static long double fib(const int n, 
                    std::vector<long double> &table);

                /**
                 * @brief Calculate the numbers of differents path from (0, 0)
                 * to (x, y)
                 * 
                 * @param x The x value of the coordenates. 
                 * @param y The y value of the coordenates.
                 * @return long double Number of paths to the x y coordenate.
                 */
                static long double city_map(const int x, const int y);

                /**
                 * @brief Calculate the numbers of differents path from (0, 0)
                 * to (x, y)
                 * 
                 * @param x The x value of the coordenates. 
                 * @param y The y value of the coordenates.
                 * @param matrix Matrix of size x y where the values are stored. The
                 * values in the first row and first column must be 1 and the rest
                 * should be -1. Any other coordenate with a value of 0 will be a 
                 * excluded croosroad.
                 * @return long double Number of paths to the x y coordenate.
                 */
                static long double city_map(const int x, const int y,
                    std::vector< std::vector<long double> > matrix);

        };

        /**
         * @brief Group of alogrithms that the functionality is
         * based in the divide and conquer method.
         * 
         */
        template<class T>
        class DivideAndConquer{
            
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
            static void quicksort(std::vector<T> &vector, int i, int j);
        };
    }

#endif