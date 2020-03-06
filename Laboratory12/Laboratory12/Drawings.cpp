#include "Drawings.h"



PieChart::PieChart(const double& input_percentage, QWidget *parent) : QWidget{ parent } {
	this->percentage = input_percentage;
}


void PieChart::setNewPercentage(const double& input_percentage) {
	this->percentage = input_percentage;
	this->paintChart();
}


QSize PieChart::sizeHint() const {
	return QSize{ 100, 100 };
}


void PieChart::paintChart() {
	QPainter painter{ this };
	painter.eraseRect(0, 0, 100, 100);

	QRectF size(0, 0, 100, 100);
	int spanAngle = (this->percentage / 4.4) * 16;
	painter.setBrush(Qt::green);
	painter.drawPie(size, 0, spanAngle * 16);
	painter.setBrush(Qt::gray);
	painter.drawPie(size, spanAngle * 16, (360 - spanAngle) * 16);
}


void PieChart::paintEvent(QPaintEvent *event) {
	this->paintChart();
}



Photograph::Photograph(const std::string& input_photograph, QWidget *parent) : QWidget{ parent } {
	this->photo_string = input_photograph;
}


void Photograph::setNewPhoto(const std::string& input_photograph) {
	this->photo_string = input_photograph;
	this->paintChart();
}


QSize Photograph::sizeHint() const {
	return QSize{ 150, 100 };
}


void Photograph::paintChart() {
	std::hash<std::string> str_hash;
	int hash = str_hash(this->photo_string);
	srand(hash);

	QPainter painter{ this };
	painter.eraseRect(0, 0, 150, 100);
	QRectF size(0, 0, 150, 100);
	painter.setBrush(Qt::red);

	QPointF points[6];
	points[0] = QPointF(rand() % 50, rand() % 50);
	points[1] = QPointF(rand() % 50 + 50, rand() % 50);
	points[2] = QPointF(rand() % 50 + 100, rand() % 50);
	points[5] = QPointF(rand() % 50, rand() % 50 + 50);
	points[4] = QPointF(rand() % 50 + 50, rand() % 50 + 50);
	points[3] = QPointF(rand() % 50 + 100, rand() % 50 + 50);
	painter.drawPolygon(points, 6);
}


void Photograph::paintEvent(QPaintEvent *event) {
	this->paintChart();
}