#pragma once
#include <iostream>
#include <ctype.h>  
#include <cstdlib> 
using namespace std;

//������ ������ �ٲٱ� ���� ����
class CharStack {
private: //class ���� ����
	double stack[100];
	int top;
public: // ����/�ܺ� ���� ����
	CharStack() { top = -1; }
	void push(char val) { stack[++top] = val; }  //stack�� val �� �ֱ�
	char pop() { return stack[top--]; }   //stack�� �� ����
	int isEmpty() { return top == -1; }
	int isFull() { return top == 99; }
	char getTop() { return stack[top]; }
};

//intStack  -- postfix result ������ ���� stack
class IntStack {
private:
	double stack[100];
	int top;
public:
	IntStack() { top = -1; }
	void push(double val) { stack[++top] = val; }
	double pop() { return stack[top--]; }
	int isEmpty() { return top == -1; }
	int isFull() { return top == 99; }
};

//calculator class ����
class mainCalculator {
private:
	char buffer[80];
	char postfix[80];

	IntStack s1;
	CharStack s2;

	void infixTopostfix();
	double result();
	int priority(char);

public:
	double calculate(char[]);
};