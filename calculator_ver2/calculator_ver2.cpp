#include "calculator_ver2.h"
#include "stack.h"
#include <cstring>

calculator_ver2::calculator_ver2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(500, 300);

	// Button click function
	connect(ui.num0Btn,		 &QPushButton::clicked, this, &calculator_ver2::num0_Clicked);
	connect(ui.num1Btn,		 &QPushButton::clicked, this, &calculator_ver2::num1_Clicked);
	connect(ui.num2Btn,		 &QPushButton::clicked, this, &calculator_ver2::num2_Clicked);
	connect(ui.num3Btn,		 &QPushButton::clicked, this, &calculator_ver2::num3_Clicked);
	connect(ui.num4Btn,		 &QPushButton::clicked, this, &calculator_ver2::num4_Clicked);
	connect(ui.num5Btn,		 &QPushButton::clicked, this, &calculator_ver2::num5_Clicked);
	connect(ui.num6Btn,		 &QPushButton::clicked, this, &calculator_ver2::num6_Clicked);
	connect(ui.num7Btn,		 &QPushButton::clicked, this, &calculator_ver2::num7_Clicked);
	connect(ui.num8Btn,		 &QPushButton::clicked, this, &calculator_ver2::num8_Clicked);
	connect(ui.num9Btn,		 &QPushButton::clicked, this, &calculator_ver2::num9_Clicked);

	connect(ui.plusBtn,		 &QPushButton::clicked, this, &calculator_ver2::plusBtn_Clicked);
	connect(ui.minusBtn,	 &QPushButton::clicked, this, &calculator_ver2::minusBtn_Clicked);
	connect(ui.multiplyBtn,  &QPushButton::clicked, this, &calculator_ver2::multiplyBtn_Clicked);
	connect(ui.divisionBtn,  &QPushButton::clicked, this, &calculator_ver2::divisionBtn_Clicked);
	connect(ui.remainderBtn, &QPushButton::clicked, this, &calculator_ver2::remainderBtn_Clicked);
	connect(ui.resultBtn,	 &QPushButton::clicked, this, &calculator_ver2::resultBtn_Clicked);

	// Calcuation option
	connect(ui.delAllBtn,	 &QPushButton::clicked, this, &calculator_ver2::deleteAll_Clicked);
}

void calculator_ver2::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_0:
		num0_Clicked();
		break;

	case Qt::Key_1:
		num1_Clicked();
		break;

	case Qt::Key_2:
		num2_Clicked();
		break;

	case Qt::Key_3:
		num3_Clicked();
		break;

	case Qt::Key_4:
		num4_Clicked();
		break;

	case Qt::Key_5:
		num5_Clicked();
		break;

	case Qt::Key_6:
		num6_Clicked();
		break;

	case Qt::Key_7:
		num7_Clicked();
		break;

	case Qt::Key_8:
		num8_Clicked();
		break;

	case Qt::Key_9:
		num9_Clicked();
		break;

	case Qt::Key_Plus:
		plusBtn_Clicked();
		break;

	case Qt::Key_Minus:
		minusBtn_Clicked();
		break;

	case Qt::Key_Asterisk:
		multiplyBtn_Clicked();
		break;

	case Qt::Key_Slash:
		divisionBtn_Clicked();
		break;

	case Qt::Key_Percent:
		remainderBtn_Clicked();
		break;

	case Qt::Key_Enter:
		resultBtn_Clicked();
		break;

	case Qt::Key_Return:
		resultBtn_Clicked();
		break;

	case Qt::Key_Delete:
		deleteAll_Clicked();
		break;
		
	default:
		break;
	}
}

void calculator_ver2::num0_Clicked()
{
	progress += '0';
	ui.progress->setText(progress);
}

void calculator_ver2::num1_Clicked()
{
	progress += '1';
	ui.progress->setText(progress);
}

void calculator_ver2::num2_Clicked()
{
	progress += '2';
	ui.progress->setText(progress);
}

void calculator_ver2::num3_Clicked()
{
	progress += '3';
	ui.progress->setText(progress);
}

void calculator_ver2::num4_Clicked()
{
	progress += '4';
	ui.progress->setText(progress);
}

void calculator_ver2::num5_Clicked()
{
	progress += '5';
	ui.progress->setText(progress);
}

void calculator_ver2::num6_Clicked()
{
	progress += '6';
	ui.progress->setText(progress);
}

void calculator_ver2::num7_Clicked()
{
	progress += '7';
	ui.progress->setText(progress);
}

void calculator_ver2::num8_Clicked()
{
	progress += '8';
	ui.progress->setText(progress);
}

void calculator_ver2::num9_Clicked()
{
	progress += '9';
	ui.progress->setText(progress);
}

void calculator_ver2::plusBtn_Clicked()
{
	progress += '+';
	ui.progress->setText(progress);
}

void calculator_ver2::minusBtn_Clicked()
{
	progress += '-';
	ui.progress->setText(progress);
}

void calculator_ver2::multiplyBtn_Clicked()
{
	progress += '*';
	ui.progress->setText(progress);
}

void calculator_ver2::divisionBtn_Clicked()
{
	progress += '/';
	ui.progress->setText(progress);
}

void calculator_ver2::remainderBtn_Clicked()
{
	progress += '%';
	ui.progress->setText(progress);
}

void calculator_ver2::resultBtn_Clicked()
{
	mainCalculator inputFormula;
	result = ui.progress->text();
	QByteArray byteName = result.toLocal8Bit();
	char* cfileNmae = byteName.data();
	double answer = inputFormula.calculate(cfileNmae);
	QString s = QString::number(answer);
	ui.result->setText(s);
}

void calculator_ver2::deleteAll_Clicked()
{
	ui.progress->setText("");
	ui.result->setText("");
	ui.binNumber->setText("");
	ui.octNumber->setText("");
	ui.decNumber->setText("");
	ui.hexNumber->setText("");

	progress = "";
	result = '0';
}

void calculator_ver2::numberSystemConversion()
{
	decToBin();
	decToOct();
	decToDec();
	decToHex();
}

void calculator_ver2::decToBin()
{
	QString bin = QString("%1").arg(ui.progress->text().toInt(), 0, 2);
	ui.binNumber->setText(bin);
}

void calculator_ver2::decToOct()
{
	QString oct = QString("%1").arg(ui.progress->text().toInt(), 0, 8);
	ui.octNumber->setText(oct);
}

void calculator_ver2::decToDec()
{
	QString dec = QString("%1").arg(ui.progress->text().toInt(), 0, 10);
	ui.decNumber->setText(dec);
}

void calculator_ver2::decToHex()
{
	QString hex = QString("%1").arg(ui.progress->text().toInt(), 0, 16);
	ui.hexNumber->setText(hex);
}