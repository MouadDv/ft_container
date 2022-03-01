#include <iostream>
#include "cleanup.hpp"
#include "avl.hpp"

int main()
{
	ft::Avl<int, int> test;
	ft::pair<const int, int> p1(10, 20);
	ft::pair<const int, int> p2(5, 20);
	ft::pair<const int, int> p3(30, 20);
	ft::pair<const int, int> p4(20, 20);
	ft::pair<const int, int> p5(40, 20);
	ft::pair<const int, int> p6(15, 20);
	ft::pair<const int, int> p7(26, 20);

	test.insert(&(test.root), p1, nullptr);
	test.insert(&(test.root), p2, nullptr);
	test.insert(&(test.root), p3, nullptr);
	test.insert(&(test.root), p4, nullptr);
	test.insert(&(test.root), p5, nullptr);
	test.insert(&(test.root), p6, nullptr);
	test.insert(&(test.root), p7, nullptr);
	//test.insert(&(test.root), p4);
	//test.insert(&(test.root), p5);
	//test.insert(&(test.root), p6);
	//test.insert(&(test.root), p7);
	//test.insert(&(test.root), p8);

	ft::tree<int, int> *t;
	t = test.root;

	print2D(t);

}
