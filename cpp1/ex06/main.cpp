#include "Karen.hpp"

int msg_err(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

int main(int argc, char **argv)
{
	Karen karen;

	if (argc != 2)
		return (msg_err("wrong number of args"));
	karen.complain(argv[1]);
	return (0);
}