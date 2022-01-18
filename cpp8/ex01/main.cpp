#include "span.hpp"

int main()
{
	std::cout << "test 1: from subject" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test 2: add extra number to assigned new object" << std::endl;
	Span somespan = sp;
	try
	{
		somespan.addNumber(7);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "test 3: new span without arg" << std::endl;
	Span onemorespan;
	try
	{
		onemorespan.addNumber(7);
		std::cout << onemorespan.shortestSpan() << std::endl;
		std::cout << onemorespan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "test 4: 10000" << std::endl;
	Span verybigspan(10000);
	try
	{
		for (int i = 1; i <= 10000; i++)
			verybigspan.addNumber(i);
		std::cout << verybigspan.shortestSpan() << std::endl;
		std::cout << verybigspan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "test 5: better add number" << std::endl;
	int *nums = new int[10000];
	for (int i = 0; i < 10000; i++)
		nums[i] = i + 1;
	Span betterspan(10000);
	try
	{
		betterspan.betterAddNumber(nums, 10000);
		delete [] nums;
		std::cout << "done" << std::endl;
		std::cout << betterspan.shortestSpan() << std::endl;
		std::cout << betterspan.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}