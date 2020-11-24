#include "stack.h"

int mainCalculator::priority(char ch)
{
	if		(ch == '*' || ch == '/') return 3;
	else if (ch == '+' || ch == '-') return 2;
	else							 return 1;
}

double mainCalculator::calculate(char infix[])
{
	for (int i = 0; i < 100; i++)
	{
		buffer[i] = infix[i];
		infixToPostfix();
		return result();
	}
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
			{
				postfix[j++] = buffer[i++];
			}
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

double mainCalculator::result()
{
	int i = 0, k;
	char token[10];
	double num, number, numOne, numTwo, numThree;
	char ch;

	while (postfix[i] != NULL)
	{
		if (isdigit(postfix[i]))
		{
			k = 0;
			while (isdigit(postfix[i])) token[k++] = postfix[i++];

			token[k] = NULL;

			num = atof(token);

			stackOne.push(num);
		}
		else if (postfix[i] == ' ') i++;
		else
		{
			ch = postfix[i++];
			numOne = stackOne.pop();
			numTwo = stackOne.pop();

			if (ch == '+') 
			{
				number = numTwo + numOne;
				if (numOne < 10)
				{
					numOne /= 10;
				}
			}

			else if (ch == '-') number = numTwo - numOne;
			else if (ch == '*') number = numTwo * numOne;
			else if (ch == '/') number = numTwo / numOne;
			else if (ch == '/' && numOne == 0) number = 0;

			stackOne.push(number);
		}
		i++;
	}
	numThree = stackOne.pop();
	return numThree;
}