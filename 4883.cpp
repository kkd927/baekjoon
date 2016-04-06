/*
 * 4883번 삼각 그래프
 * https://www.acmicpc.net/problem/4883
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define INF 987654321

int K, T, tmp;
int arr[100000][5], result[100000][5];

int main()
{
	while (1) {
		// 입력
		scanf("%d", &K);
		if (K == 0) break;
		for (int i = 0; i < K; i++) scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);

		// 초기화
		arr[0][1] = INF; arr[0][3] += arr[0][2];
		for (int i = 0; i < K; i++) arr[i][0] = arr[i][4] = INF;
		
		// 계산
		for (int i = 1; i < K; i++) {
			for (int j = 1; j < 4; j++) {
				tmp	= MIN(arr[i][j - 1], arr[i - 1][j]);
				tmp = MIN(tmp, arr[i - 1][j - 1]);
				tmp = MIN(tmp, arr[i - 1][j + 1]);
				arr[i][j] += tmp;
			}
		}
		printf("%d. %d\n", ++T, arr[K - 1][2]);
	}
	return 0;
}