#include <iostream>
#include "../utils/iterator_traits.hpp"
#include "../utils/enable_if.hpp"
#include <type_traits>
#include <new>
#include <iostream>
#include <string>
#pragma once
template <typename T>

class RandomAccessIterator
{
public:
	typedef typename ft::iterator_traits<T*>::value_type 		value_type;
	typedef typename ft::iterator_traits<T*>::reference 		reference;
	typedef typename ft::iterator_traits<T*>::pointer			pointer;
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
	typedef RandomAccessIterator<const T>						const_iterator;		

	/*
		Is default-constructible, copy-constructible, copy-assignable and destructible
		X a;
		X b(a);
		b = a;
	*/
	operator const_iterator()
	{
		return (const_iterator(_ptr));
	}

	RandomAccessIterator(void) : _ptr(NULL)
	{

	}
	RandomAccessIterator(pointer ptr) : _ptr(ptr)
	{

	}
	RandomAccessIterator(RandomAccessIterator const & src)
	{
		*this = src;
	}

	RandomAccessIterator & operator=(RandomAccessIterator const & rhs)
	{
		this->_ptr = rhs._ptr;
		return (*this);
	}

	// template<bool was_const = IsConst, class = ft::enable_if<IsConst || !was_const>>
    // RandomAccessIterator(RandomAccessIterator<T,was_const>  const & rhs) : _ptr(rhs.getConstPtr()) 
	// {

	// }

    // template<bool WasConst, class = ft::enable_if<IsConst && !WasConst>>
    // RandomAccessIterator& operator=(RandomAccessIterator<T,WasConst>const & rhs)
	// { 
	// 	this->_ptr = rhs._ptr;
	// 	return *this;
	// }
	
	~RandomAccessIterator()
	{

	}
	/*
		Can be compared for equivalence using the equality/inequality operators
		(meaningful when both iterator values iterate over the same underlying sequence) .
		a == b
		a != b
	*/
	bool operator==(const RandomAccessIterator & it) const 
	{ 
		return this->_ptr == it._ptr; 
	}
	bool operator!=(const RandomAccessIterator & it) const 
	{ 
		return this->_ptr != it._ptr; 
	}
	/* 
		Can be dereferenced as an rvalue (if in a dereferenceable state).
		*a
		a->m 
	*/
	reference operator* () 
	{ 
		return *_ptr; 
	}
	pointer   operator->() 
	{ 
		return  _ptr; 
	}

	/* 
		For mutable iterators (non-constant iterators):
		Can be dereferenced as an lvalue (if in a dereferenceable state).
		*a = t
	*/
	reference operator=(reference rhs) 
	{
		*_ptr = rhs;
		return (*_ptr);
	}

	/* 
		Can be incremented (if in a dereferenceable state).
		The result is either also dereferenceable or a past-the-end iterator.
		Two iterators that compare equal, keep comparing equal after being both increased.
		++a
		a++
		*a++
	*/
	RandomAccessIterator & operator++() 
	{
		_ptr++;
		return *this; 
	}
	RandomAccessIterator operator++(int)
	{
		RandomAccessIterator tmp(*this);
		++_ptr;
		return tmp;
	}

	/*
		Can be decremented (if a dereferenceable iterator value precedes it).
		--a
		a--
		*a--
		*/
    RandomAccessIterator & operator--() 
	{ 
		_ptr--;
		return *this; 
	}
	RandomAccessIterator operator--(int) 
	{
		RandomAccessIterator tmp(*this);
		--_ptr;
		return tmp;
	}

	/* 
		Supports the arithmetic operators + and - between an iterator and an integer value, 
		or subtracting an iterator from another.
		a + n  
		n + a
		a - n
		a - b
	*/
	// RandomAccessIterator operator+(const difference_type & other) const // a + n
	// {
	// 	return RandomAccessIterator(_ptr + other);
	// }
	RandomAccessIterator operator+(int other) const // a + n
	{
		return RandomAccessIterator(_ptr + other);
	}
	friend RandomAccessIterator operator+(const difference_type & n, const RandomAccessIterator & it) // n + a
	{
			return RandomAccessIterator(n + it._ptr);
	}
	
	RandomAccessIterator operator-(const difference_type & other) const // a - n
	{
		return RandomAccessIterator(_ptr - other);
	}
	difference_type operator-(const RandomAccessIterator & it) const // a - b
	{
		return (_ptr - it._ptr);
	}
	/*
		Can be compared with inequality relational operators (<, >, <= and >=).
		a < b
		a > b
		a <= b
		a >= b
	*/
	
	bool operator<(const RandomAccessIterator & other_it) const
	{
		return (_ptr < other_it._ptr);
	}
	bool operator>(const RandomAccessIterator & other_it) const
	{
		return (_ptr > other_it._ptr);
	}
	bool operator<=(const RandomAccessIterator & other_it) const
	{
		return (_ptr <= other_it._ptr);
	}
	bool operator>=(const RandomAccessIterator & other_it) const
	{
		return (_ptr >= other_it._ptr);
	}
	/*
		Supports compound assignment operations += and -=
		a += n
		a -= n
	*/
	RandomAccessIterator & operator+=(difference_type n)
	{
		_ptr += n;
		return (*this);
	}
	RandomAccessIterator & operator-=(difference_type n)
	{
		_ptr -= n;
		return (*this);
	}
	/*
		Supports the offset dereference operator ([])
		a[n]
	*/
	reference operator[](const difference_type & n)
	{
		return (_ptr[n]);
	}
	pointer getPtr() const
	{
		return _ptr;
	}
	const pointer getConstPtr() const
	{
		return (_ptr);
	}
	
private:
		T* _ptr;
};
