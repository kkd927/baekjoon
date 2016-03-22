/*
 * 1788번 피보나치 수의 확장
 * https://www.acmicpc.net/problem/1788
 */

#include <stdio.h>
#define MOD 1000000000
#define ABS(X) ((X) > 0 ? (X) : (X) * -1)

int arrp[1000001];
int n;

void c(int tmp)
{
	if (tmp > 0) printf("%d\n", 1);
	else if (tmp = 0) printf("%d\n", 0);
	else printf("%d\n", -1);
}

int main()
{
	arrp[0] = 0;
	arrp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		arrp[i] = (arrp[i - 1] + arrp[i - 2]) % MOD;

	while (scanf("%d", &n) != EOF)
	{
		if (n > 0) printf("%d\n", 1);
		else if (n == 0) printf("%d\n", 0);
		else {
			if (n % 2 == 0) printf("%d\n", -1);
			else printf("%d\n", 1);
		}
		printf("%d\n", arrp[ABS(n)] % MOD);
	}

	return 0;
}