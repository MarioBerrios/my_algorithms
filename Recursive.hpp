#ifndef MA_RECURSIVE_H
#define MA_RECURSIVE_H

    #include <vector>

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
    }

#endif