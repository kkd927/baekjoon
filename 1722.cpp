/*
 * 1722번 순열의 순서
 * https://www.acmicpc.net/problem/1722
 * 분류: 순열
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <vector>

using namespace std;

int N, T;
long long K;
int arr[20];
vector<int> ord;
vector<int>::iterator iterPos;
long long result;

vector<int>::iterator indexOf(int a)
{
	for (iterPos = ord.begin(); iterPos != ord.end(); iterPos++)
	{
		if (*iterPos == a)
			return iterPos;
	}
}

long long fact(int a)
{
	long long result = 1;
	for (long long i = 1; i <= a; i++)
		result *= i;

	return result;
}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		ord.push_back(i);

	scanf("%d", &T);

	long long f = fact(N - 1);

	if (T == 1)
	{
		scanf("%lld", &K);
		long long z = K - 1;
		for (int i = 0, j = N - 1; i < N - 1; i++, j--)
		{
			arr[i] = z / f;
			z %= f;
			if (j != 0) f /= j;
		}

		for (int i = 0; i < N - 1; i++)
		{
			printf("%d ", ord[arr[i]]);
			indexOf(ord[arr[i]]);
			ord.erase(iterPos);
		}
		printf("%d", ord[0]);
		printf("\n");
	}
	else if (T == 2)
	{
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		for (int i = 0, j = N - 1; i < N; i++, j--)
		{
			indexOf(arr[i]);
			int d = distance(ord.begin(), iterPos);
			result += f * d;

			if (j != 0) f /= j;
			ord.erase(iterPos);
		}

		printf("%lld\n", result + 1);
	}

	return 0;
}