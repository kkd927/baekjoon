#include <stdio.h>
#include <string.h>
#include <math.h>

char str[100];
char arr[100][100];
int R, C, N;

int findR(int n)
{
	for (int i = (int)sqrt((double)n); i >= 1; i--)
	{
		if (n % i == 0)
			return i;
	}
}

int main()
{
	while (scanf("%s", str) != EOF)
	{
		N = strlen(str);
		R = findR(N);
		C = N / R;

		int k = 0;
		for (int i = 0; i < C; i++)
			for (int j = 0; j < R; j++)
				arr[j][i] = str[k++];

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				printf("%c", arr[i][j]);

		printf("\n");

		memset(str, 0, sizeof(str));
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}