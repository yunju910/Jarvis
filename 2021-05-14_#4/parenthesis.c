//��ȣ 9012�� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100 // ������ �ִ� ũ��

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

//���� �ʱ�
void init_stack(StackType* s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ȣ �˻� �Լ�
int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
			push(&s, ch);
			break;
		case ')':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}

int main(void) {
	int num = 0;
	scanf("%d", &num); // �ݺ��� Ƚ�� �ޱ�
	char* p = malloc(sizeof(char) * 50);  // ���� �޸� Ȱ��
	for (int i = 0; i < num; i++) {
		scanf("%s", p); // ���� �ޱ�
		if (check_matching(p) == 1) { // p ��ȣ Ȯ���ϱ� ��ȯ���� 1�̶�� yes
			printf("YES\n");
		}
		else {
			printf("NO\n"); //�ƴ϶�� no
		}
	}
	free(p);  // �޸� ��ȯ
	return 0;
}