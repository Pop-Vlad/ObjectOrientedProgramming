#pragma once

#include "Controller.h"



class Test {


private:

	std::string repository_type = "file";


public:

	static void testMode();
	static void fileLocation();

	static void testAdd();
	static void testUpdate();
	static void testDelete();
	static void testListA();

	static void testNext();
	static void testListB();
	static void testMyListPlusSave();

	static void testAll();


};