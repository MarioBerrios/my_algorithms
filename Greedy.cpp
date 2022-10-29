#include <vector>
#include "Greedy.hpp"

namespace my_algorithms{

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
                solution.push_back(-1);
                return solution;
            }
        }

        return solution;
    }


    void Greedy::bag(const long double volumen, std::vector<Item> &items){
        long double max_price, remain = volumen;
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
        } while (remain > 0 || mat_available);
    }
}