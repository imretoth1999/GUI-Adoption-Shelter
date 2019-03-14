#pragma once
#include "Repo.h"
#include "DogValidator.h"
#include "AdoptionList.h"
#include "CSVAdopt.h"
class Controller
{
private:
	Repository repo;
	DogValidator valid;
public:
	Controller(const Repository& r, DogValidator& v) : repo{ r }, valid{ v } {}

	Repository getRepo() const { return repo; }
	DogValidator getValid() const { return valid; }
//	CSVAdoptionList csv{ this->getRepo().getAdopt() };
	int addDogToRepository(const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight);
	int deleteDogFromRepository(const int pos);
	int updateDogFromRepository(const int pos, const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight);

	int addAdoption(Dog & d);

	int exists(const std::string & s, std::vector<Dog> & v, int age);
	void openAdoptionlistCSV() ;
	void openAdoptionlistHTML() const;

};