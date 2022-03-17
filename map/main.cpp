#include "pair.hpp"
#include "map.hpp"



int main()
{
  ft::map<int, int> mymap;

  for (int i = 0; i < 100; i++)
  {
    mymap.insert(ft::pair<const int, int>(i, 20));
  }
}
