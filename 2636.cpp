/*
* 2636¹ø Ä¡Áî
* https://www.acmicpc.net/problem/2636
*
* ID: kkd927
* Github: https://github.com/kkd927/baekjoon
*/

#include <stdio.h>
#include <vector>

int N, M;
int arr[101][101];
int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
bool isFinished;
int result;
typedef struct sNode {
	int x;
	int y;
} node;
std::vector<node> C, D;

void findWhtie(int x, int y, int index, int bIndex)
{
	if (arr[x][y] == index) return;
	if (arr[x][y] == bIndex) {
		isFinished = false;
		return;
	}

	arr[x][y] = index;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) findWhtie(nx, ny, index, bIndex);
	}
}

void findBlack(int x, int y, int index, int bIndex)
{
	int count = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (arr[nx][ny] == index) count++;
	}
	if (count >= 1) {
		node tmp;
		tmp.x = x; tmp.y = y;
		C.push_back(tmp);
	}
	arr[x][y] = bIndex + 1;
}

void removeBlack(int index)
{
	result++;
	D.clear();
	while (!C.empty()) {
		node tmp = C.back();
		arr[tmp.x][tmp.y] = index;
		D.push_back(tmp);
		C.pop_back();
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &arr[i][j]);

	int index = -1;
	int bIndex = 1;
	while (1) {
		isFinished = true;
		findWhtie(0, 0, index, bIndex);
		if (isFinished) {
			printf("%d\n", result);
			printf("%d\n", D.size());
			break;
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (arr[i][j] == bIndex) findBlack(i, j, index, bIndex);
		removeBlack(index);
		index--; bIndex++;
	}
	return 0;
}