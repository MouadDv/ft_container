#pragma once
#ifndef RANDOMACCESS_ITERATOR
#define RANDOMACCESS_ITERATOR

#include "bidirectional_iterator.hpp"

template<class IT>
class randomaccess_iterator: public bidirectional_iterator<IT>
{
  typedef randomaccess_iterator iterator;
public:
  bool operator<(const iterator &cp)
  {
    return (this->iterator_value < cp.iterator_value);
  }

  bool operator>(const iterator &cp)
  {
    return (this->iterator_value > cp.iterator_value);
  }

  bool operator<=(const iterator &cp)
  {
    return (this->iterator_value <= cp.iterator_value);
  }

  bool operator>=(const iterator &cp)
  {
    return (this->iterator_value >= cp.iterator_value);
  }

  iterator operator+(const iterator& rhs)
  {
    return iterator(this->iterator_value + rhs.iterator_value);
  }

  iterator operator-(const iterator& rhs)
  {
    return iterator(this->iterator_value - rhs.iterator_value);
  }

  iterator operator+(const int& rhs)
  {
    return iterator(this->iterator_value + rhs);
  }

  iterator operator-(const int& rhs)
  {
    return Iterator(this->iterator_value - rhs);
  }

  iterator& operator+=(const int& rhs)
  {
    this->iterator_value += rhs;
    return (*this);
  }

  iterator& operator-=(const int& rhs)
  {
    this->iterator_value -= rhs;
    return (*this);
  }
};


#endif
