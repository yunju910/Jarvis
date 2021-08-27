// ť2 18258��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element; // int���� ����ü ����� ���ڸ� ���� �迭 data, front, rear�� ���� ��ġ, capacity�� �迭 ũ��� ����� �ݴϴ�. 
typedef struct{
    int front;
    int rear; 
    int capacity;
    element *data;
} QueueType;


void init_queue(QueueType *q){  // ť�� �ʱ�ȭ �ϴ� �Լ� 
    q->rear = -1;   
    q->front = -1;
    q->capacity = 1;
    q->data = (element *)malloc(q->capacity *sizeof(element));
}

element full(QueueType *q){  // ť ��ȭ ���� 
    if (q->rear == q->capacity - 1){
        return 1;   
    }
    else {
        return 0;
    }
}

element empty(QueueType *q){
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

void push(QueueType *q, int X){
    if(full(q) == 1){
        q->capacity *= 2; 
        q->data = (element *)realloc(q->data, q->capacity * sizeof(element));
    }
    q->data[++(q->rear)] = X;
    
}

element pop(QueueType *q){
    if(empty(q) == 1){
        return -1; 
    }
    else{
        int item = q->data[++(q->front)];
        q->capacity -= 1;
        return item;
    }
    
}

element front(QueueType *q){
    if(empty(q) == 1){
        return -1; 
    }
    else{
        return  q->data[(q->front + 1)];
    }
}

element back(QueueType *q){
    if(empty(q) == 1){
        return -1; 
    }
    else{
        return q->data[(q->rear)];
    }
}

element size(QueueType *q){
    return ((q->rear) - (q->front));
}
    
int main (void){
    int item = 0;
    int num = 0; 
    scanf("%d", &num);
    QueueType q; 
    init_queue(&q);
    
    char *str = (char *)malloc(sizeof(char) * 20);
    for(int i = 0; i < num; i++){
        scanf("%s", str);
        if (strcmp(str, "push") == 0) {
			int X; 
			scanf("%d", &X);
			push(&q, X);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop(&q));
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty(&q));
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", front(&q));
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", back(&q));
        }
        else if (strcmp(str, "size") == 0) {
			printf("%d\n", size(&q));
        }
    }
    free(str);
    free(q.data);
    return 0; 
}