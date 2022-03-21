#include "pair.hpp"
#include "map.hpp"



int main()
{
  ft::map<int, int> mymap;

  for (int i = 0; i < 10; i++)
  {
    mymap.insert(ft::pair<const int, int>(i, i));
  }
  ft::map<int, int>::iterator it = mymap.begin();
  while (it != mymap.end())
  {
    std::cout << "it val " << (*it).first << " , " << (*it).second << "\n";
    ++it;
  }
  ft::map<int, int>::reverse_iterator en = mymap.rbegin();
  while(en != mymap.rend()){
    std::cout << "it val " << (*en).first << " , " << (*en).second << "\n";
    ++en;
  }
}
