#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void){};
	virtual ~MutantStack(){};

	MutantStack(MutantStack const &cl)
	{
		*this = cl;
	};
	MutantStack &operator=(MutantStack const &cl)
	{
		this->c = cl.c;
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return (this->c.end()); }

#endif