#include "UI.h"
#include <string>
#include "RepositoryException.h"
#include "AdoptionList.h"
#include "FileAdoption.h"
#include "HTMLAdoptionList.h"
using namespace std;
void UI::printMenu()
{
	/*
	We print the menu
	*/
	cout << endl;
	cout << "1 - Administrator" << endl;
	cout << "2 - User" << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdminMenu()
{
	/*
	We print the admin menu
	*/
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add dog." << endl;
	cout << "\t 2 - Remove dog by index" << endl;
	cout << "\t 3 Update dog by index" << endl;
	cout << "\t 4 - Display all dogs with weight smaller than a given value" << endl;
	cout << "\t -1 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserMenu()
{
	/*
	We print the user menu
	*/
	cout << "Possible commands: " << endl;
	cout << "\t 1 - To see the dogs one by one" << endl;
	cout << "\t 2 - To see all dogs having the age smaller than a given number " << endl;
	cout << "\t 3 - To see the adoption list" << endl;
	cout << "\t 4 - To see the adoption list in the format selected at start" << endl;
	cout << "\t 0 - Go back" << endl;
}
void UI::addDogToRepo()
{
	/*
	We add the dog to repo
	*/
	cout << "Enter the breed"<<endl;
	std::string breed;
	cin >> breed;
	cout << "Enter the name" << endl;
	std::string name;
	cin >> name;
	int32_t age;
	cout << "Enter the age" << endl;
	cin >> age;
	cout << "Enter the link" << endl;
	std::string link;
	cin >> link;
	std::int32_t weight;
	cout << "Enter the weight" << endl;
	cin >> weight;
	try
	{
		if (this->ctrl.addDogToRepository(breed, name, age, link, weight) == 1)
			cout << "The dog was added" << endl;
		else
			cout << "The dog already exists" << endl;
	}
	catch (DogException& e)
	{
		for (auto d : e.getErrors())
			cout << d;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}
void UI::deleteDogR()
{
	/*
	Delete dog from repo
	*/
	cout << "Enter the index of the dog you want to delete" << endl;
	int pos;
	cin >> pos;
	try
	{
		if (this->ctrl.deleteDogFromRepository(pos) == 1)
			cout << "The dog was deleted" << endl;
		else
			cout << "Invalid index" << endl;
	}
	catch (DogException& e)
	{
		for (auto d : e.getErrors())
			cout << d;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}
void UI::updateDogR()
{
	/*
	Update the dog
	*/
	cout << "Enter the breed" << endl;
	std::string breed;
	cin >> breed;
	cout << "Enter the name" << endl;
	std::string name;
	cin >> name;
	int32_t age;
	cout << "Enter the age" << endl;
	cin >> age;
	cout << "Enter the link" << endl;
	std::string link;
	cin >> link;
	std::int32_t weight;
	cout << "Enter the weight" << endl;
	cin >> weight;
	cout << "Enter the index of the dog you want to modify" << endl;
	int index;
	cin >> index;
	try
	{
		if (this->ctrl.updateDogFromRepository(index, breed, name, age, link, weight) == 1)
			cout << "The dog was updated" << endl;
		else
			cout << "Invalid index" << endl;
	}
	catch (DogException& e)
	{
		for (auto d : e.getErrors())
			cout << d;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}
void UI::listAdoption()
{
	std::vector<Dog> v = this->ctrl.getRepo().getAdopt();

	for (int i = 0; i < v.size(); i++)
	{
		cout << i << " - Name: " << v[i].getName() << " Breed: " << v[i].getBreed() << " Age: " << v[i].getAge() <<" Weight: "<<v[i].getWeight()<< endl;
		//d[i].showPhoto();
	}
}
void UI::smallerAge()
{
	/*
	We get all the dogs smaller than a given age from a given breed
	*/
	cout << "Enter the age" << endl;
	int age;
	string bred;
	cin.ignore();
	cin >> age;
	cout << "Enter the breed" << endl;
	cin.ignore();
	cin >> bred;
	cin.ignore();
	std::vector<Dog> v = this->ctrl.getRepo().getVector();
	std::vector<Dog> v1;
	if (v.size() == 0)
	{
		cout << "Empty repo!" << endl;
		return;
	}

	int ok = this->ctrl.exists(bred,v1,age);

	if (ok == 1)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			cout << i << " - Name: " << v1[i].getName() << " Breed: " << v1[i].getBreed() << " Age: " << v1[i].getAge() <<" Weight "<<v1[i].getWeight()<< endl;
			int c2 = { 0 };
			cout << "Press 1 to adopt it" << endl;
			cout << "Press 2 to get to the next dog and not adopt this one" << endl;
			if (i == v1.size() - 1)
			{
				cout << "Press 3 to exit the list";
			}
			cin >> c2;
			if (c2 == 1)
			{
				this->ctrl.addAdoption(v1[i]);
			}
			if (i == v1.size() - 1 && c2 == 3)
				break;
			if (i == v1.size() - 1 && c2 == 2)
				i = -1;
		}
	}
	else
	{
		this->onebyone();
	}
}
void UI::onebyone()
{
	/*
	We display everything one by one
	*/
	std::vector<Dog> v = this->ctrl.getRepo().getVector();
	if (v.size() == 0)
	{
		cout << "Empty repo!" << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << i << " - Name: " << v[i].getName() << " Breed: " << v[i].getBreed() << " Age: " << v[i].getAge() << " Weight: "<<v[i].getWeight()<<endl;
		int c2 = { 0 };
		cout << "Press 1 to adopt it"<<endl;
		cout << "Press 2 to get to the next dog and not adopt this one"<<endl;
		if (i == v.size() - 1)
		{
			cout << "Press 3 to exit the list";
		}
		cin >> c2;
		if (c2 == 1)
		{
			this->ctrl.addAdoption(v[i]);
		}
		if (i == v.size() - 1 && c2 == 3)
			break;
		if (i == v.size() - 1 && c2 == 2)
			i = -1;
	}
}
void UI::displayAllDogs()
{
	/*
	Display all dogs
	*/
	std::vector<Dog> v = this->ctrl.getRepo().getVector();

	if (v.size() == 0)
	{
		cout << "Empty repo!" << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << i << " - Name: " << v[i].getName() << " Breed: " << v[i].getBreed() << " Age: " << v[i].getAge() <<" Weight: "<<v[i].getWeight()<<endl;
		//d[i].showPhoto();
	}
}
void UI::smallerWeight()
{
	std::vector<Dog> v = this->ctrl.getRepo().getVector();
	cout << "Enter the weight please" << endl;
	int weight;
	cin >> weight;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < weight)
		{
			cout << i << " - Name: " << v[i].getName() << " Breed: " << v[i].getBreed() << " Age: " << v[i].getAge() << " Weight: " <<v[i].getWeight() << endl;
		}
	}
}
void UI::run()
{
	/*
	We run the UI
	*/
	int type = 42;
	while (true)
	{
		
		if (type == 42)
		{
			cout << "Enter the type of the file you want to save\n0-CSV\nAnything else for HTML\n";

			cin >> type;
		}
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		else if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int c1{ 0 };
				cin >> c1;
				cin.ignore();
				if (c1 == 0)
					break;
				else if (c1 == 1)
					this->addDogToRepo();
				else if (c1 == 2)
					this->deleteDogR();
				else if (c1 == 3)
					this->updateDogR();
				else if (c1 == 4)
					this->smallerWeight();
				else if (c1 == -1)
					this->displayAllDogs();
				else
					cout << "Invalid command" << endl;
			}
		}
		else if (command == 2)
		{
			while (true)
			{
				int c1{ 0 };
				UI::printUserMenu();
				cin >> c1;

				if (c1 == 0)
					break;
				else if (c1 == 1)
				{
					this->onebyone();
				}
				else if (c1 == 2)
				{
					this->smallerAge();
				}
				else if (c1 == 3)
				{
					this->listAdoption();
				}
				else if (c1 == 4)
				{
					if (type == 0)
					{
						CSVAdoptionList csv{ this->ctrl.getRepo().getAdopt() };
						csv.writeToFile();
						csv.displayAdoptionList();
					}
					else
					{
						HTMLAdoptionList html{ this->ctrl.getRepo().getAdopt() };
						html.writeToFile();
						html.displayAdoptionList();
					}
				}
				else
				{
					cout << "Invalid command" << endl;
				}
			}	
		}
		else
		{
			break;
		}

	}
}