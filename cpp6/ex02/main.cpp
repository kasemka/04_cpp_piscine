#include "Base.hpp"

Base *generate(void)
{
	srand(time(NULL)); // for rand()
	int i = rand() % 3;

	
	switch (i)
	{
	case 0:
		std::cout<<"rand is A"<<std::endl;
		return (new A());
		break;
	case 1:
		std::cout<<"rand is B"<<std::endl;
		return (new B());
		break;
	}
	std::cout<<"rand is C"<<std::endl;
	return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "ptr: A" << std::endl;
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << "ptr: B" << std::endl;
	else if (dynamic_cast<C *>(p) != 0)
		std::cout << "ptr: C" << std::endl;
	else
		std::cout << "ptr: else" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A obj = dynamic_cast<A &>(p);
		std::cout << "ref: A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			B obj = dynamic_cast<B &>(p);
			std::cout << "ref: B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				C obj = dynamic_cast<C &>(p);
				std::cout << "ref: C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n'; //std::bad_cast
			}
		}
	}
}

int main(void)
{
	Base *base = generate();
	
	identify(base);
	identify(*base);
	identify(NULL);

	delete base;
	return (0);
}