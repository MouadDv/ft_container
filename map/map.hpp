#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS
#define COUNT 10

#include "pair.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
namespace ft
{

    template <class T1, class T2>
    struct tree {
        tree<T1, T2> *parent;
        tree<T1, T2> *r;
        tree<T1, T2> *l;
        //tree<T1, T2> *parent;
        pair<const T1, T2> val;

        tree(const pair<const T1, T2> &p): parent(0), val(p), r(0), l(0) {}
    };

    template <typename F, typename S>
    class Avl {
    public:
        tree<F, S> *root;
    public:
        Avl(): root(0) {
        }
        void LR(tree<F, S> *r)
        {
            if (this->root == r)
                this->root = r->l;
            tree<F, S> *tmp;
            tree<F, S> *p;
            p = r->parent;
            r->parent = r->l->parent;
            r->l->parent = p;
            tmp = r->l->r;
            r->l->r = r;
            r->l = tmp;
        }

        void RR(tree<F, S> *r)
        {
            if (this->root == r)
                this->root = r->r;
            tree<F, S> *tmp;
            tree<F, S> *p;
            p = r->parent;
            r->parent = r->r->parent;
            r->r->parent = p;
            tmp = r->r->l;
            r->r->l = r;
            r->r = tmp;
        }


        int treeheight(tree<F, S> *r)
        {
            if (r == nullptr)
                return 0;
            else {
                int lh = treeheight(r->l);
                int rh = treeheight(r->r);
                return (std::max(lh, rh)) + 1;
            }
        }
        void insert(tree<F, S> **pos,pair<const F, S> &p, tree<F, S> *par)
        {
            if ((*pos) == nullptr)
                {
                    (*pos) = new tree<F, S>(p);
                    (*pos)->parent = par;
                    //if(this->root == nullptr)
                    //    this->root = pos;
                    //std::cout << "Element: " << pos->val.first << "\n";
                }
            else
                {
                    if (p < (*pos)->val)
                        insert(&((*pos)->l), p, (*pos));
                    else
                        insert(&((*pos)->r), p, (*pos));
                }
            int lh = treeheight((*pos)->l);
            int rh = treeheight((*pos)->r);
            int balance = std::abs(lh - rh);

            std::cout << "lh == " << lh << "\n";
            std::cout << "rh == " << rh << "\n";
            std::cout << "balance of tree is == " << balance << "\n";
        }
        ~Avl(){}
    };


    using namespace std;

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
        cout<< root->parent << "\n";
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
