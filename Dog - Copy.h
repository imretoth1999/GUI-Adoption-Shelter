#pragma once
#include <iostream>
class Dog
{
private:
	std::string breed;
	std::string name;
	std::int32_t age;
	std::string photo;
	std::int32_t weight;
public:
	Dog();
	Dog(const std::string& breed, const std::string& name, const std::int32_t age, const std::string& photo, const std::int32_t weight);
	bool operator==(const Dog& d);
	bool operator<(const int weight);
	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	std::int32_t getAge() const { return age; }
	std::string getPhoto() const { return photo; }
	std::int32_t getWeight() const { return weight; };
	void showPhoto();
	bool equalDogs(const Dog& d);
	friend std::istream& operator>>(std::istream& is, Dog& d);
	friend std::ostream& operator<<(std::ostream& os, const Dog& d);

};