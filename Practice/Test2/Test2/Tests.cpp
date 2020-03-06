#pragma once

#include <assert.h>

#include "Repository.h"



class Test {

public:

	static void testFilter() {
		Repository repository{ "test.txt" };
		Task task1{ "qqq", 10, 3 };
		Task task2{ "www", 5, 1 };
		Task task3{ "eee", 6, 2 };
		Task task4{ "rrr", 7, 1 };
		Task task5{ "ttt", 12, 2 };

		std::vector<Task> result = repository.getElementsWithPriority(1);
		assert(result.size() == 2);
		assert(result[0].toString() == task2.toString());
		assert(result[1].toString() == task4.toString());
		result = repository.getElementsWithPriority(2);
		assert(result.size() == 2);
		assert(result[0].toString() == task3.toString());
		assert(result[1].toString() == task5.toString());
		result = repository.getElementsWithPriority(3);
		assert(result.size() == 1);
		assert(result[0].toString() == task1.toString());
		result = repository.getElementsWithPriority(0);
		assert(result.size() == 5);
		assert(result[0].toString() == task1.toString());
		assert(result[1].toString() == task2.toString());
		assert(result[2].toString() == task3.toString());
		assert(result[3].toString() == task4.toString());
		assert(result[4].toString() == task5.toString());
	}


};