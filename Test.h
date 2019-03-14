#pragma once
#include "Repo.h"
#include "Controller.h"
class Test
{
public:
	static void testDog();
	//static void testVector();
	//static void testAdd(DynamicVector<Dog>& v);
	static void testAll();
	//static void testDel(DynamicVector<Dog>& v);
	//static void testUpdate(DynamicVector<Dog>& v);
	static void testRepo();
	static void testRepoAdd(Controller& c);
	static void testRepoDel(Controller& c);
	static void testUpdateDel(Controller &c);
	static void testAdoptAdd(Controller &c);
	static void testExists(Controller& c);

};