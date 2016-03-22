/* 3095번 플러스의 개수
 * https://www.acmicpc.net/problem/3095
 * 분류: 행렬
 * 상태: 실패
 */

#include <stdio.h>

int N;
int arr[2000][2000];
int result;

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		// 행렬 입력
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &arr[i][j]);


	}

	return 0;
}