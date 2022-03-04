#include <iostream>
#include "map.hpp"
#include "avl.hpp"

#define COUNT 10

using namespace std;

template <class F>
int calheight(F *p)
{
	if(p->l && p->r)
		{
			if (p->l->h < p->r->h)
				return p->r->h + 1;
			else
				return  p->l->h + 1;
		}
	else if(p->l && p->r == NULL)
		{
			return p->l->h + 1;
		}
	else if(p->l ==NULL && p->r)
		{
			return p->r->h + 1;
		}
	return 0;
}


template <class F>
void print2DUtil(F *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->r, space);

	// Print current node after space
	// count
	cout<<endl;
	for (int i = COUNT; i < space; i++)
		cout<<" ";
	cout<<root->val.first <<"\n";
	//cout<< root->parent << "\n";
	// Process left child
	print2DUtil(root->l, space);
}

// Wrapper over print2DUtil()
template<typename F>
void print2D(F *root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}


int main()
{
	ft::Avl<int, int> test;
	ft::pair<int, int> p1(10, 20);
	ft::pair<int, int> p2(5, 20);
	ft::pair<int, int> p3(30, 20);
	ft::pair<int, int> p4(20, 20);
	ft::pair<int, int> p5(40, 20);
	ft::pair<int, int> p6(15, 20);
	ft::pair<int, int> p7(26, 20);

	test.insert(&(test.root), p1);
	test.insert(&(test.root), p2);
	test.insert(&(test.root), p3);
	test.insert(&(test.root), p4);
	test.insert(&(test.root), p5);
	test.insert(&(test.root), p6);
	test.insert(&(test.root), p7);
	//test.insert(&(test.root), p4);
	//test.insert(&(test.root), p5);
	//test.insert(&(test.root), p6);
	//test.insert(&(test.root), p7);
	//test.insert(&(test.root), p8);
	print2D(test.root);

}
