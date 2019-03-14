#pragma once
#include "Dog.h"
#include <vector>

class AdoptionList
{
public:
	std::vector<Dog> dogs;
	int current;

public:
	AdoptionList();
	AdoptionList(const std::vector<Dog>& d, size_t s)
	{
		this->dogs = d;
		this->current = s;
	}
	///Add dog to the AdoptionList User
	void add(const Dog& dog);

	///Checks if the AdoptionList is empty.
	bool isEmpty();

	///Return the list of dogs that one user adopted.
	//std::vector<Dog> getAdoptedDogs() const { return dogs; }

	virtual ~AdoptionList() {}
};
