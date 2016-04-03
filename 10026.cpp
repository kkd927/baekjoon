/*
 * 10026번 적록색약
 * https://www.acmicpc.net/problem/10026
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <memory.h>
#define MAX 110

int N;
char arr[MAX][MAX];
char tmp[MAX][MAX];
int result1, result2;
int dir[4][2] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };

void find1(int x, int y, char c)
{
	// 방문표시
	tmp[x][y] = 'A';

	// 4방향 탐색
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];

		if (0 <= xx && xx < N && 0 <= yy && yy < N && c == tmp[xx][yy]) {
			find1(xx, yy, c);
		}
	}
}

void find2(int x, int y, char c)
{
	// 방문표시
	tmp[x][y] = 'A';

	// 4방향 탐색
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];

		if (0 <= xx && xx < N && 0 <= yy && yy < N && ((tmp[xx][yy] == 'R' && c == 'G') || (tmp[xx][yy] == 'G' && c == 'R') || c == tmp[xx][yy])) {
			find2(xx, yy, c);
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	// 비색맹 탐색
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp[i][j] != 'A') {
				find1(i, j, tmp[i][j]);
				result1++;
			}
		}
	}

	// 색맹 탐색
	memcpy(tmp, arr, sizeof(arr));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp[i][j] != 'A') {
				find2(i, j, tmp[i][j]);
				result2++;
			}
		}
	}

	printf("%d %d\n", result1, result2);

	return 0;
}