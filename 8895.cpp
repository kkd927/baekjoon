#include <stdio.h>
#include <memory.h>

int T, N, L, R;
long long cache[21][21][21];

long long find(int n, int l, int r)
{
	if (n == 0 || l == 0 || r == 0)
		return 0;

	if (n == 1 && l == 1 && r == 1)
		return 1;

	if (cache[n][l][r] != -1)
		return cache[n][l][r];

	return cache[n][l][r] = find(n - 1, l - 1, r) + find(n - 1, l, r - 1) + 1LL * find(n - 1, l, r) * (n - 2);
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		memset(cache, -1, sizeof(cache));
		scanf("%d %d %d", &N, &L, &R);
		printf("%lld\n", find(N, L, R));
	}

	return 0;
}