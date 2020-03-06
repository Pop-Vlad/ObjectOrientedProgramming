#include "Test.h"
#include <assert.h>

bool compare(AnomalousFragment fragment_1, AnomalousFragment fragment_2) {
	return fragment_1.getId() == fragment_2.getId() && fragment_1.getSize() == fragment_2.getSize() &&
		fragment_1.getInfectionLevel() == fragment_2.getInfectionLevel() && fragment_1.getMicrofragments() == fragment_2.getMicrofragments()
		&& fragment_1.getPhotograph() == fragment_2.getPhotograph();
}



void Test::testMode() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('B');
	assert(controller.getMode() == 'B');
	controller.setMode('B');
	assert(controller.getMode() == 'B');
	controller.setMode('a');
	assert(controller.getMode() == 'A');
	controller.setMode('A');
	assert(controller.getMode() == 'A');
	try {
		controller.setMode('c');
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
	try {
		controller.setMode(4);
		assert(false);
	}
	catch (ModeError& mode_error) {
		std::string message = mode_error.what();
		assert(true);
	}
}


void Test::testFileLocation() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('B');
	controller.changeFile("C:/Users/popvl/source/OOP/Laboratory8/Tests/path/TestFile_1.txt");
	AnomalousFragment a_fragment = controller.nextFragment();
	assert(a_fragment.getId() == "1" && a_fragment.getSize() == "a" && a_fragment.getInfectionLevel() == 4.0 && a_fragment.getMicrofragments() == 5
		&& a_fragment.getPhotograph() == "abc");
	controller.setMode('A');
	assert(controller.listAll().size() == 4);
	controller.changeFile("C:/Users/popvl/source/OOP/Laboratory8/Tests/path/TestFile_1.txt");
	assert(controller.listAll().size() == 4);
	controller.changeFile("../Tests/path/TestFile_1.txt");
	assert(controller.listAll().size() == 4);
	controller.changeFile("C:/Users/popvl/source/OOP/Laboratory8/Tests/path/TestFile_3.txt");
	assert(controller.listAll().size() == 4);
	controller.changeFile("../Tests/some path with spaces/TestFile_1.txt");
	assert(controller.listAll().size() == 12);
	controller.changeFile("../Tests/some path with spaces/some file with different extension.txt");
	assert(controller.listAll().size() == 4);
	controller.changeFile("../Tests/some path with spaces/some file with different extension.txt");
	assert(controller.listAll().size() == 4);
	controller.changeFile("C:/Users/popvl/source/OOP/Laboratory8/Tests/path/TestFile_1.txt");
	controller.setMode('B');
	a_fragment = controller.nextFragment();
	assert(a_fragment.getId() == "2" && a_fragment.getSize() == "3x4x5" && a_fragment.getInfectionLevel() == 6.0 && a_fragment.getMicrofragments() == 7
		&& a_fragment.getPhotograph() == "8");
	controller.setMode('A');
	assert(controller.listAll().size() == 4);
}


void Test::testAdd() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	assert(controller.listAll().size() == 0);
	AnomalousFragment new_fragment_1{ "id_1", "size_1", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "size_2", 12.3, 22, "photo_1" };
	controller.add(new_fragment_2);
	AnomalousFragment new_fragment_3{ "id_3", "size_3", 12.3, 22, "photo_1" };
	controller.add(new_fragment_3);
	AnomalousFragment new_fragment_4{ "id_4", "size_4", 12.3, 22, "photo_1" };
	controller.add(new_fragment_4);
	assert(controller.listAll().size() == 4);
	try {
		AnomalousFragment new_fragment_1{ "id_1", "size_1", 12.3, 22, "photo_1" };
		controller.add(new_fragment_1);
		assert(false);
	}
	catch (ElementAlreadyExists& add_error) {
		assert(true);
	}
	try {
		AnomalousFragment new_fragment_2{ "id_1", "size_3", 122.3, 222, "photo_3" };
		controller.add(new_fragment_2);
		assert(false);
	}
	catch (ElementAlreadyExists& add_error) {
		assert(true);
	}
	try {
		controller.setMode('B');
		controller.add(new_fragment_1);
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
}


void Test::testUpdate() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	AnomalousFragment new_fragment_1{ "id_1", "size_1", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "size_2", 12.3, 22, "photo_2" };
	controller.add(new_fragment_2);
	AnomalousFragment new_fragment_3{ "id_3", "size_3", 12.3, 22, "photo_3" };
	controller.add(new_fragment_3);
	AnomalousFragment new_fragment_4{ "id_4", "size_4", 12.3, 22, "photo_4" };
	controller.add(new_fragment_4);
	AnomalousFragment fragment_update_1{ "id_1", "modified_size", 100, 100, "modified_photo" };
	controller.update(fragment_update_1);
	AnomalousFragment fragment_update_2{ "id_2", "modified_size", 100, 100, "modified_photo" };
	controller.update(fragment_update_2);
	AnomalousFragment fragment_update_3{ "id_1", "aaa", 100, 100, "bbb" };
	controller.update(fragment_update_3);
	std::vector<AnomalousFragment> result = controller.listAll();
	std::vector<AnomalousFragment> check{ fragment_update_3, fragment_update_2, new_fragment_3, new_fragment_4 };
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 4);
	AnomalousFragment inexistent_fragment{ "inexistent_element", "aaa", 100, 100, "bbb" };
	try {
		controller.update(inexistent_fragment);
		assert(false);
	}
	catch (ElementNotFound& add_error) {
		assert(true);
	}
	result = controller.listAll();
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 4);
	try {
		controller.setMode('B');
		controller.update(new_fragment_1);
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
}


void Test::testDelete() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	AnomalousFragment new_fragment_1{ "id_1", "size_1", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "size_2", 12.3, 22, "photo_2" };
	controller.add(new_fragment_2);
	AnomalousFragment new_fragment_3{ "id_3", "size_3", 12.3, 22, "photo_3" };
	controller.add(new_fragment_3);
	AnomalousFragment new_fragment_4{ "id_4", "size_4", 12.3, 22, "photo_4" };
	controller.add(new_fragment_4);
	controller.remove("id_3");
	controller.remove("id_2");
	std::vector<AnomalousFragment> result = controller.listAll();
	std::vector<AnomalousFragment> check{ new_fragment_1, new_fragment_4 };
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 2);
	try {
		controller.remove("inexistent_element");
		assert(false);
	}
	catch (ElementNotFound& add_error) {
		assert(true);
	}
	try {
		controller.remove("id_3");
		assert(false);
	}
	catch (ElementNotFound& add_error) {
		assert(true);
	}
	result = controller.listAll();
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 2);
	try {
		controller.setMode('B');
		controller.remove("id_1");
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
}


void Test::testListA() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	assert(controller.listAll().size() == 0);
	AnomalousFragment new_fragment_1{ "id_1", "size_1", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "size_2", 12.3, 22, "photo_1" };
	controller.add(new_fragment_2);
	AnomalousFragment new_fragment_3{ "id_3", "size_3", 12.3, 22, "photo_1" };
	controller.add(new_fragment_3);
	AnomalousFragment new_fragment_4{ "id_4", "size_4", 12.3, 22, "photo_1" };
	controller.add(new_fragment_4);
	std::vector<AnomalousFragment> result = controller.listAll();
	std::vector<AnomalousFragment> check{ new_fragment_1, new_fragment_2, new_fragment_3, new_fragment_4 };
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 4);
	try {
		controller.setMode('B');
		controller.listAll();
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
}


void Test::testListB() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	assert(controller.listAll().size() == 0);
	AnomalousFragment new_fragment_1{ "id_1", "aaa", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "aaa", 12.3, 100, "photo_1" };
	controller.add(new_fragment_2);
	AnomalousFragment new_fragment_3{ "id_3", "aaa", 12.3, 100, "photo_1" };
	controller.add(new_fragment_3);
	AnomalousFragment new_fragment_4{ "id_4", "size_4", 12.3, 100, "photo_1" };
	controller.add(new_fragment_4);
	controller.setMode('B');
	std::vector<AnomalousFragment> result = controller.listFiltered("aaa", 100);
	std::vector<AnomalousFragment> check{ new_fragment_2, new_fragment_3 };
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 2);
	try {
		controller.setMode('A');
		controller.listFiltered("aaa", 100);
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
}


void Test::testNext() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	assert(controller.listAll().size() == 0);
	AnomalousFragment new_fragment_1{ "id_1", "size_1", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "size_2", 12.3, 22, "photo_1" };
	controller.add(new_fragment_2);
	controller.setMode('B');
	AnomalousFragment result = controller.nextFragment();
	assert(compare(result, new_fragment_1));
	result = controller.nextFragment();
	assert(compare(result, new_fragment_2));
	result = controller.nextFragment();
	assert(compare(result, new_fragment_1));
	try {
		controller.setMode('A');
		controller.nextFragment();
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
	FileRepository repository2{};
	MemoryRepository user_list2{};
	Controller controller2{ &repository2, &user_list2 };
	controller2.setMode('B');
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller2.changeFile("../Tests/path/Default.txt");
	try {
		controller2.nextFragment();
		assert(false);
	}
	catch (EmptyRepository& empty_repository_error) {
		assert(true);
	}
}


void Test::testMyListPlusSave() {
	FileRepository repository{};
	MemoryRepository user_list{};
	Controller controller{ &repository, &user_list };
	controller.setMode('A');
	std::ofstream file_to_clear;
	file_to_clear.open("../Tests/path/Default.txt");
	file_to_clear << "0";
	file_to_clear.close();
	controller.changeFile("../Tests/path/Default.txt");
	assert(controller.listAll().size() == 0);
	AnomalousFragment new_fragment_1{ "id_1", "aaa", 12.3, 22, "photo_1" };
	controller.add(new_fragment_1);
	AnomalousFragment new_fragment_2{ "id_2", "aaa", 12.3, 100, "photo_1" };
	controller.add(new_fragment_2);
	AnomalousFragment new_fragment_3{ "id_3", "aaa", 12.3, 100, "photo_1" };
	controller.add(new_fragment_3);
	AnomalousFragment new_fragment_4{ "id_4", "size_4", 12.3, 100, "photo_1" };
	controller.add(new_fragment_4);
	controller.setMode('B');
	controller.saveFragment("id_3");
	controller.saveFragment("id_2");
	controller.saveFragment("id_4");
	std::vector<AnomalousFragment> result = controller.showUserList();
	std::vector<AnomalousFragment> check{ new_fragment_3, new_fragment_2, new_fragment_4 };
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 3);
	try {
		controller.saveFragment("id_3");
		assert(false);
	}
	catch (ElementAlreadyExists& add_error) {
		assert(true);
	}
	result = controller.showUserList();
	assert(std::equal(result.begin(), result.end(), check.begin(), compare) && result.size() == 3);
	try {
		controller.setMode('A');
		controller.saveFragment("id_1");
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
	try {
		controller.setMode('A');
		controller.showUserList();
		assert(false);
	}
	catch (ModeError& mode_error) {
		assert(true);
	}
}


void Test::testAll() {
	Test::testMode();
	Test::testFileLocation();

	Test::testAdd();
	Test::testListA();
	Test::testUpdate();
	Test::testDelete();
	
	Test::testListB();
	Test::testNext();
	Test::testMyListPlusSave();
}