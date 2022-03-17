#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include "pair.hpp"
#include "avl.hpp"
#include "map_iterator.hpp"
//#include "bidirectional_iterator.hpp"

namespace ft
{
  template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           >
  class map {
  public:
    typedef Key                                                              key_type;
    typedef T                                                                mapped_type;
    typedef Compare                                                          key_compare;
    typedef Alloc                                                            allocator_type;
    typedef ft::pair<const Key, T>                                           value_type;
    typedef typename allocator_type::pointer                                 pointer;
    typedef typename allocator_type::reference                               reference;
    typedef Avl<key_type, mapped_type, Compare, Alloc>                       base_type;
    typedef typename allocator_type::template rebind<base_type>::other       alloc_base;
    typedef size_t                                                           size_type;
    typedef typename ft::Avl<key_type, mapped_type, Compare, Alloc>::tree_s* avlpointer;
    typedef ft::map_iterator<avlpointer , value_type>                        iterator;
    //TODO const_iterator declaration
    typedef ft::map_iterator<avlpointer , value_type>                        const_iterator;



class value_compare
{
  friend class map;
  protected:
    Compare comp;
    value_compare (Compare c) : comp(c) {}
  public:
    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;
    bool operator() (const value_type& x, const value_type& y) const
    {
      return comp(x.first, y.first);
    }
};

  private:
    base_type       *base_tree;
    alloc_base       baseallocator;
    key_compare      comp;
    allocator_type   alloc;
    size_type        _size;
  public:
    explicit map (const key_compare& com = key_compare(),
              const allocator_type& alctr = allocator_type())
      {
        this->base_tree = baseallocator.allocate(1);
        baseallocator.construct(this->base_tree, base_type());
        this->alloc = alctr;
        this->comp = com;
        this->_size = 0;
      }

    template <class InputIterator>
    map (InputIterator first, InputIterator last,
       const key_compare& com = key_compare(),
       const allocator_type& alctr = allocator_type())
      {
        this->base_tree = baseallocator.allocate(1);
        baseallocator.construct(this->base_tree, base_type());
        this->alloc = alctr;
        this->comp = com;
        this->_size = 0;
        insert(first, last);
      }
    map (const map& x)
      {
        this->alloc = x.alloc;
        this->_size = x._size;
        this->comp = x.comp;
        this->base_tree = baseallocator.allocate(1);
        baseallocator.construct(*this->base_tree, base_type(*(x.base_tree)));
      }

    ft::pair<iterator,bool>insert (const value_type& val) // single element (1)
    {
      base_tree->insert(&(base_tree->root), val, NULL);
      _size++;
      return(ft::make_pair(iterator(base_tree->root, base_tree->mostleft(base_tree->root), base_tree->el), 1));
    }

    iterator begin()
    {
      return (iterator(base_tree->root, base_tree->mostleft(base_tree->root), base_tree->el));
    }

    ~map()
      {}

  };
}

#endif
