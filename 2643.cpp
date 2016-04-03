/*
 * 2643번 색종이 올려 놓기
 * https://www.acmicpc.net/problem/2643
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <algorithm>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define M 110

int N;
int arr[M][3];
int result;

int find(int x)
{
	int &ret = arr[x][2];
	if (ret != -1)
		return ret;

	int tmp = 1;

	for (int i = x + 1; i < N; i++) {
		if ((arr[x][0] >= arr[i][0] && arr[x][1] >= arr[i][1]) || (arr[x][1] >= arr[i][0] && arr[x][0] >= arr[i][1])) {
			int r = find(i);
			tmp = (r >= tmp) ? r + 1 : tmp;
		}
	}
	return ret = tmp;
}

void quick(int start, int end, int (*arr)[3])
{
	int m = (start + end) / 2;
	int p = arr[m][0] * arr[m][1];
	int s = start;
	int e = end;

	while (s <= e) {
		while (arr[s][0] * arr[s][1] > p && s <= e) s++;
		while (p > arr[e][0] * arr[e][1] && s <= e) e--;

		if (s <= e) {
			for (int i = 0; i < 2; i++) {
				int tmp = arr[s][i];
				arr[s][i] = arr[e][i];
				arr[e][i] = tmp;
			}
			s++; e--;
		}
	}

	if (start < e) quick(start, e, arr);
	if (s < end) quick(s, end, arr);
}

int main()
{
	for (int i = 0; i < M; i++)
		arr[i][2] = -1;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	quick(0, N - 1, arr);

	for (int i = 0; i < N; i++) {
		result = MAX(result, find(i));
	}

	printf("%d\n", result);
	return 0;
}