//C언어로 쉽게 풀어쓴 자료구조 

#include <stdio.h>
#include <stdlib.h>

typedef struct { // 넣을 정보는 이름, 나이, 키 구조체로 저장
    char* Name;
    int Age;
    double Height;
}information;

typedef struct ListNode {  
    information data;
    struct ListNode* link;
} ListNode;

ListNode* insert(ListNode* head, information value) { // 노드의 첫 번째에 삽입하는 함수
    ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // 새로운 노드 생성
    p->data = value;   // 넣은 값을 저장
    p->link = head;    // 현재의 헤드값 저장
    head = p;    // 헤드 포인터 변경
    return head;   // 현재 헤드 반환
}

void print_list(ListNode* head) {    // 노드의 데이터 출력
    for (ListNode* p = head; p != NULL; p = p->link) {  //Null이 나올 때 즉 끝날 때까지 출력
        printf("Name: %s Age: %d Height: %.1f\n", p->data.Name, p->data.Age, p->data.Height);  // 이름, 나이, 키 출력
    }
}
