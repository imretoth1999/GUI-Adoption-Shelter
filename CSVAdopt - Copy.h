#pragma once
#include "FileAdoption.h"
#include <string>

class CSVAdoptionList
{
private:
	std::vector<Dog> dogs;
public:
	/*
	Writes the AdoptionList to file.
	Throws: FileException - if it cannot write.
	*/
	CSVAdoptionList(const std::vector<Dog>& dogs)
	{
		this->dogs = dogs;
	}
	void writeToFile();

	/*
	Displays the AdoptionList using Microsoft Excel.
	*/
	void displayAdoptionList();
};
