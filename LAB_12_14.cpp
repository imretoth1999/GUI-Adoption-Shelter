#include "LAB_12_14.h"
#include <fstream>
LAB_12_14::LAB_12_14(Controller &c,QWidget *parent)
	: c(c), QMainWindow(parent)
{
	ui.setupUi(this);
	this->current = 0;
	this->showDogs();
	this->showAdopt();
	this->filtered = 0;
	this->showone(this->current);
	this->connect();
}
void LAB_12_14::connect()
{
	QObject::connect(ui.usergo, SIGNAL(released()), this, SLOT(goToTab2()));
	QObject::connect(ui.admingo, SIGNAL(released()), this, SLOT(goToTab3()));
	QObject::connect(ui.goback, SIGNAL(released()), this, SLOT(goToTab1()));
	QObject::connect(ui.goback_2, SIGNAL(released()), this, SLOT(goToTab1()));
	QObject::connect(ui.adaugafra, SIGNAL(released()), this, SLOT(addDog()));
	QObject::connect(ui.deleteDog, SIGNAL(released()), this, SLOT(deleteDog()));
	QObject::connect(ui.updateDog, SIGNAL(released()), this, SLOT(updateDog()));
	QObject::connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(show1()));
	QObject::connect(ui.get, SIGNAL(released()), this, SLOT(putadopt()));
	QObject::connect(ui.next, SIGNAL(released()), this, SLOT(next()));
	QObject::connect(ui.filter, SIGNAL(released()), this, SLOT(filter()));
	QObject::connect(ui.gow, SIGNAL(released()), this, SLOT(gow()));
	QObject::connect(ui.HTML, SIGNAL(released()), this, SLOT(HTMLDog()));
	QObject::connect(ui.CSV, SIGNAL(released()), this, SLOT(CSVDog()));



}
void LAB_12_14::showDogs()
{
	if (ui.listaadmin->count() > 0)
		ui.listaadmin->clear();
	for (auto c : c.getRepo().getVector())
	{
		std::string n = c.getName();
		if (ui.comboBox->currentText() == "Detailed")
		{
			std::string b = c.getBreed();
			std::string a = std::to_string(c.getAge());
			std::string we = std::to_string(c.getWeight());
			ui.listaadmin->addItem(QString::fromStdString(n + " - " + b + ", " + a + ", " + we));
		}
		else
			ui.listaadmin->addItem(QString::fromStdString(n));
	}
}
void LAB_12_14::showAdopt()
{
	if (ui.listaadopt->count() > 0)
		ui.listaadopt->clear();
	for (auto c : c.getRepo().getAdopt())
	{
		std::string n = c.getName();
		std::string b = c.getBreed();
		std::string a = std::to_string(c.getAge());
		std::string we = std::to_string(c.getWeight());
		ui.listaadopt->addItem(QString::fromStdString(n + " - " + b + ", " + a + ", " + we));
	}
}
void LAB_12_14::showone(int i)
{
	if (ui.Adopt->count() > 0)
		ui.Adopt->clear();
	if (this->filtered == 0)
	{
		std::string n = c.getRepo().getVector()[i].getName();
		std::string b = c.getRepo().getVector()[i].getBreed();
		std::string a = std::to_string(c.getRepo().getVector()[i].getAge());
		std::string we = std::to_string(c.getRepo().getVector()[i].getWeight());
		ui.Adopt->addItem(QString::fromStdString(n + " - " + b + ", " + a + ", " + we));
	}
	else
	{
		std::string n = this->v[i].getName();
		std::string b = this->v[i].getBreed();
		std::string a = std::to_string(this->v[i].getAge());
		std::string we = std::to_string(this->v[i].getWeight());
		ui.Adopt->addItem(QString::fromStdString(n + " - " + b + ", " + a + ", " + we));
	}
}
