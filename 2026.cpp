/*
* 2026¹ø ¼ÒÇ³
* https://www.acmicpc.net/problem/2026
*
* ID: kkd927
* Github: https://github.com/kkd927/baekjoon
*/

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int K, N, F;
bool arr[910][910];
int check[910];
vector<int> selected;
int res;

bool isFriend(int x)
{
	for (size_t i = 0; i < selected.size(); i++) {
		if (!arr[x][selected[i]]) return false;
	}
	return true;
}

int find(int x, int cnt)
{
	int flag = 0;
	selected.push_back(x);
	if (cnt == 1) {
		for (size_t i = 0; i < selected.size(); i++) printf("%d\n", selected[i]);
		selected.pop_back();
		return 1;
	}

	for (int i = x + 1; i <= N; i++) {
		if (arr[x][i] && check[i] >= K - 1 && isFriend(i)) {
			if (find(i, cnt - 1)) return 1;
		}
	}
	selected.pop_back();
	return flag;
}

int main()
{
	scanf("%d %d %d", &K, &N, &F);
	int a, b;
	for (int i = 1; i <= F; i++) {
		scanf("%d %d", &a, &b);
		arr[b][a] = arr[a][b] = true;
		check[a]++; check[b]++;
	}

	for (int i = 1; i <= N - K + 1; i++) {
		if (check[i] >= K - 1) {
			selected.clear();
			if (find(i, K)) return 0;
		}
	}
	if (!res) printf("%d\n", -1);
	return 0;
}