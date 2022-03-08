#pragma once
#ifndef BIDERECTIONAL_ITERATOR
#define BIDERECTIONAL_ITERATOR

#include "iterator_traits.hpp"

template<class IT>
class bidirectional_iterator {
  typedef typename ft::iterator_traits<IT>::value_type value_type;
  typedef typename ft::iterator_traits<IT>::pointer pointer;
  typedef typename ft::iterator_traits<IT>::reference reference;
  typedef bidirectional_iterator iterator;
public:
  iterator iterator_value;
public:
  bidirectional_iterator(){}
  bidirectional_iterator(const value_type &c): iterator_value(c)
  {}
  bidirectional_iterator(const iterator &c): iterator_value(c.iterator_value)
  {}
  const iterator &operator=(const iterator &c)
  {
    this->iterator_value = c.iterator_value;
    return (*this);
  }

  // operators

  bool operator==(const iterator &c)
  {
    return (this->iterator_value == c.iterator_value);
  }

  bool operator!=(const iterator &c)
  {
    return (this->iterator_value != c.iterator_value);
  }

  reference operator*()
  {
    return (this->iterator_value.operator*());
  }

  pointer operator->()
  {
    return (this->iterator_value.operator->());
  }

  iterator &operator++()
  {
    ++this->iterator_value;

    return (*this);
  }

  iterator operator++(int)
  {
    iterator tmp(*this);
    ++(*this);

    return (tmp);
  }

  iterator &operator--()
  {
    --this->iterator_value;

    return (*this);
  }

  iterator operator--(int)
  {
    iterator tmp(*this);
    --(*this);

    return (tmp);
  }

  ~bidirectional_iterator()
  {}
};


#endif
