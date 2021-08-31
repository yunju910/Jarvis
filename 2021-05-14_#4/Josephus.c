// �似Ǫ�� ����0 11866��
// Segfault

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1001 // ���� ���ǿ��� N�� K�� 1000�����̹Ƿ� ũ�⸦ ������

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear; 
} QueueType;

void init_queue(QueueType *q){ 
    q->front = -1;
    q->rear = -1; 
}

void enqueue(QueueType *q, int item){ // item �����Լ�
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q){  // ���� �Լ�    
    int item = q->data[++(q->front)];
    return item;
}

void position(QueueType *q, int K){ // ���ڸ� ť���� K - 1 �� ��ŭ �ڷ� �����ϴ�. 
    for(int i = 0; i < K-1; i++){
        int item = dequeue(q);
        enqueue(q, item);
    }
}


int main(void){
    QueueType q; 
    init_queue(&q);
    QueueType result; 
    init_queue(&result);
    int N = 0;
    int K = 0;  
    scanf("%d", &N);
    scanf("%d", &K);
    
    for(int i = 1; i <= N; i++){  // ó���� ť�� 1���� N���� ���� ����
        enqueue(&q, i);
    }
    for(int i = 0; i < N; i++){  // position�Լ��� �־ ��ġ�� ������ �� ���� ������. 
        position(&q, K);
        enqueue(&result, dequeue(&q));
    }
    for(int i = 0; i < N; i++){  // ����� ����Ʈ 
        printf("%d ", dequeue(&result));
    }   
    return 0;
}