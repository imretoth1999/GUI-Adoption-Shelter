#include "CSVAdopt.h"
#include <fstream>
#include "RepositoryException.h"
#include <Windows.h>
using namespace std;

void CSVAdoptionList::writeToFile()
{
	ofstream f("Dogs.csv");

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto d : this->dogs) {
		f << d.getBreed() << ", " << d.getName() << ", " << d.getAge() << ", " << d.getPhoto() <<", "<<d.getWeight()<< "\n";
	}

	f.close();
}

void CSVAdoptionList::displayAdoptionList() 
{
	//string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations

	string aux = "Dogs.csv";
	ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);

}


