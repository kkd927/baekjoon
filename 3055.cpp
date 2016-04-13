/*
 * 3055¹ø Å»Ãâ
 * https://www.acmicpc.net/problem/3055
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <queue>

const int INF = 987654321;
int R, C, result;
char arr[55][55];
int tmp[55][55];
int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
typedef struct sNode {
	int x;
	int y;
	int t;
} node;
std::queue<node> q;

void calcWater(int x, int y, int t)
{
	node current, next;
	next.x = x; next.y = y; next.t = t;
	q.push(next);
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.x + dir[i][0];
			int ny = current.y + dir[i][1];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] == '.' && tmp[nx][ny] > current.t + 1) {
				next.x = nx; next.y = ny; next.t = current.t + 1;
				q.push(next);
				tmp[next.x][next.y] = next.t;
			}
		}
	}
}

void find(int x, int y, int t)
{
	node current, next;
	next.x = x; next.y = y; next.t = t;
	q.push(next);
	while (!q.empty()) {
		current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.x + dir[i][0];
			int ny = current.y + dir[i][1];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && (arr[nx][ny] == 'D' || (arr[nx][ny] == '.' && current.t + 1 < tmp[nx][ny]))) {
				if (arr[nx][ny] == 'D') {
					result = current.t + 1;
					return;
				}
				next.x = nx; next.y = ny; next.t = current.t + 1;
				q.push(next);
				tmp[next.x][next.y] = 0;
			}
		}
	}
}

int main()
{
	result = -1;
	for (int i = 0; i < 55; i++) for (int j = 0; j < 55; j++) tmp[i][j] = INF;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", arr[i]);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '*') {
				calcWater(i, j, 0);
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'S') {
				find(i, j, 0);
				break;
			}
		}
	}

	if (result == -1) printf("KAKTUS");
	else printf("%d", result);
	return 0;
}