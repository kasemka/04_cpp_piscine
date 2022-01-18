#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
class Span
{

private:
	std::vector<int> _v1;
	unsigned int _size;

public:
	Span(void);
	virtual ~Span();
	Span &operator=(Span const &cl);
	Span(Span const &cl);
	Span(unsigned int size);

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;
	void betterAddNumber(int *num, unsigned int len);


	class NoPlaceException : public std::exception
	{
	public:
		virtual const char *what() const throw(){
			return "No place left for new number or size < 2";};
	};
	class NoSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw(){
			return "No span found";};
	};
};


// std::ostream &operator<<(std::ostream &o, Span &cl);

#endif