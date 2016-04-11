/*
 * 1991번 트리 순회
 * https://www.acmicpc.net/problem/1991
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>

int N;
char arr[26][3];

void preorder(char a)
{
	for (int i = 0; i < N; i++) {
		if (arr[i][0] == a) {
			printf("%c", a);
			if (arr[i][1] != '.') preorder(arr[i][1]);
			if (arr[i][2] != '.') preorder(arr[i][2]);
		}
	}
}

void midorder(char a)
{
	for (int i = 0; i < N; i++) {
		if (arr[i][0] == a) {
			if (arr[i][1] != '.') midorder(arr[i][1]);
			printf("%c", a);
			if (arr[i][2] != '.') midorder(arr[i][2]);
		}
	}
}

void afterorder(char a)
{
	{
		for (int i = 0; i < N; i++) {
			if (arr[i][0] == a) {
				if (arr[i][1] != '.') afterorder(arr[i][1]);
				if (arr[i][2] != '.') afterorder(arr[i][2]);
				printf("%c", a);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf(" %c %c %c", &arr[i][0], &arr[i][1], &arr[i][2]);
	
	preorder('A');
	printf("\n");

	midorder('A');
	printf("\n");

	afterorder('A');
	printf("\n");

	return 0;
}