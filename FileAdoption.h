#pragma once
#include "AdoptionList.h"

class FileAdoptionList : public AdoptionList
{
protected:
	std::vector<Dog> d;
public:
	FileAdoptionList();
	FileAdoptionList(const AdoptionList& a)
	{
		this->d = a.dogs;
	}
	virtual ~FileAdoptionList() {}

	virtual void writeToFile() = 0;
	virtual void displayAdoptionList() const = 0;
};