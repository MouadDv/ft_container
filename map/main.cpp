#include "pair.hpp"
#include "map.hpp"
#include <map>

#include <random>

int main()
{
bool cond;
        /*---------------------------------- time limit test --------------------------------------------*/
        /*{
            int res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            res = m.lower_bound(1e5)->first;

            ft_res = ft_m.lower_bound(1e5)->first;
            cond = ft_res == res;
        }*/
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150, 19}; // size = 9
        for (size_t i = 0; i < 10; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
        }
        std::cout << (ft_m.insert(ft::make_pair(20, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(10, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(100, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(15, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(60, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(90, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(65, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(200, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(150, "value"))).second << "\n";
           std::cout << (ft_m.insert(ft::make_pair(19, "value"))).second << "\n";
        for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); it++) {
          std::cout << "el == " << it->first << "\n";
        }
       // ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
        /*---------------------------------------------------------------------------------------------*/
}
