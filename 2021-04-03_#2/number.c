// ������ ���� 2577��
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARININGS

int main(void) {
	int A, B, C;
	int size = 0;
	int Product;
	scanf_s("%d\n", &A);
	scanf_s("%d\n", &B);
	scanf_s("%d", &C);
	Product = A * B * C;
	while (Product != 0) { // �� �� �ڸ��� ���� ���ϱ� ����
		Product = Product / (int)10;
		size = size + 1;
	}
	Product = A * B * C;
	int* num = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		num[i] = (Product % 10); // ���� ������ �ڸ� ����
		Product = Product / 10;  // �� �������� �̵�
	}
	int n0 = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;
    // �迭�� �̿��ߴٸ� �� �ܼ�ȭ�� �� �־��� �� ����. 
	for (int i = 0; i < size; i++) {
		switch (num[i]) {
		case 0:
			n0 = n0 + 1;
			break;
		case 1:
			n1 = n1 + 1;
			break;
		case 2:
			n2 = n2 + 1;
			break;
		case 3:
			n3 = n3 + 1;
			break;
		case 4:
			n4 = n4 + 1;
			break;
		case 5:
			n5 = n5 + 1;
			break;
		case 6:
			n6 = n6 + 1;
			break;
		case 7:
			n7 = n7 + 1;
			break;
		case 8:
			n8 = n8 + 1;
			break;
		case 9:
			n9 = n9 + 1;
			break;
		}
	}
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", n0, n1, n2, n3, n4, n5, n6, n7, n8, n9);
}