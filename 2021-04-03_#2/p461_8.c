#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num[10];
	int Sum = 0;
	double V = 0;
	float v;
	for (int i = 0; i < 10; i++) {
		num[i] = rand();  // ���� ����
		printf("%d\n", num[i]);
		Sum = Sum + num[i]; // �հ�
	}
	float Average = Sum / 10.0; // ���
	printf("%f\n", Average); 
	for (int i = 0; i < 10; i++) { // �л�
		float v = pow((num[i] - Average), 2) / 10; 
		V = V + v;
	}
	float dev;
	dev = sqrt(V); // ǥ������
	printf("%f", dev);

}