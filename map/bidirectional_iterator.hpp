#pragma once
#ifndef BIDERECTIONAL_ITERATOR
#define BIDERECTIONAL_ITERATOR

template<class IT>
class biderectional_iterator {
  typedef typename IT::value_type rvalue;
  typedef typename IT::pointer pointer;
  typedef typename IT::reference reference;
  typedef biderectional_iterator iterator;
  typedef IT iterator_type;
public:
  iterator_type iterator_value;
public:
  biderectional_iterator(){}
  biderectional_iterator(const iterator_type &c): iterator_value(c)
  {}
  biderectional_iterator(const iterator &c): iterator_value(c.iterator_value)
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

  ~biderectional_iterator()
  {}
};


#endif
