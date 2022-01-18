#include <iostream>
#include <stdint.h>
#include <string>

struct Data
{
	int price;
	std::string fruit;
};

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data *data = new Data();
	uintptr_t ptr;
	Data *newdata;

	data->fruit = "apple";
	data->price = 70;
	ptr = serialize(data);

	std::cout << "serialized int: " << ptr << std::endl;

	newdata = deserialize(ptr);

	std::cout << "fruit: " << newdata->fruit << ", price: " << newdata->price << std::endl;
	std::cout << "fruit: " << data->fruit << ", price: " << data->price << std::endl;

	delete (data);

	return (0);
}