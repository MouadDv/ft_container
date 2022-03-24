#pragma once
#ifndef MAP_CLASS
#define MAP_CLASS

#include <iostream>
#include "pair.hpp"
#include "avl.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "is_integral.hpp"

namespace ft
{
	template<bool Cond, class T = void> struct enable_if;

	template<class T> 
	struct enable_if<true, T> { typedef T type; };
}

namespace ft
{
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) 
				return false;
			else if (*first1<*first2) 
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
	template <class InputIterator1, class InputIterator2, class Compare>
 	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1!=last1)
		{
			if (first2==last2 || comp(*first2, *first1)) 
				return false;
			else if (comp(*first1, *first2)) 
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

}

namespace ft
{
	// equality
	template <class InputIterator1, class InputIterator2>
 	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
	// predicate
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1)
		{
			if (!pred(*first1,*first2)) 
				return false;
			++first1; ++first2;
		}
		return true;
	}

}

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
    typedef typename base_type::tree_s                                       treepointer;
    typedef typename allocator_type::template rebind<base_type>::other       alloc_base;
    typedef size_t                                                           size_type;
    typedef typename ft::Avl<key_type, mapped_type, Compare, Alloc>::tree_s* avlpointer;
    typedef ft::map_iterator<avlpointer , value_type>                        iterator;
    typedef ft::map_iterator<avlpointer , const value_type>                  const_iterator;
    typedef ft::reverse_iterator<iterator>                                   reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                             const_reverse_iterator;



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
      baseallocator.construct(this->base_tree, *(x.base_tree));
    }

    iterator ret_it(const key_type& k)
    {
      if (base_tree->root != NULL)
      {
        treepointer *tmp = base_tree->root;
        while (tmp)
        {
          if (comp(k, tmp->val.first) == true)
            tmp = tmp->l;
          else if (comp(tmp->val.first, k) == true)
            tmp = tmp->r;
          else {
            return (iterator(base_tree->root, tmp, base_tree->el));
          }
        }
      }
      return (end());
    }

	const_iterator ret_it(const key_type& k) const
    {
      if (base_tree->root != NULL)
      {
        treepointer *tmp = base_tree->root;
        while (tmp)
        {
          if (comp(k, tmp->val.first) == true)
            tmp = tmp->l;
          else if (comp(tmp->val.first, k) == true)
            tmp = tmp->r;
          else {
            return (iterator(base_tree->root, tmp, base_tree->el));
          }
        }
      }
      return (end());
    }

    ft::pair<iterator,bool>insert (const value_type& val) // single element (1)
    {
      base_tree->insert(&(base_tree->root), val, NULL);
      _size++;

      return(ft::make_pair(ret_it(val.first), 1));
    }

    iterator insert (iterator position, const value_type& val)
    {
      (void)position;
      return ((this->insert(val)).first);
    }

    template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      while (first != last)
      {
        this->insert(*first);
        first++;
      }
    }

    iterator begin()
    {
      return (iterator(base_tree->root, base_tree->mostleft(base_tree->root), base_tree->el));
    }

    const_iterator begin() const
    {
      return (const_iterator(base_tree->root, base_tree->mostleft(base_tree->root), base_tree->el));
    }

    iterator end()
    {
      return (iterator(base_tree->root, base_tree->el, base_tree->el));
    }

    const_iterator end() const
    {
      return (const_iterator(base_tree->root, base_tree->el, base_tree->el));
    }

    reverse_iterator rbegin()
    {
      return (reverse_iterator(end()));
    }

    const_reverse_iterator rbegin() const
    {
      return (const_reverse_iterator(end()));
    }

    reverse_iterator rend()
    {
      return (reverse_iterator(begin()));
    }

    const_reverse_iterator rend() const
    {
      return (const_reverse_iterator(begin()));
    }

    bool empty() const
    {
      if (this->_size == 0)
        return (0);
      return (1);
    }

    size_type size() const
    {
      return (this->_size);
    }

    size_type max_size() const
    {
      return (Alloc::template rebind<base_type>.max_size());
    }

    mapped_type& operator[] (const key_type& k)
    {
      return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
    }

    void erase (iterator position)
    {
      if (this->empty() == true)
        return ;
      base_tree->erase(base_tree->root, (*position).first);
    }

    size_type erase (const key_type& k)
    {
      if (this->empty() == true)
        return 0;
      if (ret_it(k) == end())
        return 0;
      base_tree->erase(base_tree->root, k);
      return 1;
    }

    void erase (iterator first, iterator last)
    {
      if (this->empty() == true)
        return ;
      while (first != last)
      {
        this->erase(first);
        first++;
      }
    }

    void swap (map& x)
    {
      base_type *tmp = this->base_tree;
      size_type sizetmp = this->_size;
      this->base_tree = x.base_tree;
      this->_size = x._size;
      x.base_tree = tmp;
      x._size = sizetmp;
    }

    void clear()
    {
      this->base_tree->clear(base_tree->root);
    }

    key_compare key_comp() const
    {
      return (comp);
    }
    value_compare value_comp() const
    {
      return (value_compare(comp));
    }

    iterator find (const key_type& k)
    {
      return (ret_it(k));
    }

    const_iterator find (const key_type& k) const
    {
      return (ret_it(k));
    }

    size_type count (const key_type& k) const
    {
      if (find(k) != end())
        return 1;
      return 0;
    }

    iterator lower_bound (const key_type& k) // edit return to return iterator
    {
      treepointer *tmp = base_tree->root;
      iterator last = end();
      last--;

      while (tmp != NULL)
      {
        if (k == tmp->val.first)
          return (iterator(base_tree->root, tmp, base_tree->el));
        else if (comp(k, tmp->val.first) == true)
        {
          if (tmp->l == NULL)
            break ;
          tmp = tmp->l;
        }
        else if (comp(k, tmp->val.first) == false)
        {
          if (tmp->r == NULL)
            break ;
          tmp = tmp->r;
        }
      }
      if (comp(k, tmp->val.first) == false)
      {
        while (tmp->parent != NULL && comp(k, tmp->val.first) == false)
          tmp = tmp->parent;
        return (iterator(base_tree->root, tmp, base_tree->el));
      }
      else if (k < last->first && comp(k, tmp->val.first) == true)
        return (iterator(base_tree->root, tmp, base_tree->el));
      return end();
    }

    const_iterator lower_bound (const key_type& k) const
    {
      treepointer *tmp = base_tree->root;
      const_iterator last = this->end();
      last--;

      while (tmp != NULL)
      {
        if (k == tmp->val.first)
          return (const_iterator(base_tree->root, tmp, base_tree->el));
        else if (comp(k, tmp->val.first) == true)
        {
          if (tmp->l == NULL)
            break ;
          tmp = tmp->l;
        }
        else if (comp(k, tmp->val.first) == false)
        {
          if (tmp->r == NULL)
            break ;
          tmp = tmp->r;
        }
      }
      if (comp(k, tmp->val.first) == false)
      {
        while (tmp->parent != NULL && comp(k, tmp->val.first) == false)
          tmp = tmp->parent;
        return (const_iterator(base_tree->root, tmp, base_tree->el));
      }
      else if (k < last->first && comp(k, tmp->val.first) == true)
        return (const_iterator(base_tree->root, tmp, base_tree->el));
      return end();
    }


    iterator upper_bound (const key_type& k)
    {
      treepointer *tmp = base_tree->root;
      iterator last = end();
      last--;

      while (tmp != NULL)
      {
        if (k == tmp->val.first)
        {
          iterator ret(base_tree->root, tmp, base_tree->el);
          return (++ret);
        }
        else if (comp(k, tmp->val.first) == true)
        {
          if (tmp->l == NULL)
            break ;
          tmp = tmp->l;
        }
        else if (comp(k, tmp->val.first) == false)
        {
          if (tmp->r == NULL)
            break ;
          tmp = tmp->r;
        }
      }
      if (comp(k, tmp->val.first) == false)
      {
        while (tmp->parent != NULL && comp(k, tmp->val.first) == false)
          tmp = tmp->parent;
        return (iterator(base_tree->root, tmp, base_tree->el));
      }
      else if (k < last->first && comp(k, tmp->val.first) == true)
        return (iterator(base_tree->root, tmp, base_tree->el));
      return end();
    }

    const_iterator upper_bound (const key_type& k) const
    {
      treepointer *tmp = base_tree->root;
      const_iterator last = end();
      last--;

      while (tmp != NULL)
      {
        if (k == tmp->val.first)
        {
          const_iterator ret(base_tree->root, tmp, base_tree->el);
          return (++ret);
        }
        else if (comp(k, tmp->val.first) == true)
        {
          if (tmp->l == NULL)
            break ;
          tmp = tmp->l;
        }
        else if (comp(k, tmp->val.first) == false)
        {
          if (tmp->r == NULL)
            break ;
          tmp = tmp->r;
        }
      }
      if (comp(k, tmp->val.first) == false)
      {
        while (tmp->parent != NULL && comp(k, tmp->val.first) == false)
          tmp = tmp->parent;
        return (const_iterator(base_tree->root, tmp, base_tree->el));
      }
      else if (k < last->first && comp(k, tmp->val.first) == true)
        return (const_iterator(base_tree->root, tmp, base_tree->el));
      return end();
    }


    ft::pair<iterator, iterator>  equal_range (const key_type& k)
    {
      return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
    }

    ft::pair<const_iterator, const_iterator>  equal_range (const key_type& k) const
    {
      return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
    }

    allocator_type get_allocator() const
    {
      return alloc;
    }

    ~map()
      {}

  };
}
  template <class Key, class T, class Compare, class Alloc>
  bool operator== ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
  {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
  }

  template <class Key, class T, class Compare, class Alloc>
  bool operator!= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const ft::map<Key,T,Compare,Alloc>& lhs,
						const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
  bool operator<= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
  bool operator>  ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return rhs < lhs;
	}
	template <class Key, class T, class Compare, class Alloc>
  bool operator>= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
  void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
  {
	  x.swap(y);
  }


#endif
