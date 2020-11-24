#pragma once
#include <iostream>
#include <ctype.h>  
#include <cstdlib> 
using namespace std;

//중위를 후위로 바꾸기 위한 연산
class CharStack {
private: //class 내부 접근
	double stack[100];
	int top;
public: // 내부/외부 접근 가능
	CharStack() { top = -1; }
	void push(char val) { stack[++top] = val; }  //stack에 val 값 넣기
	char pop() { return stack[top--]; }   //stack에 값 빼기
	int isEmpty() { return top == -1; }
	int isFull() { return top == 99; }
	char getTop() { return stack[top]; }
};

//intStack  -- postfix result 연산을 위한 stack
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

//calculator class 정의
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