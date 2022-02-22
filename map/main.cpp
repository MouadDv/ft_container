#include <map>
#include <iostream>

int main()
{
	std::pair<int,int> tt(10,3000);
	std::pair<int,int> t(30000,2000);
	std::map<int, int> test;
	test.insert(tt);
	test.insert(t);
	std::map<int, int>::iterator it = test.begin();
	std::map<int, int>::iterator it2 = test.end();

	std::cout << "map begin: " << (*it).first << "  |  " << (*it).second << "\n";
	it++;
	std::cout << "map begin: " << (*it).first << "  |  " << (*it).second << "\n";
	it++;
	std::cout << "map begin: " << (*it).first << "  |  " << (*it).second << "\n";
	std::cout << "map end:   " << (*it2).first << "  |  " << (*it2).second << "\n";


}