/*
 * 11067번 모노톤길
 * https://www.acmicpc.net/problem/11067
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>

int T, N, M;
int arr[100000][2];
int tmp[100000][2];
int result[100000][2];
int index;

void quicksort(int start, int end)
{
	int p = arr[(start + end) / 2][0];
	int s = start;
	int e = end;

	while (s <= e)
	{
		while (arr[s][0] < p && s <= e) s++;
		while (p < arr[e][0] && s <= e) e--;

		if (s <= e)
		{
			int tmp1 = arr[s][0];
			int tmp2 = arr[s][1];
			arr[s][0] = arr[e][0];
			arr[s][1] = arr[e][1];
			arr[e][0] = tmp1;
			arr[e][1] = tmp2;

			s++; e--;
		}
	}

	if (start < e) quicksort(start, e);
	if (s < end) quicksort(s, end);
}

void quick(int start, int end)
{
	int p = tmp[(start + end) / 2][1];
	int s = start;
	int e = end;

	while (s <= e)
	{
		while (tmp[s][1] < p && s <= e) s++;
		while (p < tmp[e][1] && s <= e) e--;

		if (s <= e)
		{
			int tmp1 = tmp[s][0];
			int tmp2 = tmp[s][1];
			tmp[s][0] = tmp[e][0];
			tmp[s][1] = tmp[e][1];
			tmp[e][0] = tmp1;
			tmp[e][1] = tmp2;

			s++; e--;
		}
	}

	if (start < e) quick(start, e);
	if (s < end) quick(s, end);
}

void find(int x, int y)
{
	// 같은 줄 벡터에 삽입
	int j = 0;
	for (int i = index; i < N; i++)
	{
		if (arr[i][0] != x)
			break;
		tmp[j][0] = arr[i][0];
		tmp[j++][1] = arr[i][1];
	}
	
	// 기준 점 부터 떨어진 길이로 정렬
	quick(0, j - 1);

	if (tmp[0][0] == x && tmp[0][1] == y)
	{
		for (int i = 0; i < j; i++)
		{
			result[index][0] = tmp[i][0];
			result[index++][1] = tmp[i][1];
		}
		if (index != N)
			find(arr[index][0], tmp[j - 1][1]);
	}
	else
	{
		for (int i = j - 1; i >= 0; i--)
		{
			result[index][0] = tmp[i][0];
			result[index++][1] = tmp[i][1];
		}
		if (index != N)
			find(arr[index][0], tmp[0][1]);
	}
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		index = 0;

		// N 입력
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d %d", &arr[i][0], &arr[i][1]);

		// x 좌표 기준으로 정렬
		quicksort(0, N - 1);

		// 시작점부터 출발
		find(0, 0);

		// M 입력
		scanf("%d", &M);
		int tmp;
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &tmp);
			printf("%d %d\n", result[tmp - 1][0], result[tmp - 1][1]);
		}
	}

	return 0;
}