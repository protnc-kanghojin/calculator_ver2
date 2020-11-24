#include "calculator_ver2.h"

calculator_ver2::calculator_ver2(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(500, 400);
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
	default:
		break;
	}
}

void calculator_ver2::num0_Clicked()
{
	int m_result = ui.num0Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num1_Clicked()
{
	int m_result = ui.num1Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num2_Clicked()
{
	int m_result = ui.num2Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num3_Clicked()
{
	int m_result = ui.num3Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num4_Clicked()
{
	int m_result = ui.num4Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num5_Clicked()
{
	int m_result = ui.num5Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num6_Clicked()
{
	int m_result = ui.num6Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num7_Clicked()
{
	int m_result = ui.num7Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num8_Clicked()
{
	int m_result = ui.num8Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}

void calculator_ver2::num9_Clicked()
{
	int m_result = ui.num9Btn->text().toInt();

	ui.progress->setText(ui.progress->text() + QString::number(m_result));
}