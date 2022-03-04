#pragma once
#ifndef TREE_CLASS
#define TREE_CLASS

#include "pair.hpp"
#include "map.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>

namespace ft
{
    template <class T1, class T2>
    struct tree {
        typedef typename ft::map<T1, T2>::value_type value_t;
        typedef tree<T1, T2> tree_s;

        tree_s *parent;
        tree_s *r;
        tree_s *l;
        int h;
        value_t val;

        tree(const pair<T1, T2> &p):parent(0), val(p), r(0), l(0) {}
    };

    template <typename F, typename S>
    class Avl {
        typedef typename ft::map<F, S>::value_type value_t;
        typedef tree<F, S> tree_s;
    public:
        tree_s *root;
    public:
        Avl(): root(0) {
        }
        int calheight(tree_s *p)
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
            return 1;
        }

        int bf(tree_s *n)
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
            return (1337);
        }

        void Lr(tree_s **s)
        {
            tree_s *p;
            tree_s *tp;
            p = *s;
            tp = p->l;

            p->l = tp->r;
            tp->r = p;

            *s = tp;
            tp->l->h = calheight(tp->l);
            tp->r->h = calheight(tp->r);
            tp->h = calheight(tp);
        }

        void Rr(tree_s **s)
        {
            tree_s *p;
            tree_s *tp;
            p = *s;
            tp = p->r;

            p->r = tp->l;
            tp->l = p;

            *s = tp;
            tp->r->h = calheight(tp->r);
            tp->l->h = calheight(tp->l);
            tp->h = calheight(tp);
        }

        void RLr(tree_s **s)
        {
            //subchild rotation
            tree_s *p;
            tree_s *tp;
            tree_s *tp2;
            p = *s;
            tp = p->r;
            tp2 = p->r->l;

            p->r = tp2->l;
            tp->l = tp2->r;
            tp2->l = p;
            tp2->r = tp;

            *s = tp2;
            tp2->r->h = calheight(tp2->r);
            tp2->l->h = calheight(tp2->l);
            tp2->h = calheight(tp2);
        }

        void LRr(tree_s **s)
        {
            //subchild rotation
            tree_s *p;
            tree_s *tp;
            tree_s *tp2;

            p = *s;
            tp = p->l;
            tp2 = p->l->r;

            p->l = tp2->r;
            tp->r = tp2->l;
            tp2->r = p;
            tp2->l = tp;

            *s= tp2;
            tp2->l->h = calheight(tp2->l);
            tp2->r->h = calheight(tp2->r);
            tp2->h = calheight(tp2);
        }

        void insert(tree_s **pos, const value_t &p)
        {
            if ((*pos) == nullptr)
            {
                (*pos) = new tree<F, S>(p);
                (*pos)->h = 1;
                return ;
            }
            else
            {
                if (p < (*pos)->val)
                    insert(&((*pos)->l), p);
                else
                    insert(&((*pos)->r), p);
            }
            (*pos)->h = calheight(*pos);
            if(bf(*pos) == 2 && bf((*pos)->l) == 1)
                Lr(pos);
            else if(bf(*pos) == -2 && bf((*pos)->r) == -1)
                Rr(pos);
            else if(bf(*pos) == -2 && bf((*pos)->r) == 1)
                RLr(pos);
            else if(bf(*pos) == 2 && bf((*pos)->l) == -1)
                LRr(pos);
        }
        ~Avl(){}
    };

}
#endif
