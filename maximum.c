// �ִ밪
#include <stdio.h>

int main(void) {
    
    int scores[9]; // �Է¹��� �迭
    
    for (int i = 0; i < 9; i++) {
        scanf("%d", &scores[i]);
    }
    
    int max = scores[0]; // �ʱ� �ִ��� ù ��° ������ ����
    for (int i = 0; i < 9; i++) { // �ִ� ã��
        if (scores[i] > max)
        {
            max = scores[i];
        }
    }
    printf("%d\n", max);
    

    for (int i = 0; i < 9; i++) { // �ִ��� ��ġ ã�� 
        if (scores[i] == max)
        {
            printf("%d", i + 1);
        }
    }
    return 0;
}