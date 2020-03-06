#include "GUI.h"



GUI::GUI(Controller* input_controller, QWidget *parent) : controller(input_controller), QMainWindow(parent) {
	ui.setupUi(this);
	this->controller->setMode('A');
	this->validator = new Validator{};
	this->initGUI();
	this->connectSignals();
	this->populateFragmentsList();
}


void GUI::initGUI() {
	QShortcut* shortcut1 = new QShortcut(QKeySequence(tr("Ctrl+Z")), this);
	QObject::connect(shortcut1, &QShortcut::activated, this, &GUI::undo);
	QShortcut* shortcut2 = new QShortcut(QKeySequence(tr("Ctrl+Y")), this);
	QObject::connect(shortcut2, &QShortcut::activated, this, &GUI::redo);
}


void GUI::connectSignals() {
	QObject::connect(this->ui.fileButton, &QPushButton::clicked, this, &GUI::changeFile);
	QObject::connect(this->ui.mylistButton, &QPushButton::clicked, this, &GUI::changeMylist);
	QObject::connect(this->ui.tab, &QTabWidget::currentChanged, this, &GUI::switchMode);
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &GUI::addFragment);
	QObject::connect(this->ui.updateButton, &QPushButton::clicked, this, &GUI::updateFragment);
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &GUI::deleteFragmant);
	QObject::connect(this->ui.undoButton, &QPushButton::clicked, this, &GUI::undo);
	QObject::connect(this->ui.redoButton, &QPushButton::clicked, this, &GUI::redo);
	QObject::connect(this->ui.mainList, &QListWidget::itemSelectionChanged, this, &GUI::listDataFromIndex);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &GUI::saveFragment);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &GUI::nextFragment);
	QObject::connect(this->ui.searchButton, &QPushButton::clicked, this, &GUI::search);
	QObject::connect(this->ui.showMylistButton, &QPushButton::clicked, this, &GUI::showMylist);
}



void GUI::populateFragmentsList() {
	try {
		QFont font{ "Arial", 12 };
		this->ui.mainList->clear();
		for (auto current : this->controller->listAll()) {
			QString current_item_string = QString::fromStdString(current.toString());
			QListWidgetItem* current_item = new QListWidgetItem{ current_item_string };
			current_item->setFont(font);
			this->ui.mainList->addItem(current_item);
		}
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


int GUI::getSelectedFragment() const {
	try {
		if (this->controller->listAll().size() == 0)
			return -1;
		QModelIndexList qt_indexes = this->ui.mainList->selectionModel()->selectedIndexes();
		if (qt_indexes.size() == 0)
			return -1;
		return qt_indexes.at(0).row();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
	return -1;
}


void GUI::listDataFromIndex() {
	try {
		int index = this->getSelectedFragment();
		if (index == -1)
			return;
		AnomalousFragment selected_fragment = this->controller->getFragment(index);
		this->ui.idEdit->setText(QString::fromStdString(selected_fragment.getId()));
		this->ui.sizeEdit->setText(QString::fromStdString(selected_fragment.getSize()));
		this->ui.infectionEdit->setText(QString::fromStdString(std::to_string(selected_fragment.getInfectionLevel())));
		this->ui.microfragmentsEdit->setText(QString::fromStdString(std::to_string(selected_fragment.getMicrofragments())));
		this->ui.photographEdit->setText(QString::fromStdString(selected_fragment.getPhotograph()));
		this->update();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::changeFile() {
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;CSV Files (*.csv);;HTML Files(*.html)");
	try {
		if (fileName != "") {
			this->controller->changeFile(fileName.toStdString());
			this->populateFragmentsList();
		}
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::changeMylist() {
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;CSV Files (*.csv);;HTML Files(*.html)");
	try {
		if (fileName != "") {
			this->controller->changeMyList(fileName.toStdString());
		}
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::switchMode() {
	if (this->ui.tab->currentIndex() == 0)
		this->controller->setMode('A');
	if (this->ui.tab->currentIndex() == 1)
		this->controller->setMode('B');
}


void GUI::addFragment() {
	try {
		std::vector<std::string> arguments;
		std::string new_id = this->ui.idEdit->text().toStdString();
		std::string new_size = this->ui.sizeEdit->text().toStdString();
		std::string new_infection = this->ui.infectionEdit->text().toStdString();
		std::string new_microfragments = this->ui.microfragmentsEdit->text().toStdString();
		std::string new_photo = this->ui.photographEdit->text().toStdString();
		arguments.push_back("add");
		arguments.push_back(new_id);
		arguments.push_back(new_size);
		arguments.push_back(new_infection);
		arguments.push_back(new_microfragments);
		arguments.push_back(new_photo);
		if (!this->validator->validateInput(arguments)) {
			throw GenericException{ "Invalid input" };
		}
		AnomalousFragment new_fragment{ new_id, new_size, std::stod(new_infection), std::stoi(new_microfragments), new_photo };
		this->controller->add(new_fragment);
		this->populateFragmentsList();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::updateFragment() {
	try {
		std::vector<std::string> arguments;
		std::string new_id = this->ui.idEdit->text().toStdString();
		std::string new_size = this->ui.sizeEdit->text().toStdString();
		std::string new_infection = this->ui.infectionEdit->text().toStdString();
		std::string new_microfragments = this->ui.microfragmentsEdit->text().toStdString();
		std::string new_photo = this->ui.photographEdit->text().toStdString();
		arguments.push_back("add");
		arguments.push_back(new_id);
		arguments.push_back(new_size);
		arguments.push_back(new_infection);
		arguments.push_back(new_microfragments);
		arguments.push_back(new_photo);
		if (!this->validator->validateInput(arguments)) {
			throw GenericException{ "Invalid input" };
		}
		AnomalousFragment new_fragment{ new_id, new_size, std::stod(new_infection), std::stoi(new_microfragments), new_photo };
		this->controller->update(new_fragment);
		this->populateFragmentsList();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::deleteFragmant() {
	try {
		std::vector<std::string> arguments;
		std::string id_to_remove = this->ui.idEdit->text().toStdString();
		arguments.push_back("delete");
		arguments.push_back(id_to_remove);
		if (!this->validator->validateInput(arguments)) {
			throw GenericException{ "Invalid input" };
		}
		this->controller->remove(id_to_remove);
		this->populateFragmentsList();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::undo() {
	try {
		this->controller->undo();
		this->populateFragmentsList();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::redo() {
	try {
		this->controller->redo();
		this->populateFragmentsList();
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::nextFragment() {
	try {
		AnomalousFragment current_fragment = this->controller->nextFragment();
		this->ui.currentEdit->setText(QString::fromStdString(current_fragment.toString()));
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::saveFragment() {
	try {
		std::string current_fragment_string = this->ui.currentEdit->text().toStdString();
		std::string current_id = current_fragment_string.substr(0, current_fragment_string.find_first_of(" "));
		std::vector<std::string> arguments;
		arguments.push_back("save");
		arguments.push_back(current_id);
		if (!this->validator->validateInput(arguments)) {
			throw GenericException{ "Invalid input" };
		}
		this->controller->saveFragment(current_id);
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::search() {
	try {
		std::string size_search = this->ui.searchSizeEdit->text().toStdString();
		std::string microfragments_search = this->ui.searchMicrofragmetnsEdit->text().toStdString();
		std::vector<std::string> arguments;
		arguments.push_back("list");
		arguments.push_back(size_search);
		arguments.push_back(microfragments_search);
		if (!this->validator->validateInput(arguments)) {
			throw GenericException{ "Invalid input" };
		}
		std::vector<AnomalousFragment> results = this->controller->listFiltered(size_search, std::stoi(microfragments_search));
		this->showSearchResults(results);
	}
	catch (GenericException& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", exception.what());
		messageBox.setFixedSize(500, 200);
	}
	catch (std::exception& exception) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "An error occured");
		messageBox.setFixedSize(500, 200);
	}
}


void GUI::showSearchResults(const std::vector<AnomalousFragment>& results) {
	QWidget* window = new QWidget{};
	QHBoxLayout* layout = new QHBoxLayout{ window };
	window->resize(300, 600);
	QListWidget* list = new QListWidget{};
	QFont font{ "Arial", 12 };
	list->clear();
	for (auto current : results) {
		QString current_item_string = QString::fromStdString(current.toString());
		QListWidgetItem* current_item = new QListWidgetItem{ current_item_string };
		current_item->setFont(font);
		list->addItem(current_item);
	}
	layout->addWidget(list);
	window->show();
}


void GUI::showMylist() {
	QWidget* window = new QWidget{};
	QHBoxLayout* layout = new QHBoxLayout{ window };
	window->resize(300, 600);
	TableModel* list = new TableModel{ this-};
	QFont font{ "Arial", 12 };
	list->();
	for (AnomalousFragment current : this->controller->showUserList()) {
		QString current_item_string = QString::fromStdString(current.toString());
		QListWidgetItem* current_item = new QListWidgetItem{ current_item_string };
		current_item->setFont(font);
		list->addItem(current_item);
	}
	layout->addWidget(list);
	window->show();
}