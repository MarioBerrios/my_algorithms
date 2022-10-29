#ifndef MA_GREEDY_H
#define MA_GREEDY_H

    #include <vector>

    namespace my_algorithms{

        /**
         * @brief Struct used in the bag algorithm. It contains
         * the volume, prices and status of the current item.
         * The status can be 0 (not used), 1 (partially used) or
         * 2 (totally used)
         * 
         */
        typedef struct item {
            long double volume;
            long double price;
            int status;
        } Item;

        /**
         * @brief Group of alogrithms that the functionality is
         * based in the greedy method.
         * 
         */
        class Greedy{
            public:

                /**
                 * @brief Give you the minimun set of elements for a given value
                 * 
                 * @param amount Goal value.
                 * @param vector Elemente to reach the goal.
                 * @return std::vector<T>. If there is not a solution, the first element
                 * is a -1.
                 */
                std::vector<long double> change(const long double amount, 
                    const std::vector<long double> &vector = {500, 200, 100, 50, 20, 10, 5, 2, 1});

                /**
                 * @brief Select the items needed to fill the volumen of the bag with
                 * the hights price possible.
                 * 
                 * @param volumen Volumen of the bag.
                 * @param items vector with all the items available to fill the bag.
                 */
                void bag(const double long volumen, std::vector<Item> &items);
        };
    }

#endif