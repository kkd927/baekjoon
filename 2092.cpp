/* 
 * 2092�� ������ ����
 * https://www.acmicpc.net/problem/2092
 * �з�: ���̳��� ���α׷���
 * ����: ����
 */

#include <stdio.h>
#include <memory.h>

int T, A, S, B;
int arr[201];

int main()
{
	while (scanf("%d %d %d %d", &T, &A, &S, &B) != EOF)
	{
		memset(arr, 0, sizeof(arr));

		int tmp = 0;
		for (int i = 0; i < A; i++)
		{
			scanf("%d", &tmp);
			arr[tmp]++;
		}


	}

	return 0;
}