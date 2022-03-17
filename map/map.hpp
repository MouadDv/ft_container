#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include "pair.hpp"
#include "avl.hpp"
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
    typedef Key                                    key_type;
    typedef T                                      mapped_type;
    typedef Compare                                key_compare;
    typedef Alloc                                  allocator_type;
    typedef ft::pair<const Key, T>                 value_type;
    typedef typename allocator_type::pointer       pointer;
    typedef typename allocator_type::reference     reference;
    //typedef std::bidirectional_iterator_tag        iterator_category;

  private:
    Avl<key_type, mapped_type> tree;

  public:
    map();
    virtual ~map();

  };
}

#endif
