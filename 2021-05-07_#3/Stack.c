// ���� 10828��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10000 // ������ �ִ� ũ��

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int capacity; 
	int top;
}StackType;	

//���� �ʱ�
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 0; 
}

//���� ���� ���� �Լ�
int empty(StackType* s) {
	if (s->top == -1) {
		return 1; 
	}
	else {
		return 0;
	}
}

// ���� �Լ�
void push(StackType* s, element X) {
	s->capacity += 1;
	s->data[++(s->top)] = X;
}

//���� �Լ�
element pop(StackType* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		s->capacity -= 1;
		return s->data[(s->top)--];
	}
}
// ũ�⸦ �� �� �ִ� �Լ�
element size(StackType* s) {
	return s->capacity;
}

// ������ ���� ���� �ִ� ���� Ȯ���ϴ� �Լ� 
element top(StackType* s) {
	if (empty(s) == 1) {
		return -1;
	}
	else {
		return s->data[(s->top)];
	}
}

int main(void) {
	StackType s;
	init_stack(&s);
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		char* str;                       // �����ϰ� ���� �Լ� ���ڿ��� �ޱ� ����. 
		str = malloc(sizeof(char) * 20);
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {  // strcmp�� �̿��� ���ڿ� �񱳸� ���ؼ� ������ ����� �޾Ƶ��̵��� ����
			int X; 
			scanf("%d", &X);
			push(&s, X);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop(&s));
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty(&s));
		}
		else if (strcmp(str, "top") == 0) {
			printf("%d\n", top(&s));
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", size(&s));
        }
    }
    return 0;
}   