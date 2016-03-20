#include <stdio.h>
#include <memory.h>

#define MOD 1000000007
int N, L, R;
int cache[101][101][101];


int find(int n, int l, int r)
{
	if (n == 0 || l == 0 || r == 0)
		return 0;

	if (n == 1 && l == 1 && r == 1)
		return 1;

	if (cache[n][l][r] != -1)
		return cache[n][l][r];

	return cache[n][l][r] = (find(n - 1, l - 1, r) + find(n - 1, l, r - 1) + 1LL * find(n - 1, l, r) * (n - 2)) % MOD;
}

int main()
{
	while (scanf("%d %d %d", &N, &L, &R) != EOF)
	{
		memset(cache, -1, sizeof(cache));
		printf("%d\n", find(N, L, R));
	}

	return 0;
}