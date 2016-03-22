/*
* 2169�� �κ� �����ϱ�
* https://www.acmicpc.net/problem/2169
* �з�: ���̳��� ���α׷���
*/

#include <stdio.h>
#include <memory.h>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int arr[1002][1002];
int tmp1[1002][1002];
int tmp2[1002][1002];
int result[1002][1002];
int N, M;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &arr[i][j]);

	result[1][1] = arr[1][1];

	// 1�� �ʱ�ȭ
	for (int i = 2; i <= M; i++)
		result[1][i] = result[1][i - 1] + arr[1][i];

	// 2 ~ N�� ���
	for (int i = 2; i <= N; i++)
	{
		// ����->������, ��->�Ʒ� �� �ִ밪
		tmp1[i][0] = result[i - 1][1];
		for (int j = 1; j <= M; j++)
			tmp1[i][j] = MAX(tmp1[i][j - 1], result[i - 1][j]) + arr[i][j];

		// ������->����, ��->�Ʒ� �� �ִ밪
		tmp2[i][M + 1] = result[i - 1][M];
		for (int j = M; j >= 1; j--)
			tmp2[i][j] = MAX(tmp2[i][j + 1], result[i - 1][j]) + arr[i][j];

		// ���� �ִ밪
		for (int j = 1; j <= M; j++)
			result[i][j] = MAX(tmp1[i][j], tmp2[i][j]);
	}

	printf("%d\n", result[N][M]);

	return 0;
}