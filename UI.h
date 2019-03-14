#pragma once
#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

	void addDogToRepo();
	void displayAllDogs();
	void smallerWeight();
	void deleteDogR();
	void updateDogR();
	void listAdoption();
	void smallerAge();
	void onebyone();
};

