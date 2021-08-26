// 평균은 넘겠지 4344번
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int C, N; // C는 테스트케이스의 개수, N이 학생의 수 
	int Sum = 0; // 점수의 합계
	float Ave, percent; 
	int people = 0;
	scanf("%d", &C);
	for (int k = 0; k < C; k++)
	{
		scanf("%d", &N);
		int* score = malloc(sizeof(int) * N); // 동적 메모리 할당
		for (int j = 0; j < N; j++) {
			scanf("%d", &score[j]);
			Sum = Sum + score[j];
		}
		Ave = (float)Sum / N;
		for (int i = 0; i < N; i++) { // 평균 이상인 사람 구하기 
			if (score[i] > Ave)  
			{
				people = people + 1;
			}
		}
		percent = (float)people / N * 100; // 퍼센트 구하기 
		printf("%.3f%% \n", percent);
		people = 0;
		Sum = 0;
		free(score);
	}
}