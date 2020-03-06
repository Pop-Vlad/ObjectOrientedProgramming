#pragma once

#include <qwidget.h>
#include <qpainter.h>
#include <qpen.h>
#include <QKeyEvent>



class PieChart : public QWidget {

	Q_OBJECT

private:

	double percentage;


protected:

	void paintEvent(QPaintEvent *event) override;


public:

	PieChart(const double& input_percentage, QWidget *parent = 0);

	void setNewPercentage(const double& input_percentage);

	QSize sizeHint() const Q_DECL_OVERRIDE;

	void paintChart();


};



class Photograph : public QWidget {

	Q_OBJECT

private:

	std::string photo_string;


protected:

	void paintEvent(QPaintEvent *event) override;


public:

	Photograph(const std::string& input_photograph, QWidget *parent = 0);

	void setNewPhoto(const std::string& input_photograph);

	QSize sizeHint() const Q_DECL_OVERRIDE;

	void paintChart();


};