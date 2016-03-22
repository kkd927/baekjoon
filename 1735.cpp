/*
 * 1735번 분수 합
 * https://www.acmicpc.net/problem/1735
 * 분류: 유클리드 호제법
 */

#include <stdio.h>

void swap(int* a, int* b)
{
	if (*a < *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int findMax(int a2, int b2)
{
	int result;
	swap(&a2, &b2);
	if (a2 - b2 == 0)
		return a2;
	if (a2 - b2 == 1)
		return 1;

	result = findMax(a2 - b2, b2);
	return result;
}

int main()
{
	int a1, a2;
	int b1, b2;
	int rs;

	scanf("%d %d", &a1, &a2);
	scanf("%d %d", &b1, &b2);

	rs = findMax(a1*b2 + a2*b1, a2*b2);
	printf("%d %d", (a1*b2 + a2*b1) / rs, a2*b2 / rs);
}