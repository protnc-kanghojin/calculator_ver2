#include "stack.h"


int mainCalculator::priority(char ch) {
	if (ch == '*' || ch == '/')			return 3;
	else if (ch == '+' || ch == '-')	return 2;
	else								return 1;
}

double mainCalculator::calculate(char infix[]) { // ���� ǥ����� ������� buffer[i]�� �־��ش� ->buffer[i]�� ����� ������ ����Ѵ�.
	for (int i = 0; i < 80; i++)
		buffer[i] = infix[i];
	infixTopostfix();
	return result();
}

void mainCalculator::infixTopostfix() { //���� ǥ��� -> ���� ǥ���
	int i = 0, j = 0;
	char ch;

	while (buffer[i] != NULL) {
		if (buffer[i] == ' ') //�����̸� ���� ���۷� �Ѿ��
			i++;
		else if (isdigit(buffer[i]) || buffer[i] == '.') { //buffer[i]�� ���� ���ڸ� postfix�� ���
			while (isdigit(buffer[i]) || buffer[i] == '.')
				postfix[j++] = buffer[i++];
			postfix[j++] = ' ';
		}

		else {
			if (s2.isEmpty())
				s2.push(buffer[i++]);
			else { //���ÿ� �ִ� �ڱ⺸�� ���ų� ���� �����ڵ��� ��� postfix�� ����ϰ� �ڽ��� ���ÿ� push 
				while (!s2.isEmpty() && priority(s2.getTop()) >= priority(buffer[i])) {
					ch = s2.pop();
					postfix[j++] = ch;
					postfix[j++] = ' ';
				}
				s2.push(buffer[i]);
				i++;
			}
		}
	}

	while (!s2.isEmpty()) { //������ ������ stack���� pop
		ch = s2.pop();
		postfix[j++] = ch;
		postfix[j++] = ' ';
	}
	postfix[j] = NULL;

}

double mainCalculator::result() {
	int i = 0, k;
	char token[10];
	double num, number, num1, num2;
	double num3;
	char ch;
	//////////////////////// �Ҽ��� ���� �ذ��ؾߵ�
	/////////////////////////////////////////////////
	while (postfix[i] != NULL) {

		if (isdigit(postfix[i])) {//postfix�� ���� ���ڸ� ��ȯ(true), ������ �̸�(false) 
			k = 0;
			while (isdigit(postfix[i]))
				token[k++] = postfix[i++];


			token[k] = NULL;
			num = atof(token); //���ڿ��� float������ ��ȯ

			s1.push(num);
		}
		else if (postfix[i] == ' ')
			i++;


		else { //�����ڴ� ���ÿ��� �� ���� pop�Ͽ� �����ϰ� �ٽ� push
			ch = postfix[i++];
			num1 = s1.pop();


			num2 = s1.pop();


			if (ch == '+') {
				number = num2 + num1;
				if (num1 < 10) {
					num1 /= 10;
				}
			}
			else if (ch == '-') number = num2 - num1;
			else if (ch == '*') number = num2 * num1;
			else if (ch == '/') number = num2 / num1;
			else if (ch == '/' && num1 == 0) number = 0;


			s1.push(number);
		}
		i++;
	}
	num3 = s1.pop();
	return num3;
}