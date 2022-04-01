#pragma once 
#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> > class stack;
}

template <class T, class Container> 
class ft::stack
{
public:
	// Attributes
	typedef T			value_type;		// Type of the elements
	typedef Container	container_type;	// Type of the underlying container
	typedef std::size_t	size_type;		// 	usually the same as size_t
	
	/* Member functions */

	// Constructors/Destructor
	explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
	{

	}

	bool empty() const
	{
		// This member function effectively calls member empty of the underlying container object.
		return c.empty();
	}

	size_type size() const
	{
		// This member function effectively calls member size of the underlying container object.
		return c.size();
	}

	value_type& top()
	{
		// This member function effectively calls member back of the underlying container object.
		return c.back();
	}

	const value_type& top() const
	{
		return c.back();
	}

	void push (const value_type& val)
	{
		// This member function effectively calls the member function push_back of the underlying container object.
		c.push_back(val);
	}

	void pop()
	{
		// This member function effectively calls the member function pop_back of the underlying container object.
		c.pop_back();
	}

	/* Non-member function overloads */
	// Each of these operator overloads calls the same operator on the underlying container objects.
	template <class Tp, class Cntr>
	friend bool operator== (const ft::stack<Tp,Cntr>& lhs, const ft::stack<Tp,Cntr>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class Tp, class Cntr>
	friend bool operator!= (const ft::stack<Tp,Cntr>& lhs, const ft::stack<Tp,Cntr>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class Tp, class Cntr>
	friend bool operator<  (const ft::stack<Tp,Cntr>& lhs, const ft::stack<Tp,Cntr>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class Tp, class Cntr>
	friend bool operator<= (const ft::stack<Tp,Cntr>& lhs, const ft::stack<Tp,Cntr>& rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class Tp, class Cntr>
	friend bool operator>  (const ft::stack<Tp,Cntr>& lhs, const ft::stack<Tp,Cntr>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class Tp, class Cntr>
	friend bool operator>= (const ft::stack<Tp,Cntr>& lhs, const ft::stack<Tp,Cntr>& rhs)
	{
		return (lhs.c >= rhs.c);
	}

protected:
	container_type c;
};
