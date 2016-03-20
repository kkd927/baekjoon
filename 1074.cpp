#include <stdio.h>

int N, r, c;
int arr[2][32768];

int main()
{
	while (scanf("%d %d %d", &N, &r, &c) != EOF)
	{
		arr[0][0] = 0;
		arr[0][1] = 1;
		arr[1][1] = 2;

		int x = 2;
		int y = 0;

		for (int i = 2; i < (2 << N - 1); i++) {
			if (i == x) {
				y = (i * i);
				arr[0][i] = y;
				arr[1][i] = arr[0][i] * 2;
				x *= 2;
			}
			else {
				arr[0][i] = arr[0][i - x / 2] + y;
				arr[1][i] = arr[0][i] * 2;
			}
		}

		printf("%d\n", arr[1][r] + arr[0][c]);
	}

	return 0;
}