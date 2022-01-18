#include "iter.hpp"

int main(void)
{
	int arr[3] = {1, 2, 3};
	::iter(arr, 3, print<int>);
	std::cout << std::endl;

	char s[] = "Hello world!";
	::iter(s, 12, print<char>);
	std::cout << std::endl;


	Test *smth = new Test[2];
	::iter(smth, 2, print_address<Test>);
	delete [] smth;

	return (0);
}