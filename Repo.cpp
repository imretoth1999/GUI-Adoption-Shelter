#include "Repo.h"
#include "Dog.h"
#include <string>
#include <fstream>
#include <iostream>
#include "RepositoryException.h"
int Repository::addDogRepo(const Dog& d)
{
	/*
	We add a dog to the repo
	*/
	for (Dog d1:this->repo)
		if (d.getName() == d1.getName() && d.getBreed() == d1.getBreed())
			return 0;
	this->repo.push_back(d);
	this->writeToFile();

	return 1;
}
int Repository::deleteDogRepo(const int pos)
{
	/*
	We delete a dog from the repo
	*/
	if (pos < 0 || pos >= this->repo.size())
		return 0;
	this->repo.erase(this->repo.begin() + pos);
	this->writeToFile();
	return 1;
}
int Repository::updateDogRepo(const int pos, const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight)
{
	/*
	We update a dog from the repo
	*/
	if (pos < 0 || pos >= this->repo.size())
		return 0;
	Dog d = Dog{ breed,name,age,photo,weight};
	this->repo[pos] = d;
	this->writeToFile();
	return 1;
}

int Repository::addAdoptionDog(const Dog& d)
{
	/*
	We add a dog to the repo
	*/
	for (Dog d1 : this->adopt)
		if (d.getName() == d1.getName() && d.getBreed() == d1.getBreed())
			return 0;
	this->adopt.push_back(d);
	return 1;
}
void Repository::readFromFile()
{
	std::ifstream file("Dogs.txt");
	if (!file.is_open())
		throw FileException("The file could not be open!");
	Dog d;
	while (file >> d)
		this->addDogRepo(d);
	file.close();
}

void Repository::writeToFile()
{
	std::ofstream file("Dogs.txt");
	if (!file.is_open())
		throw FileException("The file could not be open!");
	for (auto d : this->repo)
		file << d;
	file.close();
}