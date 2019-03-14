#include "HTMLAdoptionList.h"
#include <fstream>
#include <iostream>
#include "RepositoryException.h"
#include "Windows.h "
using namespace std;
void HTMLAdoptionList::writeToFile()
{
	ofstream f("Dogs.html");

	string rez = "<!DOCTYPE html>\n";
	rez += "<html>\n";
	rez += "<head>\n";
	rez += "<title>Adoptions</title>\n";
	rez += "</head>\n";
	rez += "<body>\n";
	rez += "<table border=\"1\">\n";
	rez += "<tr>\n";
	rez += "<td>Breed</td>\n";
	rez += "<td>Name</td>\n";
	rez += "<td>Age</td>\n";
	rez += "<td>Weight</td>\n";
	rez += "<td>Source</td>\n";
	rez += "</tr>\n";
	f << rez;
	for (auto d : this->dogs)
	{
		f << "<tr>" << "<td>" << d.getBreed() << "</td>" << "<td>" << d.getName() << "</td>" << "<td>" << d.getAge() << "</td>" << "<td>" << d.getWeight() << "</td>" << "<td><a href =" << d.getPhoto() << ">Link</a></td>" << "</tr>";
	}
	f << "</table></body></html>";
	f.close();

}
void HTMLAdoptionList::displayAdoptionList() 
{
	//string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	string aux = "Dogs.html";
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}