// AC 5430��
// ������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element; // int���� ����ü ����� ���ڸ� ���� �迭 data, front, rear�� ���� ��ġ, capacity�� �迭 ũ��� ����� �ݴϴ�. 
typedef struct {
    int front;
    int rear;
    int capacity;
    element* data;
} DequeType;

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(DequeType* q) {  // ť�� �ʱ�ȭ �ϴ� �Լ� 
    q->rear = q->rear = 0;
    q->capacity = 1;
    q->data = (element*)malloc(q->capacity * sizeof(element));
}

int full(DequeType* q) {  // ť ��ȭ ���� 
    return (q->front == q->rear);
}

int empty(DequeType* q) {
    return ((q->rear + 1) % q->capacity == q->front);
}

void add_rear(DequeType* q, element item) {
    if (full(q))
        error("ť�� ��ȭ�����Դϴ�.");
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
}

element delete_front(DequeType* q) {
    if (empty(q))
        error("ť�� ��������Դϴ�.");
    return q->data[(q->front + 1) % q->capacity];
}

void add_front(DequeType* q, element val) {
    if (full(q))
        error("ť�� ��ȭ�����Դϴ�.");
    q->data[q->front] = val;
    q->front = (q->front - 1 + q->capacity) % q->capacity;

}

element delete_rear(DequeType* q) {
    int prev = q->rear;
    if (empty(q))
        error("ť�� ��������Դϴ�");
    q->rear = (q->rear - 1 + q->capacity) % q->capacity;
    return q->data[prev];
}

element get_rear(DequeType* q) {
    if (empty(q))
        error("ť�� ��������Դϴ�.");
    return q->data[q->rear];
}

void R(DequeType* q) {
    DequeType position;
    init_queue(&position);

    for (int i = 0; i < (q->capacity); i++) {
        add_front(&position, delete_rear(q));
    }
    for (int i = 0; i < (q->capacity); i++) {
        add_front(q, delete_front(&position));
    }

}

void D(DequeType* q) {
    delete_front(q);
}

int main(void) {
    DequeType q;
    init_queue(&q);

    int T = 0;
    int X = 0;
    scanf_s("%d", &T);
    char* p = malloc(sizeof(char) * 100000);
    char* number = malloc(sizeof(char) * 100000);
    for (int i = 0; i < T; i++) {
        scanf_s("%s", &p);
        scanf_s("%d", &X);
        scanf_s("%s", &number);
        int len1 = strlen(number);
        int len2 = strlen(p);
        for (int j = 0; j < len1; j++) {
            add_front(&q, number[j]);
        }
        for (int k = 0; k < len2; k++) {
            char a = p[k];
            if (a == 'R') {
                R(&q);
            }
            else if (a == 'D') {
                D(&q);
            }
        }

        for (int l = 0; l < 2; l++) {
            printf("%c", delete_front(&q));
        }
    }
    free(p);
    free(number);
    free(q.data);
}
