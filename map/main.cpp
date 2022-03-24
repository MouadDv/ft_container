#include "pair.hpp"
#include "map.hpp"
#include <map>


int main()
{

  std::map<int, int> m1;
  ft::map<int, int> ft_m1;

  for (size_t i = 0; i < 10; i++)
    {
      m1.insert(std::make_pair(i, i));
      ft_m1.insert(ft::make_pair(i, i));
    }

  std::map<int, int> const m2(m1.rbegin(), m1.rend());
  ft::map<int, int> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

}
