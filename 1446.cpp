/*
 * 1446번 지름길
 * https://www.acmicpc.net/problem/1446
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int arr[10001];
int road[10000][3];
int N, D;

int main()
{
	scanf("%d %d", &N, &D);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &road[i][0], &road[i][1], &road[i][2]);

	for (int i = 1; i <= D; i++)
	{
		arr[i] = arr[i - 1] + 1;
		for (int j = 0; j <= N; j++)
		{
			if (road[j][1] > D || road[j][1] - road[j][0] < road[j][2])
				continue;

			if (road[j][1] == i)
				arr[i] = MIN(arr[road[j][0]] + road[j][2], arr[i]);
		}
	}

	printf("%d\n", arr[D]);

	return 0;
}