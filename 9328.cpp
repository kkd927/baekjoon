/*
* 9328번 열쇠
* https://www.acmicpc.net/problem/9328
* 분류: BFS
*
* ID: kkd927
* Github: https://github.com/kkd927/baekjoon
*/

#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

int T;
int h, w;
char arr1[200][200];
char arr2[200][200];
char tmp[10000];
vector<char> key;
int result;
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
bool flag = false;


bool hasKey(char a)
{
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i] == a + 'a' - 'A')
			return true;
	}
	return false;
}

void getKey()
{
	int i = 0;
	while (tmp[i] != '\0')
	{
		key.push_back(tmp[i++]);
	}
}

void find(int x, int y)
{
	// 문서 발견
	if (arr2[x][y] == '$')
	{
		arr1[x][y] = '.';
		result++;
	}

	// 키 발견
	if (arr2[x][y] >= 'a' && arr2[x][y] <= 'z')
	{
		arr1[x][y] = '.';
		key.push_back(arr2[x][y]);
		flag = true;
	}

	// 열쇠 가진 문 발견
	if (arr2[x][y] >= 'A' && arr2[x][y] <= 'Z')
		arr1[x][y] = '.';

	// 방문 표시
	arr2[x][y] = '@';

	for (int i = 0; i < 4; i++)
	{
		int a = x + dir[i][0];
		int b = y + dir[i][1];

		if (a >= 0 && a < h && b >= 0 && b < w && arr2[a][b] != '@' && arr2[a][b] != '*')
		{
			if ((arr2[a][b] >= 'A' && arr2[a][b] <= 'Z' && hasKey(arr2[a][b])) || arr2[a][b] == '.' || (arr2[a][b] >= 'a' && arr2[a][b] <= 'z') || arr2[a][b] == '$')
				find(a, b);
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		// 초기화
		result = 0;
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		memset(tmp, 0, sizeof(tmp));
		key.clear();

		// 평면도 입력
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++)
			scanf("%s", arr1[i]);

		// 키 입력
		scanf("%s", tmp);
		if (tmp[0] != '0')
		{
			getKey();
		}

		// 둘레 탐색
		int ww[2] = { 0, h - 1 };
		int hh[2] = { 0, w - 1 };

		do
		{
			flag = false;
			memcpy(arr2, arr1, sizeof(arr1));

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < w; j++)
				{
					if ((arr2[ww[i]][j] >= 'A' && arr2[ww[i]][j] <= 'Z' && hasKey(arr2[ww[i]][j])) || arr2[ww[i]][j] == '.' || arr2[ww[i]][j] == '$' || (arr2[ww[i]][j] >= 'a' && arr2[ww[i]][j] <= 'z'))
						find(ww[i], j);
				}
			}

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < h; j++)
				{
					if ((arr2[j][hh[i]] >= 'A' && arr2[j][hh[i]] <= 'Z' && hasKey(arr2[j][hh[i]])) || arr2[j][hh[i]] == '.' || arr2[j][hh[i]] == '$' || (arr2[j][hh[i]] >= 'a' && arr2[j][hh[i]] <= 'z'))
						find(j, hh[i]);
				}
			}
		} while (flag);

		printf("%d\n", result);
	}

	return 0;
}