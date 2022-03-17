#include "pair.hpp"
#include "map.hpp"



int main()
{
  ft::map<int, int> mymap;

  for (int i = 0; i < 100; i++)
  {
    mymap.insert(ft::pair<const int, int>(i, 20));
  }
  ft::map<int, int>::iterator it = mymap.begin();
  for (int i = 0; i < 100; i++) {
    std::cout << "it val " << it->second << "\n";
    it++;
  }
}
