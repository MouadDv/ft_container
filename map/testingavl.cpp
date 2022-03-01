#include <iostream>
#include "cleanup.hpp"
#include "avl.hpp"
#include <string>

int main(int ac, char **av)
{
  ft::Avl<int, int> test;
  for (int i = 1; i < ac; i++) {
    std::string t(av[i]);
	ft::pair<const int, int> p1(std::stoi(t), 20);
	test.insert(&(test.root), p1, nullptr);

  }
  print2D(test.root);
}
