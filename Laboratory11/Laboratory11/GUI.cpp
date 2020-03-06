#include "GUI.h"



GUI::GUI(Controller* input_controller, QWidget *parent) : QWidget{ parent } {
	this->controller = input_controller;
	this->controller->setMode('A');
	this->validator = new Validator{};
	this->initGUI();
	this->connectSignals();
	this->populateFragmentsList();
}


void GUI::initGUI() {
	QVBoxLayout* window_layout = new QVBoxLayout{ this };
	QFont window_font{ "Verdana", 15 };
	
	QWidget* menu_widget = new QWidget{};
	QHBoxLayout* menu_layout = new QHBoxLayout{ menu_widget };
	this->file_location = new QPushButton{ "File" };
	this->file_location->setFont(window_font);
	menu_layout->addWidget(this->file_location);
	this->mylist_location = new QPushButton{ "Mylist" };
	this->mylist_location->setFont(window_font);
	menu_layout->addWidget(this->mylist_location);
	this->modeA_button = new QPushButton{ "Mode A" };
	this->modeA_button->setFont(window_font);
	menu_layout->addWidget(this->modeA_button);
	this->modeB_button = new QPushButton{ "Mode B" };
	this->modeB_button->setFont(window_font);
	menu_layout->addWidget(this->modeB_button);
	window_layout->addWidget(menu_widget);
	QWidget* main_widget = new QWidget{};
	QHBoxLayout* main_layout = new QHBoxLayout{ main_widget };

	//Mode A
	QWidget* modeA_widget = new QWidget{};
	QHBoxLayout* modeA_layout = new QHBoxLayout{ modeA_widget };

	this->fragments_list = new QListWidget{};
	this->fragments_list->setSelectionMode(QAbstractItemView::SingleSelection);
	modeA_layout->addWidget(this->fragments_list);
	QWidget* right_side = new QWidget{};
	QVBoxLayout* right_side_layout = new QVBoxLayout{ right_side };

	QWidget* data_widget = new QWidget{};
	QFormLayout* data_layout = new QFormLayout{ data_widget };
	this->id_edit = new QLineEdit{};
	this->size_edit = new QLineEdit{};
	this->infection_edit = new QLineEdit{};
	this->microfragments_edit = new QLineEdit{};
	this->photograph_edit = new QLineEdit{};
	QLabel* id_label = new QLabel{ "Id:" };
	id_label->setBuddy(this->id_edit);
	QLabel* size_label = new QLabel{ "Size:" };
	size_label->setBuddy(this->size_edit);
	QLabel* infection_label = new QLabel{ "Infection:" };
	infection_label->setBuddy(this->infection_edit);
	QLabel* microfragments_label = new QLabel{ "Microfragments:" };
	microfragments_label->setBuddy(this->microfragments_edit);
	QLabel* photograph_label = new QLabel{ "Photograph:" };
	photograph_label->setBuddy(photograph_edit);
	id_label->setFont(window_font);
	size_label->setFont(window_font);
	infection_label->setFont(window_font);
	microfragments_label->setFont(window_font);
	photograph_label->setFont(window_font);
	this->id_edit->setFont(window_font);
	this->size_edit->setFont(window_font);
	this->infection_edit->setFont(window_font);
	this->microfragments_edit->setFont(window_font);
	this->photograph_edit->setFont(window_font);
	data_layout->addRow(id_label, this->id_edit);
	data_layout->addRow(size_label, this->size_edit);
	data_layout->addRow(infection_label, this->infection_edit);
	data_layout->addRow(microfragments_label, this->microfragments_edit);
	data_layout->addRow(photograph_label, this->photograph_edit);

	QWidget* drawings = new QWidget{};
	QHBoxLayout* drawings_layout = new QHBoxLayout{ drawings };
	this->infection_chart = new PieChart{ 0 };
	drawings_layout->addWidget(infection_chart);
	this->photograph = new Photograph{ "" };
	drawings_layout->addWidget(this->photograph);

	QWidget* buttons_widget = new QWidget{};
	QVBoxLayout* buttons_layout = new QVBoxLayout{ buttons_widget };
	this->add_button = new QPushButton{ "Add" };
	this->add_button->setFont(window_font);
	this->update_button = new QPushButton{ "Update" };
	this->update_button->setFont(window_font);
	this->delete_button = new QPushButton{ "Delete" };
	this->delete_button->setFont(window_font);
	buttons_layout->addWidget(this->add_button);
	buttons_layout->addWidget(this->update_button);
	buttons_layout->addWidget(this->delete_button);

	right_side_layout->addWidget(data_widget);
	right_side_layout->addWidget(drawings);
	right_side_layout->addWidget(buttons_widget);
	modeA_layout->addWidget(right_side);

	//Mode B
	QWidget* modeB_widget = new QWidget{};
	QVBoxLayout* modeB_layout = new QVBoxLayout{ modeB_widget };

	QLabel* current_fragment_label = new QLabel{ "Current:" };
	current_fragment_label->setFont(window_font);
	modeB_layout->addWidget(current_fragment_label);
	this->current_fragment = new QLineEdit{};
	this->current_fragment->setFont(window_font);
	modeB_layout->addWidget(current_fragment);

	QWidget* buttons_row = new QWidget{};
	QHBoxLayout* buttons_row_layout = new QHBoxLayout{ buttons_row };
	this->next_button = new QPushButton{ "Next" };
	this->next_button->setFont(window_font);
	this->save_button = new QPushButton{ "Save" };
	this->save_button->setFont(window_font);
	buttons_row_layout->addWidget(this->save_button);
	buttons_row_layout->addWidget(this->next_button);
	modeB_layout->addWidget(buttons_row);

	//
	QWidget* search_widget = new QWidget{};
	QFormLayout* search_form = new QFormLayout{ search_widget };
	this->size_search_edit = new QLineEdit{};
	this->microfragments_search_edit = new QLineEdit{};
	QLabel* size_search_label = new QLabel{ "Size:" };
	size_search_label->setBuddy(this->size_search_edit);
	QLabel* microfragments_search_label = new QLabel{ "Microfragments:" };
	microfragments_search_label->setBuddy(this->microfragments_search_edit);
	size_search_label->setFont(window_font);
	microfragments_search_label->setFont(window_font);
	this->size_search_edit->setFont(window_font);
	this->microfragments_search_edit->setFont(window_font);
	search_form->addRow(size_search_label, this->size_search_edit);
	search_form->addRow(microfragments_search_label, this->microfragments_search_edit);
	modeB_layout->addWidget(search_widget);
	this->search_button = new QPushButton{ "Search" };
	this->search_button->setFont(window_font);
	modeB_layout->addWidget(this->search_button);

	QLabel* mylist_label = new QLabel{ "Mylist:" };
	mylist_label->setFont(window_font);
	modeB_layout->addWidget(mylist_label);
	this->mylist = new QListWidget{};
	this->mylist->setSelectionMode(QAbstractItemView::SingleSelection);
	modeB_layout->addWidget(this->mylist);
	
	main_layout->addWidget(modeA_widget);
	QSpacerItem* spacer = new QSpacerItem{ 100, 10 };
	main_layout->addSpacerItem(spacer);
	main_layout->addWidget(modeB_widget);
	window_layout->addWidget(main_widget);
}


void GUI::connectSignals() {
	QObject::connect(this->modeA_button, &QPushButton::clicked, this, &GUI::switchToModeA);
	QObject::connect(this->modeB_button, &QPushButton::clicked, this, &GUI::switchToModeB);
	QObject::connect(this->add_button, &QPushButton::clicked, this, &GUI::addFragment);
	QObject::connect(this->update_button, &QPushButton::clicked, this, &GUI::updateFragment);
	QObject::connect(this->delete_button, &QPushButton::clicked, this, &GUI::deleteFragmant);
	QObject::connect(this->fragments_list, &QListWidget::itemSelectionChanged, this, &GUI::listDataFromIndex);
}


void GUI::populateFragmentsList() {
	try {
		QFont font{ "Verdana", 15 };
		this->fragments_list->clear();
		for (auto current : this->controller->listAll()) {
			QString current_item_string = QString::fromStdString(current.toString());
			QListWidgetItem* current_item = new QListWidgetItem{ current_item_string };
			current_item->setFont(font);
			this->fragments_list->addItem(current_item);
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
		QModelIndexList qt_indexes = this->fragments_list->selectionModel()->selectedIndexes();
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
}


void GUI::listDataFromIndex() {
	try {
		int index = this->getSelectedFragment();
		if (index == -1)
			return;
		AnomalousFragment selected_fragment = this->controller->getFragment(index);
		this->id_edit->setText(QString::fromStdString(selected_fragment.getId()));
		this->size_edit->setText(QString::fromStdString(selected_fragment.getSize()));
		this->infection_edit->setText(QString::fromStdString(std::to_string(selected_fragment.getInfectionLevel())));
		this->microfragments_edit->setText(QString::fromStdString(std::to_string(selected_fragment.getMicrofragments())));
		this->photograph_edit->setText(QString::fromStdString(selected_fragment.getPhotograph()));
		this->infection_chart->setNewPercentage(selected_fragment.getInfectionLevel());
		this->photograph->setNewPhoto(selected_fragment.getPhotograph());
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


void GUI::switchToModeA() {
	this->controller->setMode('A');
}


void GUI::switchToModeB() {
	this->controller->setMode('B');
}


void GUI::addFragment() {
	try {
		std::vector<std::string> arguments;
		std::string new_id = this->id_edit->text().toStdString();
		std::string new_size = this->size_edit->text().toStdString();
		std::string new_infection = this->infection_edit->text().toStdString();
		std::string new_microfragments = this->microfragments_edit->text().toStdString();
		std::string new_photo = this->photograph_edit->text().toStdString();
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
		std::string new_id = this->id_edit->text().toStdString();
		std::string new_size = this->size_edit->text().toStdString();
		std::string new_infection = this->infection_edit->text().toStdString();
		std::string new_microfragments = this->microfragments_edit->text().toStdString();
		std::string new_photo = this->photograph_edit->text().toStdString();
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
		std::string id_to_remove = this->id_edit->text().toStdString();
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