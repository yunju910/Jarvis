// 요세푸스 문제0 11866번
// Segfault

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1001 // 문제 조건에서 N과 K는 1000이하이므로 크기를 선언함

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear; 
} QueueType;

void init_queue(QueueType *q){ 
    q->front = -1;
    q->rear = -1; 
}

void enqueue(QueueType *q, int item){ // item 삽입함수
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q){  // 삭제 함수    
    int item = q->data[++(q->front)];
    return item;
}

void position(QueueType *q, int K){ // 숫자를 큐에서 K - 1 개 만큼 뒤로 보냅니다. 
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
    
    for(int i = 1; i <= N; i++){  // 처음에 큐에 1부터 N까지 숫자 저장
        enqueue(&q, i);
    }
    for(int i = 0; i < N; i++){  // position함수에 넣어서 위치를 조정한 후 값을 꺼내옴. 
        position(&q, K);
        enqueue(&result, dequeue(&q));
    }
    for(int i = 0; i < N; i++){  // 결과를 프린트 
        printf("%d ", dequeue(&result));
    }   
    return 0;
}