#include "calculator_ver2.h"
#include "mainCalculator.h"
#include <cstring>

calculator_ver2::calculator_ver2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(250, 350);

	// Number button
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

	// Four rules calculation button
	connect(ui.plusBtn,		 &QPushButton::clicked, this, &calculator_ver2::plusBtn_Clicked);
	connect(ui.minusBtn,		 &QPushButton::clicked, this, &calculator_ver2::minusBtn_Clicked);
	connect(ui.multiplyBtn,	 &QPushButton::clicked, this, &calculator_ver2::multiplyBtn_Clicked);
	connect(ui.divisionBtn,	 &QPushButton::clicked, this, &calculator_ver2::divisionBtn_Clicked);

	// Function button
	connect(ui.delAllBtn,		 &QPushButton::clicked, this, &calculator_ver2::deleteAll_Clicked);
	connect(ui.delOneBtn,	 &QPushButton::clicked, this, &calculator_ver2::deleteOne_Clicked);
	connect(ui.resultBtn,		 &QPushButton::clicked, this, &calculator_ver2::resultBtn_Clicked);
	connect(ui.exclamBtn,		 &QPushButton::clicked, this, &calculator_ver2::exclamBtn_Clicked);
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

	case Qt::Key_Delete:
		deleteAll_Clicked();
		break;
		
	case Qt::Key_Backspace:
		deleteOne_Clicked();
		break;

	case Qt::Key_Return:
		resultBtn_Clicked();
		break;

	case Qt::Key_Enter:
		resultBtn_Clicked();
		break;

	case Qt::Key_exclamdown:
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

void calculator_ver2::resultBtn_Clicked()
{
	mainCalculator formulaInput;
	finalResult = ui.progress->text();
	QByteArray byteName = finalResult.toLocal8Bit();
	char* cfileName = byteName.data();
	double answer = formulaInput.calculate(cfileName);
	QString s = QString::number(answer);
	ui.result->setText(s);

	numberSystemConversion();
}

void calculator_ver2::deleteAll_Clicked()
{
	ui.progress->setText("Input Formula");
	ui.result->setText("Result");
	ui.binNumber->setText("BINARY");
	ui.octNumber->setText("OCTAL");
	ui.decNumber->setText("DECIMAL");
	ui.hexNumber->setText("HEXADECIMAL");

	progress = "";
	finalResult = '0';
}

void calculator_ver2::deleteOne_Clicked()
{
	progress.chop(1);
	ui.progress->setText(progress);
}

void calculator_ver2::exclamBtn_Clicked()
{
	int m_fac = ui.progress->text().toInt();
	int fac = 1;

	if (m_fac <= 1)
	{
		ui.result->setText("1");
	}
	else
	{
		while (m_fac != 1)
		{
			fac = fac * m_fac;
			m_fac--;
		}
		ui.result->setText(QString::number(fac));
	}
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
	QString bin = QString("%1").arg(ui.result->text().toInt(), 0, 2);
	ui.binNumber->setText(bin);
}

void calculator_ver2::decToOct()
{
	QString oct = QString("%1").arg(ui.result->text().toInt(), 0, 8);
	ui.octNumber->setText(oct);
}

void calculator_ver2::decToDec()
{
	QString dec = QString("%1").arg(ui.result->text().toInt(), 0, 10);
	ui.decNumber->setText(dec);
}

void calculator_ver2::decToHex()
{
	QString hex = QString("%1").arg(ui.result->text().toInt(), 0, 16);
	ui.hexNumber->setText(hex);
}