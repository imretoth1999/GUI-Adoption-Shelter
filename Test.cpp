#include "Dog.h"
#include "DogValidator.h"
#include "DynamicVector.h"
#include <assert.h>
#include "Test.h"
#include "Repo.h"
#include "Controller.h"
void Test::testDog()
{
	Dog d{ "Pug","Jane",2,"youtube.com" ,2};
	assert(d.getAge() == 2);
	assert(d.getBreed() == "Pug");
	assert(d.getName() == "Jane");
	assert(d.getPhoto() == "youtube.com");
	assert(d.getWeight() == 2);
	Dog d1{ "Pug","Jane",10,"google.com",3 };
	int ok = (d == d1);
	assert(ok == 1);
	d1.showPhoto();
}
/* 
void Test::testVector()
{
	Dyna
	Test::testAdd(v);
	DynamicVector<Dog> v1 = v;
	Test::testDel(v);
	Test::testUpdate(v);
	
}
void Test::testAdd(DynamicVector<Dog>& v)
{
	assert(v.getSize() == 0);
	Dog d{ "Pug","Jane",2,"youtube.com" ,22};
	v.add(d);
	assert(v.getSize() == 1);
	Dog d1{ "Pug1","Jane1",2,"youtube.com" ,1};
	v.add(d1);
	assert(v.getSize() == 2);
	Dog d2{ "Pug1","Jane1",2,"youtube.com",4 };

	assert(v.getCapacity() == 2);
	v.add(d2);
	assert(v.getSize() == 2);
	assert(v.getCapacity() == 2);
	assert((v.getAllElems()[0] < 100) == true);

}
void Test::testDel(DynamicVector<Dog>& v)
{
	v.deleteDog(4);
	assert(v.getSize() == 2);
	v.deleteDog(0);
	assert(v.getSize() == 1);
}

void Test::testUpdate(DynamicVector<Dog>& v)
{
	v.updateDog(0, "a", "b", 3, "www.google.com",4);
	Dog *r = v.getAllElems();
	assert(r[0].getBreed() == "a");
	assert(r[0].getName() == "b");
	assert(r[0].getAge() == 3);
	assert(r[0].getPhoto() == "www.google.com");
	assert(v.updateDog(100, "c", "s", 3, "ok.com",11) == 0);
}
*/
void Test::testRepo()
{
	Repository r;
	DogValidator v;
	Controller c{ r,v };
	Test::testRepoAdd(c);
	Test::testRepoDel(c);
	Test::testUpdateDel(c);
	Test::testAdoptAdd(c);
	Test::testExists(c);
}

void Test::testRepoAdd(Controller& c)
{
	assert(c.addDogToRepository("a2222", "Bere", 3, "www.google.com",1) == 1);
	assert(c.addDogToRepository("a2222", "Bere", 3, "www.google.com",2) == 0);
	assert(c.addDogToRepository("133ss", "Cere2", 3, "www.google.com",3) == 1);


}

void Test::testRepoDel(Controller & c)
{
	assert(c.deleteDogFromRepository(100) == 0);
	assert(c.deleteDogFromRepository(0) == 1);
}

void Test::testUpdateDel(Controller & c)
{
	assert(c.updateDogFromRepository(100, "a2222", "B", 4, "www.google.com",1) == 0);
	assert(c.updateDogFromRepository(0, "A323", "B2222", 3, "www.google.com", 3) == 1);
}

void Test::testAdoptAdd(Controller & c)
{
	Dog d{ "IMre","IMr2",33,"www.youtube.com" ,1};
	assert(c.addAdoption(d) == 1);
	assert(c.addAdoption(d) == 0);
	std::vector<Dog> v = c.getRepo().getAdopt();
	assert(v.size() == 1);
}

void Test::testExists(Controller & c)
{
	std::vector<Dog> v;
	assert(c.exists("A323", v, 100) == 1);
	assert(c.exists("q", v, 1) == 0);
	assert(c.deleteDogFromRepository(0) == 1);
	//assert(c.deleteDogFromRepository(0) == 1);
}



void Test::testAll()
{
	Test::testDog();
	//Test::testVector();
	Test::testRepo();
}


