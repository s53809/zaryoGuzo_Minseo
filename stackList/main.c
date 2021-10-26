#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int prior(char op); 
char* toPostFix(const char* exp);
int evaluate(const char* exp);

int main() {
	char expression[100];
	char* exp = NULL;
	printf("계산 수식을 입력해주세요. (ex: 3*4+5)\n>>");
	gets_s(expression, 100);
	exp = toPostFix(expression);
	printf("변환된 후위 수식 : [ %s ]\n", exp);
	int result = evaluate(exp);
	printf("%d\n", result);
	return 0;
}
int prior(char op) {
	switch (op) {
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	}
	return -1;
}

char* toPostFix(const char* exp) {
	makeFree();
	char symbol;
	int length = strlen(exp);
	int count = 0;
	char* postfix = (char*)malloc(sizeof(char) * length);
	for (int i = 0; i < length; i++) {
		displayStack();
		symbol = exp[i];
		if ('0' <= symbol && symbol <= '9') {
			postfix[count++] = symbol;
			continue;
		}
		if (symbol == '(') {
			push(symbol);
			continue;
		}
		if (symbol == ')') {
			while (1) {
				if (peek() == '(') {
					pop();
				}
				else {
					break;
				}
			}
			postfix[count++] = pop();
			while (1) {
				if (isEmpty()) {
					break;
				}
				if (peek() == '(') {
					pop();
				}
				else {
					break;
				}
			}
		}
		switch (symbol) {
		case '+': case '-': case '*': case '/':
			if (isEmpty() || peek() != '(') {
				while (!isEmpty() && (prior(symbol) <= prior(peek())))
					postfix[count++] = pop();
			}
			push(symbol);
			break;
		}
	}
	char item;
	while (!isEmpty()) {
		item = pop();
		if (item == '(') {
			continue;
		}
		postfix[count++] = item;
	}
	postfix[count] = '\0';
	return postfix;
}

int evaluate(const char* exp) {
	int op1, op2, value;
	int result = 0;
	int len = strlen(exp);
	char ch;
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		if ('0' <= ch && ch <= '9') {
			value = ch - '0';
			push(value);
		}
		else {
			op2 = pop();
			op1 = pop();
			switch (ch) {
			case '+':
				result = op1 + op2;
				push(result);
				break;
			case '-':
				result = op1 - op2;
				push(result);
				break;
			case '*':
				result = op1 * op2;
				push(result);
				break;
			case '/':
				result = op1 / op2;
				push(result);
				break;
			}
		}
	}
	return pop();

	
}