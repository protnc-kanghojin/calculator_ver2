#include "stack.h"


int mainCalculator::priority(char ch) {
	if (ch == '*' || ch == '/')			return 3;
	else if (ch == '+' || ch == '-')	return 2;
	else								return 1;
}

double mainCalculator::calculate(char infix[]) { // 중위 표기법인 연산들을 buffer[i]에 넣어준다 ->buffer[i]에 저장된 수식을 계산한다.
	for (int i = 0; i < 80; i++)
		buffer[i] = infix[i];
	infixTopostfix();
	return result();
}

void mainCalculator::infixTopostfix() { //중위 표기법 -> 후위 표기법
	int i = 0, j = 0;
	char ch;

	while (buffer[i] != NULL) {
		if (buffer[i] == ' ') //공백이면 다음 버퍼로 넘어간다
			i++;
		else if (isdigit(buffer[i]) || buffer[i] == '.') { //buffer[i]의 값이 숫자면 postfix에 출력
			while (isdigit(buffer[i]) || buffer[i] == '.')
				postfix[j++] = buffer[i++];
			postfix[j++] = ' ';
		}

		else {
			if (s2.isEmpty())
				s2.push(buffer[i++]);
			else { //스택에 있는 자기보다 높거나 같은 연산자들을 모두 postfix에 출력하고 자신은 스택에 push 
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

	while (!s2.isEmpty()) { //수식이 끝나면 stack내용 pop
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
	//////////////////////// 소수점 문제 해결해야됨
	/////////////////////////////////////////////////
	while (postfix[i] != NULL) {

		if (isdigit(postfix[i])) {//postfix의 값이 숫자면 반환(true), 연산자 이면(false) 
			k = 0;
			while (isdigit(postfix[i]))
				token[k++] = postfix[i++];


			token[k] = NULL;
			num = atof(token); //문자열을 float형으로 변환

			s1.push(num);
		}
		else if (postfix[i] == ' ')
			i++;


		else { //연산자는 스택에서 두 수를 pop하여 연산하고 다시 push
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