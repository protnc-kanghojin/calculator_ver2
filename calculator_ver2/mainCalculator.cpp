#include "mainCalculator.h"

int mainCalculator::priority(char ch)
{
	if (ch == '*' || ch == '/')			return 3;
	else if (ch == '+' || ch == '-')	return 2;
	else									return 1;
}


int mainCalculator::calculate(char infix[])
{
	for (int i = 0; i < 100; i++) 
	{
		buffer[i] = infix[i];
	}

	infixToPostfix();

	return result();
}


void mainCalculator::infixToPostfix()
{
	int i = 0, j = 0;
	char ch;

	while (buffer[i] != NULL) 
	{
		if (buffer[i] == ' ') i++;
		else if (isdigit(buffer[i]) || buffer[i] == '.')
		{
			while (isdigit(buffer[i]) || buffer[i] == '.')
				postfix[j++] = buffer[i++];
			postfix[j++] = ' ';
		}

		else
		{
			if (stackTwo.isEmpty()) stackTwo.push(buffer[i++]);
			else 
			{
				while (!stackTwo.isEmpty() && priority(stackTwo.getTop()) >= priority(buffer[i])) 
				{
					ch = stackTwo.pop();
					postfix[j++] = ch;
					postfix[j++] = ' ';
				}
				stackTwo.push(buffer[i]);
				i++;
			}
		}
	}

	while (!stackTwo.isEmpty())
	{
		ch = stackTwo.pop();
		postfix[j++] = ch;
		postfix[j++] = ' ';
	}

	postfix[j] = NULL;
}


int mainCalculator::result() 
{
	int i = 0, k;
	char token[10];
	int num, number, num1, num2, num3;
	char ch;

	while (postfix[i] != NULL) 
	{

		if (isdigit(postfix[i]))
		{
			k = 0;
			while (isdigit(postfix[i]))
				token[k++] = postfix[i++];
			token[k] = NULL;
			num = atof(token);
			stackOne.push(num);
		}

		else if (postfix[i] == ' ') i++;
		else
		{
			ch = postfix[i++];
			num1 = stackOne.pop();
			num2 = stackOne.pop();
			if (ch == '+')
			{
				number = num2 + num1;
				if (num1 < 10) num1 /= 10;
			}
			else if (ch == '-') number = num2 - num1;
			else if (ch == '*') number = num2 * num1;
			else if (ch == '/' && num1 == 0) number = 0; // Divide 0 is error... so show 0
			else if (ch == '/') number = num2 / num1;
			stackOne.push(number);
		}
		i++;
	}
	num3 = stackOne.pop();
	return num3;
}