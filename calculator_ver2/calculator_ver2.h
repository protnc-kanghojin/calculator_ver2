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
	QString result = '0';

public slots:
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

	void plusBtn_Clicked();
	void minusBtn_Clicked();
	void multiplyBtn_Clicked();
	void divisionBtn_Clicked();
	void remainderBtn_Clicked();
	void resultBtn_Clicked();
	void deleteAll_Clicked();

	void numberSystemConversion();
	void decToBin();
	void decToOct();
	void decToDec();
	void decToHex();

private:
    Ui::calculator_ver2Class ui;

protected:
    void keyPressEvent(QKeyEvent* event);
};
