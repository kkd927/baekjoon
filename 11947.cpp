#include <stdio.h>

int T;
long long N;

long long getL(long long arg)
{
	long long i = 0;
	while (arg != 0)
	{
		arg /= 10;
		i++;
	}

	return i;
}

long long getR(long long arg, long long l)
{
	long long tmp = 0;
	for (int i = 0; i < l; i++) {
		tmp *= 10;
		tmp += 9;
	}
	return (tmp - arg) * arg;
}

long long pow10(long long arg)
{
	long long tmp = 1;
	for (int i = 0; i < arg; i++)
		tmp *= 10;

	return tmp;
}

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%lld", &N);
		long long a = getL(N);
		long long b = pow10(a - 1);
		long long mid = b * 10 / 2;
		if (N >= mid)
			printf("%lld\n", getR(mid, a));
		else
			printf("%lld\n", getR(N, a));
	}
}