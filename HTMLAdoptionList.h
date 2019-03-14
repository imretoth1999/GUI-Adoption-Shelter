#pragma once
#include "FileAdoption.h"
#include <string>

class HTMLAdoptionList
{
private:
	std::vector<Dog> dogs;
public:
	/*
	Writes the AdoptionList to file.
	Throws: FileException - if it cannot write.
	*/
	HTMLAdoptionList(const std::vector<Dog>& dogs)
	{
		this->dogs = dogs;
	}
	void writeToFile();

	/*
	Displays the AdoptionList using Microsoft Excel.
	*/
	void displayAdoptionList();
};
