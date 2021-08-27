//제로 10773번
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 500000 // 스택의 최대 크기

typedef int element; //데이터의 자료형
element stack[MAX_STACK_SIZE]; // 1차원 배열로 스택을 만듦
int top = -1;

//삽입함수
void push(element item) {
	stack[++top] = item;
}

//삭제함수
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
	printf("%d", Sum); // 합계 출력
}