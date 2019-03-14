#include "Utils.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

std::string trim(const std::string& s)
{
	std::string result(s);
	int pos = result.find_first_not_of(" ");
	if (pos != -1)
		result.erase(0, pos);
	pos = result.find_last_not_of(" ");
	if (pos != std::string::npos)
		result.erase(pos + 1);
	return result;
}

vector<string> tokenize(const string& str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string(token);
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}
/*
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
*/