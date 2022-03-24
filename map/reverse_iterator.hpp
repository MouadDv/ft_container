#pragma once
#ifndef REVERSE_ITERATOR_CLASS
#define REVERSE_ITERATOR_CLASS

#include "iterator_traits.hpp"

namespace ft
{

template <class Iterator>

class reverse_iterator
{
public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category 		iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type 				value_type;
	typedef typename ft::iterator_traits<Iterator>::reference 				reference;
	typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
	typedef typename ft::iterator_traits<Iterator>::difference_type			difference_type;

	reverse_iterator() : _it()
	{

	}

	explicit reverse_iterator (iterator_type it) :_it(it)
	{

	}

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it)
	{
		this->_it = rev_it.base();
	}

	iterator_type base() const
	{
		return (_it);
	}

	reference operator*() const
	{
		iterator_type tmp = _it;
        --tmp;
        return (*tmp);
	}

	pointer operator->() const
	{
		return &(operator*());
	}

	reference operator[] (difference_type n) const
	{
		return (base()[-n-1]);
	}
	reverse_iterator& operator--()
	{
		_it++;
		return (*this);
	}

	reverse_iterator  operator--(int)
	{
		 reverse_iterator tmp = *this;
		--(*this);
		return (tmp);
	}

	reverse_iterator& operator++()
	{
		_it--;
        return (*this);
	}

	reverse_iterator  operator++(int)
	{
		reverse_iterator tmp = *this;
		++(*this);
		return (tmp);
	}
	reverse_iterator operator+ (difference_type n) const
	{
		return reverse_iterator(_it - n);
	}

	reverse_iterator operator- (difference_type n) const
	{
		return reverse_iterator(_it + n);
	}

	reverse_iterator& operator+= (difference_type n)
	{
		_it -= n;
		return (*this);
	}
	reverse_iterator& operator-= (difference_type n)
	{
		_it += n;
		return (*this);
	}

	private:
		iterator_type _it;

};

//std::relational operators (reverse_iterator)
template <class Itr>
bool operator== (const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Itr>
bool operator!= (const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
{
	return !(lhs.base() == rhs.base());
}


template <class Itr>
bool operator<  (const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Itr>
bool operator<= (const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Itr>
bool operator>  (const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Itr>
bool operator>= (const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
{
	return (lhs.base() <= rhs.base());
}

// Addition operator
template <class Itr>
reverse_iterator<Itr> operator+ ( typename reverse_iterator<Itr>::difference_type n,
            const reverse_iterator<Itr>& rev_it)
{
	return reverse_iterator<Itr>(rev_it.base() - n);
}

//Subtraction operator

template <class Itr>
reverse_iterator<Itr> operator- ( typename reverse_iterator<Itr>::difference_type n,
            const reverse_iterator<Itr>& rev_it)
{
	return reverse_iterator<Itr>(rev_it.base() + n);
}

template <class Itr>
typename reverse_iterator<Itr>::difference_type operator- (
    const reverse_iterator<Itr>& lhs,
    const reverse_iterator<Itr>& rhs)
{
	return (rhs.base() - lhs.base());
}
}
#endif
