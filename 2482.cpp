/*
 * 2482번 색상환
 * https://www.acmicpc.net/problem/2482
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#define MOD 1000000003

int N, K;
int cache[2][1001][1001];

int find(int index, int count, int first)
{
	int result = 0;

	if (index == N && first == 1)
		return 0;

	if (count == 0)
		return 1;

	int &r = cache[first][index][count];
	if (r != -1)
		return r;


	for (int i = index + 2; i <= N - count + 1; i++)
		result = (result + find(i, count - 1, first)) % MOD;

	return r = (result % MOD);
}


int main()
{
	int result = 0;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			cache[1][i][j] = cache[0][i][j] = -1;

	if (N < 2 * K)
		printf("%d\n", 0);
	else if (N == 2 * K)
		printf("%d\n", 2);
	else
	{
		result = (result + find(1, K - 1, 1)) % MOD;
		for (int i = 2; i <= N - K + 1; i++)
			result = (result + find(i, K - 1, 0)) % MOD;

		printf("%d\n", result % MOD);
	}

	return 0;
}