/*
 * 10472번 십자뒤집기
 * https://www.acmicpc.net/problem/10472
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int P; char arr[5][5];
int dir[5][2] = { { 0, 0 }, { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int result;

bool isFinshed()
{
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (arr[i][j] == '*') return false;
	return true;
}

void toggle(int x, int y)
{
	for (int i = 0; i < 5; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) {
			if (arr[xx][yy] == '.') arr[xx][yy] = '*';
			else arr[xx][yy] = '.';
		}
	}
}

void find(int x, int y, int m, int cnt)
{
	if (m == 1) toggle(x, y);

	if (isFinshed()) {
		result = MIN(result, cnt);
		toggle(x, y);
		return;
	}
	
	if (!(x == 2 && y == 2)) {
		if (y == 2) for (int i = 0; i < 2; i++) find(x + 1, 0, i, cnt + i);
		else for (int i = 0; i < 2; i++) find(x, y + 1, i, cnt + i);
	}

	if (m == 1) toggle(x, y);
}

int main()
{
	scanf("%d", &P);
	while (P--) {
		result = 9999;
		for (int i = 0; i < 3; i++) scanf("%s", arr[i]);
		for (int i = 0; i < 2; i++) find(0, 0, i, i);
		printf("%d\n", result);
	}
	return 0;
}