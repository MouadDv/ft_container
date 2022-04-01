#pragma once
#ifndef TREE_CLASS
#define TREE_CLASS

#include "pair.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>

namespace ft
{
    template <class T1>
    struct tree {
        typedef T1 value_t;
        typedef tree<T1> tree_s;

        tree_s *parent;
        tree_s *r;
        tree_s *l;
        int     h;
        value_t val;

        tree(): parent(NULL), r(NULL), l(NULL), val(value_t()) {}
        tree(const value_t &p): parent(NULL), r(NULL), l(NULL), val(p) {}
        tree(const tree &p): parent(p.parent), r(p.r), l(p.l), h(p.h), val(p.val) {}
    };

    template <typename F, typename S, typename key_comp, typename Alloc>
    class Avl {
    public:
        typedef ft::pair<const F, S> value_t;
        typedef tree<value_t> tree_s;
        typedef typename Alloc::template rebind<tree<value_t> >::other  alloc_type;
    public:
        alloc_type alloc;
        key_comp comp;
        tree_s *root;
        tree_s *el;
    public:
        Avl(): root(NULL)
        {
            this->el = alloc.allocate(1);
        }
        Avl(const Avl &c)
        {
            this->alloc=c.alloc;
            this->comp = c.comp;
            this->root = copy_tree(c.root, NULL);
            this->el = alloc.allocate(1);
            if (this->root != NULL)
                this->el->parent = mostright(this->root);
        }

        tree_s *copy_tree(tree_s *c, tree_s *par)
        {
            if (c == NULL)
                return (NULL);
            tree_s *ret = this->alloc.allocate(1);
            this->alloc.construct(ret, tree_s(*c));
            ret->parent = par;
            ret->l = copy_tree(c->l, ret);
            ret->r = copy_tree(c->r, ret);
            return (ret);
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
               return p->l->h + 1;
            else if(p->l ==NULL && p->r)
               return p->r->h + 1;
            return 1;
        }

        int bf(tree_s *&n)
        {
            if (n)
            {
                if(n->l && n->r)
                    return n->l->h - n->r->h;
                else if(n->l && n->r == NULL)
                    return n->l->h;
                else if(n->l == NULL && n->r )
                    return -(n->r->h);
            }
            return (0);
        }

        void parent_set(tree_s *&n, tree_s *p)
        {
            if (n == NULL)
                return ;
            parent_set(n->r, n);
            n->parent = p;
            parent_set(n->l, n);
        }

        tree_s *Lr(tree_s *&s)
        {
            tree_s *p;
            tree_s *tp;
            p = s;
            tp = p->l;

            p->l = tp->r;
            tp->r = p;

            parent_set(tp, s->parent);

            tp->l->h = calheight(tp->l);
            tp->r->h = calheight(tp->r);
            tp->h = calheight(tp);
            return tp;
        }

        tree_s *Rr(tree_s *&s)
        {
            tree_s *p;
            tree_s *tp;
            p = s;
            tp = p->r;

            p->r = tp->l;
            tp->l = p;

            parent_set(tp, s->parent);

            tp->r->h = calheight(tp->r);
            tp->l->h = calheight(tp->l);
            tp->h = calheight(tp);
            return tp;
        }

        tree_s *RLr(tree_s *&s)
        {
            tree_s *p;
            tree_s *tp;
            tree_s *tp2;
            p = s;
            tp = p->r;
            tp2 = p->r->l;

            p->r = tp2->l;
            tp->l = tp2->r;
            tp2->l = p;
            tp2->r = tp;

            parent_set(tp2, s->parent);

            tp2->r->h = calheight(tp2->r);
            tp2->l->h = calheight(tp2->l);
            tp2->h = calheight(tp2);
            return tp2;
        }

        tree_s *LRr(tree_s *&s)
        {
            tree_s *p;
            tree_s *tp;
            tree_s *tp2;

            p = s;
            tp = p->l;
            tp2 = p->l->r;

            p->l = tp2->r;
            tp->r = tp2->l;
            tp2->r = p;
            tp2->l = tp;

            parent_set(tp2, s->parent);

            tp2->l->h = calheight(tp2->l);
            tp2->r->h = calheight(tp2->r);
            tp2->h = calheight(tp2);
            return tp2;
        }

        void insert(tree_s *&pos, const value_t &p, tree_s *pa)
        {
            if (pos == NULL)
            {
                pos = alloc.allocate(1);
                alloc.construct(pos, p);
                pos->h = 1;
                pos->parent = pa;
                return ;
            }
            else
            {
                if (p.first == pos->val.first)
                    return ;
                else if (!comp(pos->val.first, p.first))
                    insert(pos->l, p, pos);
                else if (!comp(p.first, pos->val.first))
                    insert(pos->r, p, pos);
            }
            pos->h = calheight(pos);
            if(bf(pos) == 2 && bf(pos->l) == 1)
                pos = Lr(pos);
            else if(bf(pos) == -2 && bf(pos->r) == -1)
                pos = Rr(pos);
            else if(bf(pos) == -2 && bf(pos->r) == 1)
                pos = RLr(pos);
            else if(bf(pos) == 2 && bf(pos->l) == -1)
                pos = LRr(pos);
            this->el->parent = mostright(this->root);
        }

        tree_s *erase(tree_s *&t, const F &d)
        {
            if(t == NULL)
                return NULL;
            if (comp(t->val.first, d))
                t->r = erase(t->r, d);
            else if (comp(d , t->val.first))
                t->l = erase(t->l, d);
            else
            {
                if (t->l != NULL)
                {
                    tree_s *d = t;
                    tree_s *tmp;
                    tmp = mostright(t->l);
                    t = alloc.allocate(1);
                    alloc.construct(t, *tmp);
                    t->r = d->r;
                    t->parent = d->parent;
                    t->l = erase(d->l, tmp->val.first);
                    alloc.destroy(d);
                    alloc.deallocate(d, 1);
                }
                else if (t->r != NULL)
                {
                    tree_s *d = t;
                    tree_s *tmp;
                    tmp = mostleft(t->r);
                    t = alloc.allocate(1);
                    alloc.construct(t, *tmp);
                    t->l = d->l;
                    t->parent = d->parent;
                    t->r = erase(d->r, tmp->val.first);
                    alloc.destroy(d);
                    alloc.deallocate(d, 1);
                }
                else
                {
                    alloc.destroy(t);
                    alloc.deallocate(t, 1);
                    return NULL;
                }
            }
            t->h = calheight(t);
            if (t->l)
                t->l->h = calheight(t->l);
            if (t->r)
                t->r->h = calheight(t->r);
            if(bf(t) > 1 && bf(t->l) >= 0)
                t = Lr(t);
            else if(bf(t) < -1 && bf(t->r) <= 0)
                t = Rr(t);
            else if(bf(t) < -1 && bf(t->r) > 0)
                t = RLr(t);
            else if(bf(t) > 1 && bf(t->l) < 0)
                t = LRr(t);

            if (t->l)
                t->l->parent = t;
            if (t->r)
                t->r->parent = t;
            return t;
        }
public:
        tree_s *mostleft(tree_s *s)
        {
            if (s == NULL)
                return (s);
            while (s->l != NULL)
                s = s->l;
            return (s);
        }

        tree_s *mostright(tree_s *s)
        {
            if (s == NULL)
                return (s);
            while (s->r != NULL)
                s = s->r;
            return (s);
        }

        void clear(tree_s *&t)
        {
            if (t == NULL)
                return ;
            clear(t->l);
            clear(t->r);
            alloc.destroy(t);
            alloc.deallocate(t, 1);
            t = NULL;
        }
		
        ~Avl()
        {
            alloc.deallocate(el, 1);
        }
    };

}
#endif
