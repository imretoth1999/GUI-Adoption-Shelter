#pragma once
#pragma once
#include "Dog.h"
#include "DynamicVector.h"
#include <vector>
#include "AdoptionList.h"
#include "CSVAdopt.h"
class Repository
{
private:
	std::vector<Dog> repo;
	std::vector<Dog> adopt;
public:

	Repository() {}
	int addDogRepo(const Dog& d);
	int deleteDogRepo(const int pos);
	int updateDogRepo(const int pos, const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight);

	int addAdoptionDog(const Dog & d);

	std::vector<Dog> getVector() const { return repo; }
	std::vector<Dog> getAdopt() const { return adopt; }
	void writeToFile();
	void readFromFile();
	void writeToFileCSV();
	void writeToFileHTML();
	//virtual void writeToFilePL() = 0;
	//virtual void executeThingsPL() = 0;

};