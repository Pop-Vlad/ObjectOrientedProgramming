#include "DevelopGUI.h"

DevelopGUI::DevelopGUI(std::string content, QWidget *parent): content(content), QMainWindow(parent) {
	ui.setupUi(this);
	this->ui.textEdit->setText(QString::fromStdString(this->content));
	this->connectSignals();
}


void DevelopGUI::connectSignals() {
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &DevelopGUI::save);
}


void DevelopGUI::save() {
	std::string result = this->ui.textEdit->toPlainText().toStdString();
	auto fileName = QFileDialog::getOpenFileName(this, tr("Open"), "./", tr("Image Files (*.txt)"));
	std::ofstream f{ fileName.toStdString() };
	f << result;
	f.close();
}