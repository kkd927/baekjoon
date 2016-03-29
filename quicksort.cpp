#include <stdio.h>

void quick(int start, int end, int arr[])
{
	int p = arr[(start + end) / 2];
	int s = start;
	int e = end;

	while (s <= e)
	{
		while (arr[s] < p && s <= e)s++;
		while (p < arr[e] && s <= e)e--;

		if (s <= e)
		{
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;

			s++; e--;
		}
	}

	if (start < e)quick(start, e, arr);
	if (s < end)quick(s, end, arr);
}

int main()
{
	int arr[10] = { 1, 4, 5, 3, 2, 8, 7, 6, 9, 10 };
	quick(0, 9, arr);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}