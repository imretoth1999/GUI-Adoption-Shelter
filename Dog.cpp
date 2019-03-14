#include "Dog.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <shellapi.h>
#include <fstream>
#include "Utils.h"
#include "DogValidator.h"
using namespace std;
Dog::Dog() : breed(""), name(""), age(0), photo(""),weight(0) {};

Dog::Dog(const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight)
{
	/*
	We create a dog
	*/
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photo = photo;
	this->weight = weight;
}

bool Dog::operator==(const Dog & d)
{
	/*
	We overload the == operator
	*/
	if (this->breed == d.getBreed() && this->name == d.getName())
		return true;
	return false;
}
bool Dog::operator<(const int weight)
{
	return this->getWeight() < weight;
}

/*bool Dog::equalDogs(const Dog& d)
{
	
	if (this->breed == d.getBreed() && this->name == d.getName())
		return true;
	return false;
}*/
void Dog::showPhoto()
{
	/*
	We show the photo in chrome
	*/
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream & operator >> (istream & is, Dog & d)
{
	std::string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) 
		return is;
	DogValidator v;
	d.breed = tokens[0];
	d.name = tokens[1];
	d.age = stoi(tokens[2]);
	d.photo = tokens[3];
	d.weight = stoi(tokens[4]);
	v.validate(d);
	return is;
}

ostream & operator<<(ostream & os, const Dog & d)
{
	os << d.breed << "," << d.name << "," << d.age << "," << d.photo << "," << d.weight << "\n";
	return os;
}