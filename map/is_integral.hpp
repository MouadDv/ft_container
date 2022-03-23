#pragma once

template<class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T, v> type;
  operator value_type() const { return value; }
};

template <class T, T v> const T integral_constant<T, v>::value;

// Abbreviations: true_type and false_type are structs that represent boolean
// true and false values.
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

/*---------------------------------------------------------------*/

namespace ft
{
	template <class T> struct is_integral;

	// is_integral is false except for the built-in integer types.
	template < class T> struct is_integral : false_type { };

	template<> struct is_integral<bool> : true_type { };
	template<> struct is_integral<char> : true_type { };
	template<> struct is_integral<unsigned char> : true_type { };
	template<> struct is_integral<signed char> : true_type { };
	template<> struct is_integral<wchar_t> : true_type { };
	template<> struct is_integral<short> : true_type { };
	template<> struct is_integral<unsigned short> : true_type { };
	template<> struct is_integral<int> : true_type { };
	template<> struct is_integral<unsigned int> : true_type { };
	template<> struct is_integral<long> : true_type { };
	template<> struct is_integral<unsigned long> : true_type { };
	template<> struct is_integral<long long> : true_type { };
	template<> struct is_integral<unsigned long long> : true_type { };

}

