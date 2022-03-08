#include <iostream>
#include <map>
#include <chrono>


using namespace std;


int main()
{
	map<int , int> test;
	test.insert(pair<int, int>(1, 10));
	test.insert(pair<int, int>(2, 20));
	test.insert(pair<int, int>(3, 30));
	test.insert(pair<int, int>(4, 40));
	test.insert(pair<int, int>(5, 40));
	test.insert(pair<int, int>(6, 40));
	test.insert(pair<int, int>(7, 40));
	test.insert(pair<int, int>(8, 40));
	test.insert(pair<int, int>(9, 40));
	test.insert(pair<int, int>(10, 40));
	test.insert(pair<int, int>(11, 40));
	test.insert(pair<int, int>(12, 40));
	test.insert(pair<int, int>(13, 40));
	test.insert(pair<int, int>(14, 40));
	test.insert(pair<int, int>(15, 40));
	test.insert(pair<int, int>(16, 40));
	test.insert(pair<int, int>(17, 40));
	test.insert(pair<int, int>(18, 40));
	map<int, int>::iterator it = test.begin();
	map<int, int>::iterator it2 = test.end();


	while (it != it2)
	{
		cout << "next incrementation:\n";
		auto start = chrono::high_resolution_clock::now();
		it++;
		auto elapsed = chrono::high_resolution_clock::now() - start;
		cout << elapsed.count() << "\n";
	}
}
