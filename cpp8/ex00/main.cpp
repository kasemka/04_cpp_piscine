#include "easyfind.hpp"

int main()
{
	std::cout << "test1" << std::endl;
	std::vector<int> vec_int;
	vec_int.push_back(1);
	vec_int.push_back(2);
	vec_int.push_back(3);
	vec_int.push_back(2);
	try
	{
		::easyfind(vec_int, 2);
		::easyfind(vec_int, 6);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test2" << std::endl;
	std::deque<int> dec_int;
	dec_int.push_back(0);
	dec_int.push_front(10);
	try
	{
		::easyfind(dec_int, 10);
		::easyfind(dec_int, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}