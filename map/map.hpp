#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS

#include "pair.hpp"

namespace ft
{
  template < class Key,                                     // map::key_type
           class T                                       // map::mapped_type
           //class Compare = less<Key>,                     // map::key_compare
           //class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           >
  class map {
  public:
    typedef ft::pair<const Key, T> value_type;
    typedef map* pointer;
    typedef map& reference;
  public:

    map();
    virtual ~map();

  };
}

#endif
