#include <iostream>
#include <fstream>
#include <sstream>

int msg_err(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

std::string replace(std::string buff, std::string olds, std::string news)
{
	size_t len_olds = olds.length();
	size_t len_news = news.length();
	size_t start = 0;

	while (start < buff.length())
	{
		if (buff.compare(start, len_olds, olds) == 0)
		{
			buff.erase(start, len_olds);
			buff.insert(start, news);
			start = start + len_news - 1;
		}
		start++;
	}
	return (buff);
}

std::string ft_filename(char *str)
{
	std::string filename = str;
	int i = -1;

	while (filename[++i])
		filename[i] = toupper(filename[i]);
	filename.append(".replace");
	return (filename);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (msg_err("wrong number of arguments"));
	if (argv[2][0] == '\0')
		return (msg_err("arg for replace is empty"));
	std::ifstream file(argv[1]);
	if (!file.is_open())
		return (msg_err("file cannot be opened"));
	std::string filename = ft_filename(argv[1]);
	std::ofstream newfile(filename.c_str());
	std::stringstream buff;
	std::string newstr;
	buff << file.rdbuf();
	newfile << replace(buff.str(), argv[2], argv[3]);
	file.close();
	newfile.close();
	return (0);
}