#include <iostream>
#include "map.hpp"


int main()
{
	ft::Avl<int, int> test;
	ft::pair<const int, int> p1(1, 20);
	ft::pair<const int, int> p2(2, 20);
	ft::pair<const int, int> p3(3, 20);
	ft::pair<const int, int> p4(4, 20);
	ft::pair<const int, int> p5(5, 20);
	ft::pair<const int, int> p6(6, 20);
	ft::pair<const int, int> p7(7, 20);
	ft::pair<const int, int> p8(8, 20);

	test.insert(&(test.root), p1);
	test.insert(&(test.root), p2);
	test.insert(&(test.root), p3);
	test.insert(&(test.root), p4);
	test.insert(&(test.root), p5);
	test.insert(&(test.root), p6);
	test.insert(&(test.root), p7);
	test.insert(&(test.root), p8);

	ft::tree<int, int> *t;
	t = test.root;

	print2D(test.root);

}
