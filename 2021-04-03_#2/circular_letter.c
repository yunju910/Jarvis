// ȸ��
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
	char word [30];
	int len;
	bool identify = true;

	printf("�ܾ �Է��ϼ��� :"); 
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len / 2; i++) {  // ��ġ�� ������ ������ ó���� ���� �ϳ��� ���Ѵ�. 
		if (word[i] != word[len - 1 - i]) {
			identify = false;  // bool���� �̿��Ͽ� �ϳ��� ���� �ʴٸ� false�� ���� �����Ų��. 
			printf("ȸ���� �ƴմϴ�.");
			break;
		}
	}
	if (identify == true) {  // true��� ȸ���� �ȴ�. 
		printf("ȸ���Դϴ�.");
	}
	return 0;
	
}