#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS

#include "pair.hpp"
#include <iostream>

namespace ft
{

template <class T1, class T2>
struct tree {
	tree<T1, T2> *r;
	tree<T1, T2> *l;
	//tree<T1, T2> *parent;
    pair<const T1, T2> val;

    tree(const pair<const T1, T2> &p): val(p), r(0), l(0) {}
};

template <typename F, typename S>
class Avl {
public:
    tree<F, S> *nodes;
    tree<F, S> *root;
public:
	Avl(): nodes(0), root(0) {
    }
    void insert(tree<F, S> **pos,pair<const F, S> &p)
    {
        if ((*pos) == nullptr)
        {
            (*pos) = new tree<F, S>(p);
            //if(this->root == nullptr)
            //    this->root = pos;
            //std::cout << "Element: " << pos->val.first << "\n";
        }
        else
        {
            if (p < (*pos)->val)
                insert(&((*pos)->l), p);
            else
                insert(&((*pos)->r), p);
        }
    }
	~Avl(){}
};


using namespace std;
#define COUNT 10

template <class F, class S>
void print2DUtil(ft::tree<F, S> *root, int space)
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
    cout<<root->val.first<<"\n";

    // Process left child
    print2DUtil(root->l, space);
}

// Wrapper over print2DUtil()
template<typename F, typename S>

void print2D(ft::tree<F, S> *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

}
#endif
