//���� 10773��
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 500000 // ������ �ִ� ũ��

typedef int element; //�������� �ڷ���
element stack[MAX_STACK_SIZE]; // 1���� �迭�� ������ ����
int top = -1;

//�����Լ�
void push(element item) {
	stack[++top] = item;
}

//�����Լ�
void pop() {
	stack[top--] = 0;
}

int main(void) {

	int num = 0;
	int num1 = 0;
	int Sum = 0;
	scanf("%d", &num);
	 
	for (int i = 0; i < num; i++) {
		scanf("%d", &num1); 
		if (num1 == 0) { 
			pop();
		}
		else {
			push( num1); 
		}
	}
	for (int i = 0; i < top+1; i++) {
		Sum += stack[i]; 
	}
	printf("%d", Sum); // �հ� ���
}