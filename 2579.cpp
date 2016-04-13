/*
 * 2579번 계단 오르기
 * https://www.acmicpc.net/problem/2579
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <memory.h>
#include <algorithm>

int N;
int arr[310], cache[301][3];

int find(int x, int z)
{
	if (z == 3) return -987654321;
	if (x >= N) return arr[x];

	int &ret = cache[x][z];
	if (ret != -1) return ret;
	
	return ret = std::max(find(x + 1, z + 1), find(x + 2, 1)) + arr[x];
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	arr[N + 1] = -987654321;
	printf("%d\n", find(0, 0));
	return 0;
}