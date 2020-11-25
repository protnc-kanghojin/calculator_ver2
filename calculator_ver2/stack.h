#pragma once

#include <iostream>
#include <ctype.h>  
#include <cstdlib> 


using namespace std;


class stackChar {
private:
	double stack[100];
	int top;

public:
	stackChar() { top = -1; }
	void push(char val) { stack[++top] = val; }
	char pop() { return stack[top--]; }
	int isEmpty() { return top == -1; }
	int isFull() { return top == 99; }
	char getTop() { return stack[top]; }
};


class stackInt {
private:
	double stack[100];
	int top;

public:
	stackInt() { top = -1; }
	void push(double val) { stack[++top] = val; }
	double pop() { return stack[top--]; }
	int isEmpty() { return top == -1; }
	int isFull() { return top == 99; }
};


class mainCalculator {
private:
	char buffer[100];
	char postfix[100];

	stackInt stackOne;
	stackChar stackTwo;

	void infixTopostfix();
	int result();
	int priority(char);

public:
	double calculate(char[]);
};