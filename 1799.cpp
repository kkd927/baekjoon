/*
* 1799번 비숍
* https://www.acmicpc.net/problem/1799
*/

#include <stdio.h>

int N;
int arr[10][10];
int dir[4][2] = { { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
int result;

// 비숍의 대각선 확인
bool check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		while (x >= 0 && y >= 0 && x < N && y < N)
		{
			if (arr[x][y] == -1)
				return false;

			x += dir[i][0];
			y += dir[i][1];
		}
	}

	return true;
}

void find(int x, int y, int tmp)
{
	int flag = true;

	// 마지막 대각선 까지 도달
	if (y == N)
	{
		result = tmp > result ? tmp : result;
		return;
	}

	int a = x;
	int b = y;

	// 대각선 탐색
	while (a >= 0 && b < N)
	{
		if (arr[a][b] == 1 && check(a, b))
		{
			flag = false;
			arr[a][b] = -1;

			if (x < N - 1)
				find(x + 1, 0, tmp + 1);
			else
				find(N - 1, y + 1, tmp + 1);

			arr[a][b] = 1;
		}

		a -= 1;
		b += 1;
	}

	// 한 대각선에 놔둘자리가 없는 경우
	if (flag)
	{
		if (x < N - 1)
			find(x + 1, 0, tmp);
		else
			find(N - 1, y + 1, tmp);
	}
}

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		result = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &arr[i][j]);

		find(0, 0, 0);

		printf("%d\n", result);
	}

	return 0;
}