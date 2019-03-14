#include "LAB_12_14.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r;
	r.readFromFile();
	DogValidator v;
	Controller c{ r ,v};
	LAB_12_14 w{ c };
	w.show();
	return a.exec();
}
