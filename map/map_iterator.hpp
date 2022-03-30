#pragma once
#ifndef MAP_ITERATOR
#define MAP_ITERATOR

#include <cstddef>
#include "../utils/avl.hpp"
#include "../utils/pair.hpp"
#include "../utils/iterator_traits.hpp"

namespace ft
{
template <typename P, typename V>
class map_iterator {
public:
  typedef P                                                              treepointer;
  typedef V                                                              value_type;
  typedef typename value_type::key_type                                  key_type;
  typedef typename value_type::mapped_type                               mapped_type;
  typedef std::bidirectional_iterator_tag                                iterator_category;
  typedef value_type*                                                    pointer;
  typedef value_type&                                                    reference;
  typedef ptrdiff_t                                                      difference_type;
  typedef map_iterator<P, const V>                                       const_iterator;

private:
  treepointer root;
  treepointer return_node;
  treepointer end_node;


  treepointer most_left(treepointer c)
  {
    while (c != NULL)
      c = c->left;
    return (c);
  }

  treepointer most_right(treepointer c)
  {
    while (c != NULL)
      c = c->right;
    return (c);
  }

public:
  map_iterator(): root(NULL), return_node(NULL), end_node(NULL)
  {
  }
  map_iterator(const treepointer croot, const treepointer creturn, const treepointer cend): root(croot), return_node(creturn), end_node(cend)
  {
  }
  map_iterator(const map_iterator &c): root(c.root), return_node(c.return_node), end_node(c.end_node)
  {
  }

  operator const_iterator()
  {
    return const_iterator(root, return_node, end_node);
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
    treepointer tmp;
    if (return_node->r != NULL)
    {
      return_node = return_node->r;
      return_node = mostleft(return_node);
    }
    else
    {
      tmp = return_node->parent;
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
    treepointer tmp;

    if (return_node == end_node)
    {
      return_node = end_node->parent;
      return (*this);
    }
    else if (return_node->l != NULL)
      return_node = mostright(return_node->l);
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

  pointer operator->() const
  {
    return (&operator*());
  }
private:
  treepointer mostleft(treepointer c)
  {
    while (c->l != NULL)
      c = c->l;
    return (c);
  }

  treepointer mostright(treepointer c)
  {
    while (c->r != NULL)
      c = c->r;
    return (c);
  }
public:
  ~map_iterator()
  {
  }

};



}


#endif
