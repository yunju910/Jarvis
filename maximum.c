// 최대값
#include <stdio.h>

int main(void) {
    
    int scores[9]; // 입력받을 배열
    
    for (int i = 0; i < 9; i++) {
        scanf("%d", &scores[i]);
    }
    
    int max = scores[0]; // 초기 최댓값을 첫 번째 값으로 지정
    for (int i = 0; i < 9; i++) { // 최댓값 찾기
        if (scores[i] > max)
        {
            max = scores[i];
        }
    }
    printf("%d\n", max);
    

    for (int i = 0; i < 9; i++) { // 최댓값의 위치 찾기 
        if (scores[i] == max)
        {
            printf("%d", i + 1);
        }
    }
    return 0;
}