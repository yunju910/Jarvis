// ����� �Ѱ��� 4344��
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int C, N; // C�� �׽�Ʈ���̽��� ����, N�� �л��� �� 
	int Sum = 0; // ������ �հ�
	float Ave, percent; 
	int people = 0;
	scanf("%d", &C);
	for (int k = 0; k < C; k++)
	{
		scanf("%d", &N);
		int* score = malloc(sizeof(int) * N); // ���� �޸� �Ҵ�
		for (int j = 0; j < N; j++) {
			scanf("%d", &score[j]);
			Sum = Sum + score[j];
		}
		Ave = (float)Sum / N;
		for (int i = 0; i < N; i++) { // ��� �̻��� ��� ���ϱ� 
			if (score[i] > Ave)  
			{
				people = people + 1;
			}
		}
		percent = (float)people / N * 100; // �ۼ�Ʈ ���ϱ� 
		printf("%.3f%% \n", percent);
		people = 0;
		Sum = 0;
		free(score);
	}
}