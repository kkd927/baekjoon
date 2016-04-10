/*
 * 1654번 랜선 자르기
 * https://www.acmicpc.net/problem/1654
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>

long long K, N;
long long arr[10010];
long long M, max, min;

long long isFinished()
{
	long long result = 0;
	for (int i = 0; i < K; i++) result += (arr[i] / M);
	return result;
}

int main()
{
	scanf("%lld %lld", &K, &N);
	for (int i = 0; i < K; i++) {
		scanf("%lld", &arr[i]);
		max = arr[i] > max ? arr[i] : max;
	}

	M = max;
	min = 0;

	long long ans = 0;
	while (min <= max) {
		M = (min + max) / 2;
		long long result = isFinished();
		if (result >= N) {
			if (ans < M) {
				ans = M;
			}
			min = M + 1;
		}
		else {
			max = M - 1;
		}
		
	}
	printf("%lld\n", ans);
	return 0;
}