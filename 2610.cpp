/*
 * 2610번 회의준비
 * https://www.acmicpc.net/problem/2610
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define C 110
#define D 10000
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) > (Y)) ? (X) : (Y))


int N, M;
int arr[C][C];
int count[C];
bool visit[C], visitbfs[C];
std::vector<int> queue, bfs, time1;

// 결과 저장
int result[C];
int index1;

typedef struct sRet
{
	int count;
	int point;
} ret;

int findbfs(int org, int x)
{
	int ret = 0;
	while (bfs.size() != 0) {
		int z = bfs.front();
		int t = time1.front();
		bfs.erase(bfs.begin());
		time1.erase(time1.begin());
		if (visitbfs[z])
			continue;
		ret = MAX(ret, t);
		visitbfs[z] = visit[z] = true;
		if (x == org && z != org) {
			queue.push_back(z);
		}
		for (int i = 1; i < count[z]; i++){
			if (!visitbfs[arr[z][i]]) {
				bfs.push_back(arr[z][i]);
				time1.push_back(t + 1);
			}
		}
	}
	return ret;
}

int find(int x)
{
	ret a;
	a.count = 99999;
	a.point = x;

	bfs.clear();
	bfs.push_back(x);
	time1.clear();
	time1.push_back(1);
	memset(visitbfs, false, sizeof(visitbfs));
	int r = findbfs(x, x);
	if (a.count > r) {
		a.count = r;
		a.point = x;
	}

	while ((queue.size()) != 0) {
		int b = queue.back();
		queue.pop_back();
		bfs.clear();
		bfs.push_back(b);
		time1.clear();
		time1.push_back(1);
		memset(visitbfs, false, sizeof(visitbfs));
		int r = findbfs(x, b);
		if (a.count > r) {
			a.count = r;
			a.point = b;
		}
	}

	return a.point;
}

int main()
{
	scanf("%d %d", &N, &M);

	// 초기화
	for (int i = 1; i <= N; i++)
		count[i] = 1;

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][count[x]++] = y;
		arr[y][count[y]++] = x;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			result[index1++] = find(i);
		}
	}
	
	std::sort(result, result + index1);

	printf("%d\n", index1);
	for (int i = 0; i < index1; i++)
		printf("%d\n", result[i]);

	return 0;
}