#include <iostream>
#include <string>
#include <deque>
#if STD == 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map/map.hpp"
	#include "stack/stack.hpp"
	#include "vector/vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;
	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}

	std::cout << std::endl;
	{
		ft::vector<int> test;
		test.insert(test.begin(), 10, 10);
		std::cout << "Size == " << test.size() << " Capacity == " << test.capacity() << "\n";
		test.insert(test.begin(), 4, 10);
		std::cout << "Size == " << test.size() << " Capacity == " << test.capacity() << "\n";
		test.insert(test.begin(), 40, 10);
		std::cout << "Size == " << test.size() << " Capacity == " << test.capacity() << "\n";
	}
	{
		ft::vector<int> test;

		for (int i = 0; i < 1e4; i++)
		{
			test.push_back(i);
		}

		ft::vector<int>::iterator it = test.begin();
		ft::vector<int>::const_iterator cit = test.begin();
		
		std::cout << std::boolalpha << (cit == it) <<std::endl;
	}
	{
		ft::vector<int> test;
		for (int i = 0; i < 1e4; i++)
		{
			test.push_back(i);
		}
		ft::vector<int>::iterator it = test.begin();
		std::cout << *(2 + it) <<std::endl;
	}
	{
		ft::vector<int> test;
		ft::vector<int> test2;
		for (int i = 0; i < 10; i++)
		{
			test.push_back(i);
		}
		ft::vector<int>::iterator it = test.begin();
		ft::vector<int>::iterator it2 = test.end();
		ft::swap(test, test2);
		while (it != it2)
		{
			std::cout << "test2 : " << *it << "\n";
			it++;
		}
	}
	{
		ft::map<int, int> test;
		for (int i = 0; i < 100; i++)
		{
			test.insert(ft::make_pair(i, i));
		}
		std::cout << "insert duplicated key " << (test.insert(ft::make_pair(0, 0))).second << "\n";
	}
	{
		ft::map<int, int> test;
		for (int i = 0; i < 10; i++)
		{
			test.insert(ft::make_pair(i, i));
		}
		ft::map<int, int>::iterator it = test.begin();
		test.erase(10);
		while (it != test.end())
		{
			std::cout << "test : " << it->first << "\n";
			it++;
		}
		
	}
	 {
        std::cout << "constructing stacks\n";
        ft::vector<int> myvector (2,200);        // vector with 2 elements

        ft::stack<int> first;                    // empty stack

        ft::stack<int,ft::vector<int> > third;  // empty stack using vector
        ft::stack<int,ft::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }

    {
        std::cout << "\nstack::empty\n";
        ft::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }

        std::cout << "total: " << sum << '\n';
    }

    {
        std::cout << "\nstack::size\n";
        ft::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }

    {
        std::cout << "\nstack::top\n";
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }

    {
        std::cout << "\nstack::push/pop\n";
        ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }
	
	//system("leaks a.out");
	return (0);
}