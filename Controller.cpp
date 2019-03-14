#include "Controller.h"
#include <iostream>
#include "CSVAdopt.h"

int Controller::addDogToRepository(const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight)
{
	/*
	We add the dog to the repository
	*/
	Dog d = Dog{ breed,name,age,photo, weight};
	this->valid.validate(d);
	return this->repo.addDogRepo(d);
}
int Controller::deleteDogFromRepository(const int pos)
{
	/*
	We delete the dog from repo
	*/
	return this->repo.deleteDogRepo(pos);
}
int Controller::updateDogFromRepository(const int pos, const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight)
{
	/*
	We update the dog from repo
	*/
	Dog d = Dog{ breed,name,age,photo, weight };
	this->valid.validate(d);
	return this->repo.updateDogRepo(pos, breed, name, age, photo, weight);
}
int Controller::addAdoption(Dog &d)
{
	return this->repo.addAdoptionDog(d);
}
int Controller::exists(const std::string & s, std::vector<Dog> & v, int age)
{
	int ok = 0;
	for (Dog d:this->getRepo().getVector())
		if (d.getBreed() == s)
		{
			ok = 1;
			if (d.getAge() < age)
			{
				v.push_back(d);
			}
		}
	return ok;
}

