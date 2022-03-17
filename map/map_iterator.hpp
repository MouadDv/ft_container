#pragma once
#ifndef MAP_ITERATOR
#define MAP_ITERATOR

#include <cstddef>
#include "avl.hpp"
#include "pair.hpp"
#include "iterator_traits.hpp"

namespace ft
{
template <typename P, typename V>
class map_iterator {
public:
  typedef P                                                              pointer;
  typedef V                                                              value_type;
  typedef typename value_type::key_type                                  key_type;
  typedef typename value_type::mapped_type                               mapped_type;
  typedef std::bidirectional_iterator_tag                                iterator_category;
  typedef value_type*                                                    value_pointer;
  typedef value_type&                                                    reference;
  typedef ptrdiff_t                                                      difference_type;

private:
  pointer root;
  pointer return_node;
  pointer end_node;



  pointer most_left(pointer c)
  {
    while (c != NULL)
      c = c->left;
    return (c);
  }

  pointer most_right(pointer c)
  {
    while (c != NULL)
      c = c->right;
    return (c);
  }

public:
  map_iterator(): root(NULL), return_node(NULL), end_node(NULL)
  {
  }
  map_iterator(const pointer croot, const pointer creturn, const pointer cend): root(croot), return_node(creturn), end_node(cend)
  {
  }
  map_iterator(const map_iterator &c): root(c.root), return_node(c.return_node), end_node(c.end_node)
  {
  }


  map_iterator& operator=(const map_iterator &c)
  {
    this->root = c.root;
    this->return_node = c.return_node;
    this->end_node = c.end_node;

    return (*this);
  }

  bool operator==(const map_iterator& iterator) const
  {
    return (this->return_node == iterator.return_node);
  }

  bool operator!=(const map_iterator& iterator) const
  {
    return !(*this == iterator);
  }

  map_iterator operator++(int)
  {
    map_iterator ret(*this);
    ++(*this);
    return (ret);
  }

  map_iterator& operator++()
  {
    pointer tmp;

    if (return_node->r != NULL)
      return_node = mostleft(return_node->r);
    else
    {
      tmp = return_node->l;
      while (tmp != NULL && return_node == tmp->r)
      {
        return_node = tmp;
        tmp = tmp->parent;
      }
      return_node = tmp;
    }
    if (return_node == NULL)
    {
      return_node = end_node;
    }
    return (*this);
  }

  map_iterator operator--(int)
  {
    map_iterator ret(*this);
    --(*this);
    return (ret);
  }

  map_iterator& operator--()
  {
    pointer tmp;

    if (return_node == end_node)
    {
      return_node = end_node->parent;
      return (*this);
    }
    else if (return_node->l != NULL)
      return_node = mostright(return_node->r);\
    else
    {
      tmp = return_node->parent;
      while (tmp != NULL && return_node == tmp->l)
      {
        return_node = tmp;
        tmp = tmp->parent;
      }
      return_node = tmp;
    }
    return (*this);
  }

  reference operator*() const
  {
    return (return_node->val);
  }

  value_pointer operator->() const
  {
    return (&operator*());
  }

  pointer mostleft(pointer c)
  {
    while (c != NULL)
      c = c->l;
    return (c);
  }

  pointer mostright(pointer c)
  {
    while (c != NULL)
      c = c->r;
    return (c);
  }

  ~map_iterator()
  {
  }

};



}


#endif
