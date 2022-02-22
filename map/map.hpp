#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>

template <typename F, typename S>
struct _tree
{
private:
	struct tree *root;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
	std::pair<F, S> val;
public:
	_tree(){
	}
	_tree(std::pair<F, S> s)
	{
		root = this;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		val = s;
	}
	void insert(std::pair<F, S> s)
	{
		struct tree *next = new struct tree(s);
		if (s.first > val.first)
			this->left = next;
		else
			this->right = next;
		next->root = this;
		next->parent = this;
	}
	void print( void )
	{
		struct tree *tmp = this->root;
	}
};


#endif