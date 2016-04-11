/*
 * 1326¹ø ÆúÂ¦ÆúÂ¦
 * https://www.acmicpc.net/problem/1326
 * 
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <queue>
#define M 10001

int N;
int arr[M][2];
int visit[M];
int a, b;
std::queue<int> q;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i][0]);
	scanf("%d %d", &a, &b);

	q.push(a);
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		if (index == b) {
			printf("%d", arr[b][1]);
			return 0;
		}
		visit[index] = 1;
		for (int i = 1;; i++) {
			int nextIndex = index + i * arr[index][0];
			if (nextIndex <= N && visit[nextIndex] != 1) {
				if (arr[nextIndex][1] == 0 || arr[nextIndex][1] > arr[index][1] + 1) {
					q.push(nextIndex);
					visit[nextIndex] = 1;
					arr[nextIndex][1] = arr[index][1] + 1;
				}
			}
			if (nextIndex > N) break;
		}
		for (int i = 1;; i++) {
			int nextIndex = index - i * arr[index][0];
			if (nextIndex >= 1 && visit[nextIndex] != 1) {
				if (arr[nextIndex][1] == 0 || arr[nextIndex][1] > arr[index][1] + 1) {
					q.push(nextIndex);
					visit[nextIndex] = 1;
					arr[nextIndex][1] = arr[index][1] + 1;
				}
			}
			if (nextIndex < 1) break;
		}
	}

	printf("%d",-1);
	return 0;
}