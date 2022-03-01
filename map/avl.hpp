#pragma once
#ifndef TREE_CLASS
#define TREE_CLASS
#define COUNT 10

#include "pair.hpp"
#include "cleanup.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
namespace ft
{

    template <class T1, class T2>
    struct tree {
        typename ft::map<const T1, T2>::value_type val;
        tree<T1, T2> *parent;
        tree<T1, T2> *r;
        tree<T1, T2> *l;
        int h;

        tree(const pair<const T1, T2> &p): h(1) ,parent(0), val(p), r(0), l(0) {}
    };

    template <typename F, typename S>
    class Avl {
    public:
        tree<F, S> *root;
    public:
        Avl(): root(0) {
        }
        int calheight(tree<F, S> *p)
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

        int bf(tree<F, S> *n)
        {
            if(n->l && n->r)
            {
                return n->l->h - n->r->h;
            }
            else if(n->l && n->r == NULL)
            {
                return n->l->h;
            }
            else if(n->l == NULL && n->r )
            {
                return -(n->r->h);
            }
            return (0);
        }

        void Lr(tree<F, S> **s)
        {
            tree<F, S> *d = *s;
            tree<F, S> *tmp;
            *s = d->l;
            tmp = d->l->r;
            d->l->r = d;
            d->l = tmp;
        }

        void Rr(tree<F, S> **s)
        {
            tree<F, S> *d = *s;
            tree<F, S> *tmp;
            *s = d->r;
            tmp = d->r->l;
            d->r->l = d;
            d->r = tmp;
        }

        void LRr(tree<F, S> **s)
        {
            //subchild rotation
            tree<F, S> *d = *s;
            tree<F, S> *tmp;
            tree<F, S> *tmpl;
            tmpl = d->l->r->l;
            tmp = d->l;
            d->l = d->l->r;
            d->l->l = tmp;
            d->l->l->r = tmpl;


            //parent rotation
            *s = d->l;
            tmp = d->l->r;
            d->l->r = d;
            d->l = tmp;
        }

        void RLr(tree<F, S> **s)
        {
            //subchild rotation
            tree<F, S> *d = *s;
            tree<F, S> *tmp;
            tree<F, S> *tmpr;
            tmpr = d->r->l->r;
            tmp = d->r;
            d->r = d->r->l;
            d->r->r = tmp;
            d->r->r->l = tmpr;

            //parent rotation
            *s = d->r;
            tmp = d->r->l;
            d->r->l = d;
            d->r = tmp;
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
            (*pos)->h = calheight(*pos);
            if(bf(*pos)==2 && bf((*pos)->l)==1)
                 Lr(pos);
            else if(bf(*pos)==-2 && bf((*pos)->r)==-1)
                Rr(pos);
            else if(bf(*pos)==-2 && bf((*pos)->r)==1)
                RLr(pos);
            else if(bf(*pos)==2 && bf((*pos)->l)==-1)
                LRr(pos);
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
        //cout<< root->parent << "\n";
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
