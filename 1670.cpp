#include <stdio.h>

long long arr[5000];
int N;

int main()
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= 5000; i++)
	{
		for (int j = 2; j <= i * 2; j += 2)
		{
			arr[i] += (arr[(j - 2) / 2] * arr[(i * 2 - j) / 2]) % 987654321;
			arr[i] %= 987654321;
		}
	}

	while (scanf("%d", &N) != EOF)
	{
		printf("%lld\n", arr[N / 2]);
	}
	return 0;
}