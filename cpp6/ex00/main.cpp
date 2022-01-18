#include <iostream>
#include <cstdlib> //atoi
#include <string>
#include <cmath> //isinf, isnan

int err_msg(std::string s)
{
	std::cerr << s << std::endl;
	return (1);
}

int checkNum(std::string input)
{
	int point = 0;
	int len = input.length();

	if (len == 1)
		return (0);
	if (input == "nanf" || input == "-inff" || input == "+inff" || input == "inff" || input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
		return (0);
	for (int j = 0; j < len; j++)
	{
		if (std::isdigit(input[j]) == 0)
		{
			if (input[j] == '.' && point == 0)
				point++;
			else if (input[j] == '.' && point > 0)
				return (err_msg("Argumnet is not a number"));
			else if (input[j] != 'f' && input[j] != '-')
				return (err_msg("Argumnet is not a number"));
			else if (input[j] == 'f' && j != len - 1)
				return (err_msg("Argumnet is not a number"));
			else if (input[j] == '-' && j != 0)
				return (err_msg("Argumnet is not a number"));
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	char c;
	int i;
	float f;
	double d;
	std::string input;
	char *end;

	if (argc != 2)
		return (err_msg("Program should have one argument"));
	input = argv[1];
	if (checkNum(input))
		return (1);

	if (!isdigit(input[0]) && input[1] == '\0')
		d = static_cast<double>(input[0]); //ascii code saved
	else
		d = std::strtod(argv[1], &end); //strtod expects numbers 

	

	c = static_cast<char>(d);
	if (std::isinf(d) || std::isnan(d))
		std::cerr << "char: impossible" << std::endl;
	else if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'"<< std::endl;

	i = static_cast<int>(d);
	if (std::isinf(d) || std::isnan(d) || d < -2147483648 || d > 2147483647)
		std::cerr << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	f = static_cast<float>(d);
	if (f - i == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (d - i == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;


	return (0);
}