#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LAB_12_14.h"
#include "Controller.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <fstream>
#include <string>
class LAB_12_14 : public QMainWindow
{
	Q_OBJECT

public:
	LAB_12_14(Controller &c,QWidget *parent = Q_NULLPTR);
	void connect();
	int current;
	int filtered;
	std::vector<Dog> v;
	int current1;
private:
	Ui::LAB_12_14Class ui;
	Controller &c;
	void showDogs();
	void showAdopt();
	void showone(int i);

private slots:
	void goToTab2() { ui.myTab->setCurrentIndex(1); };
	void goToTab3() { ui.myTab->setCurrentIndex(2); };
	void goToTab1() { ui.myTab->setCurrentIndex(0); };
	void addDog()
	{
		QString name = ui.Name->text();
		std::string Name = name.toStdString();
		QString breed = ui.Breed->text();
		std::string Breed = breed.toStdString();
		QString link = ui.Link->text();
		std::string Link = link.toStdString();
		int Age = ui.Age->value();
		int Weight = ui.Weight->value();
		int res;
		try
		{
			res = this->c.addDogToRepository(Breed, Name, Age, Link, Weight);
		}
		catch (DogException& e)
		{
			std::string error;
			for (auto d : e.getErrors())
			{
				error += d;
				error += " ";
			}
			QString Error = QString::fromStdString(error);
			ui.Error->setText(Error);

		}
		showDogs();
	}
	void deleteDog()
	{
		this->c.deleteDogFromRepository(ui.listaadmin->currentRow());
		showDogs();
	}
	void updateDog()
	{
		QString name = ui.Name->text();
		std::string Name = name.toStdString();
		QString breed = ui.Breed->text();
		std::string Breed = breed.toStdString();
		QString link = ui.Link->text();
		std::string Link = link.toStdString();
		int Age = ui.Age->value();
		int Weight = ui.Weight->value();
		int res;
		try
		{
			res = this->c.updateDogFromRepository(ui.listaadmin->currentRow(), Breed, Name, Age, Link, Weight);
		}
		catch (DogException& e)
		{
			std::string error;
			for (auto d : e.getErrors())
			{
				error += d;
				error += " ";
			}
			QString Error = QString::fromStdString(error);
			ui.Error->setText(Error);
		}
		showDogs();
	}
	void show1()
	{
		showDogs();
	}
	void putadopt()
	{
		if (this->filtered == 0)
		{
			Dog d = this->c.getRepo().getVector()[this->current];
			this->c.addAdoption(d);
			showAdopt();
		}
		else
		{
			Dog d = this->v[this->current1];
			this->c.addAdoption(d);
			showAdopt();
		}
		if (this->filtered == 0)
		{
			this->current++;
			if (this->current == this->c.getRepo().getVector().size())
				this->current = 0;
			showone(this->current);
		}
		else
		{
			this->current1++;
			if (this->current1 == this->v.size())
				this->current1 = 0;
			showone(this->current1);
		}
	}
	void next()
	{
		if (this->filtered == 0)
		{
			this->current++;
			if (this->current == this->c.getRepo().getVector().size())
				this->current = 0;
			showone(this->current);
		}
		else
		{
			this->current1++;
			if (this->current1 == this->v.size())
				this->current1 = 0;
			showone(this->current1);
		}
	}
	void filter()
	{
		this->current1 = 0;
		this->filtered = 1;
		QString b = ui.minw->text();
		std::string b1 = b.toStdString();
		int age = ui.Ag->value();
		int ok = this->c.exists(b1, this->c.getRepo().getVector(), age);
		if (ok == 1)
			for (int i = 0; i < this->c.getRepo().getVector().size(); i++)
			{
				if (this->c.getRepo().getVector()[i].getBreed() == b1 && this->c.getRepo().getVector()[i].getAge() < age)
					this->v.push_back(this->c.getRepo().getVector()[i]);
			}
		else
			for (int i = 0; i < this->c.getRepo().getVector().size(); i++)
			{
				if (this->c.getRepo().getVector()[i].getAge() < age)
					this->v.push_back(this->c.getRepo().getVector()[i]);
			}
		showone(this->current1);
	}
	void gow()
	{
		this->filtered = 0;
		this->v.clear();
		this->current = 0;
		showone(this->current);
	}
	void HTMLDog()
	{
		std::ofstream f("Dogs.html");

		std::string rez = "<!DOCTYPE html>\n";
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
		for (auto d : this->c.getRepo().getAdopt())
		{
			f << "<tr>" << "<td>" << d.getBreed() << "</td>" << "<td>" << d.getName() << "</td>" << "<td>" << d.getAge() << "</td>" << "<td>" << d.getWeight() << "</td>" << "<td><a href =" << d.getPhoto() << ">Link</a></td>" << "</tr>";
		}
		f << "</table></body></html>";
		f.close();
		std::string aux = "Dogs.html";
		ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
		
	}
	void CSVDog()
	{
		std::ofstream f("Dogs.csv");

		for (auto d : this->c.getRepo().getAdopt()) {
			f << d.getBreed() << ", " << d.getName() << ", " << d.getAge() << ", " << d.getPhoto() << ", " << d.getWeight() << "\n";
		}

		f.close();
		std::string aux = "Dogs.csv";
		ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	}
};
