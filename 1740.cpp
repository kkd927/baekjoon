/*
* 1740¹ø °ÅµìÁ¦°ö
* https://www.acmicpc.net/problem/1740
* ºÐ·ù: ¼öÇÐ
*
* ID: kkd927
* Github: https://github.com/kkd927/baekjoon
*/

#include <stdio.h>

long long N;
long long result = 0;

int main()
{
	scanf("%lld", &N);
	
	for (long long k = 1; N != 0; k *= 3, N >>= 1)
		result += (N & 1) * k;

	printf("%lld\n", result);

	return 0;
}