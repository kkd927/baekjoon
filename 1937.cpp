#include <stdio.h>
#include <memory.h>

int n;
int arr[500][500];
int check[500][500];
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
int result;

int find(int i, int j)
{
	int rs = 0;


	for (int a = 0; a < 4; a++)
	{
		int x = i + dir[a][0];
		int y = j + dir[a][1];

		if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] > arr[i][j]) {
			if (check[x][y] == 0)
				check[x][y] = find(x, y);
			rs = check[x][y] > rs ? check[x][y] : rs;
		}
	}

	return rs + 1;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(check, 0, 2500);
		result = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = find(i, j);
				result = check[i][j] > result ? check[i][j] : result;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}