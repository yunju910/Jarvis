// 회문
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
	char word [30];
	int len;
	bool identify = true;

	printf("단어를 입력하세요 :"); 
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len / 2; i++) {  // 위치를 반으로 나누어 처음과 끝을 하나씩 비교한다. 
		if (word[i] != word[len - 1 - i]) {
			identify = false;  // bool형을 이용하여 하나라도 맞지 않다면 false를 쓰고 종료시킨다. 
			printf("회문이 아닙니다.");
			break;
		}
	}
	if (identify == true) {  // true라면 회문이 된다. 
		printf("회문입니다.");
	}
	return 0;
	
}