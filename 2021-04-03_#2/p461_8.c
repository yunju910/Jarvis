#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num[10];
	int Sum = 0;
	double V = 0;
	float v;
	for (int i = 0; i < 10; i++) {
		num[i] = rand();  // 난수 생성
		printf("%d\n", num[i]);
		Sum = Sum + num[i]; // 합계
	}
	float Average = Sum / 10.0; // 평균
	printf("%f\n", Average); 
	for (int i = 0; i < 10; i++) { // 분산
		float v = pow((num[i] - Average), 2) / 10; 
		V = V + v;
	}
	float dev;
	dev = sqrt(V); // 표준편차
	printf("%f", dev);

}