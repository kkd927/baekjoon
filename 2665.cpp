/*
* 2665번 미로만들기
* https://www.acmicpc.net/problem/2665
*
* ID: kkd927
* Github: https://github.com/kkd927/baekjoon
*/

#include <stdio.h>
#define M 55

int N;
char arr[M][M];
int cache[M][M];
int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

void find(int x, int y, int cnt)
{
	if (arr[x][y] == '0') cnt++;
	cache[x][y] = cnt;
	if (x == N - 1 && y == N - 1) return;

	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (x >= 0 && x < N && y >= 0 && y < N && cache[xx][yy] > cnt) {
			find(xx, yy, cnt);
		}
	}
}

int main()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			cache[i][j] = 9999;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i]);

	find(0, 0, 0);
	printf("%d\n", cache[N - 1][N - 1]);
	return 0;
}