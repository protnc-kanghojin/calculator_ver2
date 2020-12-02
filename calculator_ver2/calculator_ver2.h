#pragma once

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>

#include "ui_calculator_ver2.h"

class calculator_ver2 : public QMainWindow
{
    Q_OBJECT

public:
    calculator_ver2(QWidget *parent = Q_NULLPTR);
	
	QString progress = "";
	QString finalResult = '0';

public slots:
	// Number button
    void num0_Clicked();
	void num1_Clicked();
	void num2_Clicked();
	void num3_Clicked();
	void num4_Clicked();
	void num5_Clicked();
	void num6_Clicked();
	void num7_Clicked();
	void num8_Clicked();
	void num9_Clicked();

	// Four rules calculation button
	void plusBtn_Clicked();
	void minusBtn_Clicked();
	void multiplyBtn_Clicked();
	void divisionBtn_Clicked();
	void resultBtn_Clicked();

	// Function button
	void deleteAll_Clicked();
	void deleteOne_Clicked();
	void exclamBtn_Clicked();

	// Number system conversion
	void numberSystemConversion();
	void decToBin();
	void decToOct();
	void decToDec();
	void decToHex();

private:
    Ui::calculator_ver2Class ui;

protected:
    void keyPressEvent(QKeyEvent* event); // Keyboard button press event
};