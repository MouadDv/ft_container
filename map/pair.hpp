#pragma once
#ifndef PAIR_CLASS
#define PAIR_CLASS

namespace ft
{
  template <class T1, class T2>
  class pair {
  public:
    typedef T1 key_type;
    typedef T2 mapped_type;
    T1 first;
    T2 second;
  public:
    pair(): first(), second()
    {
    }
    template<class U, class V>
    pair (const pair<U,V>& c): first(c.first), second(c.second)
    {
    }
    pair (const T1& a, const T2& b): first(a), second(b)
    {

    }
    template<class U, class V>
    pair &operator=(const pair<U, V>& c)
    {
      this->first = c.first;
      this->second = c.second;
      return (*this);
    }
    ~pair()
    {

    }
  };

  template <class T1, class T2>
  bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
  }
  template <class T1, class T2>
  bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return !(lhs == rhs);
  }

  template <class T1, class T2>
  bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
  }
  template <class T1, class T2>
  bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return !(rhs<lhs);
  }
  template <class T1, class T2>
  bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return (rhs<lhs);
  }
  template <class T1, class T2>
  bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
  {
    return !(lhs<rhs);
  }

  template <class T1,class T2>
  pair<T1,T2> make_pair (T1 x, T2 y)
  {
    return ( pair<T1,T2>(x,y) );
  }

}

#endif
