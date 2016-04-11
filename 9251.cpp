/*
 * 9251¹ø LCS
 * https://www.acmicpc.net/problem/9251
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 1001

char str1[M], str2[M];
int cache[M][M];

int lcs(int len1, int len2)
{
	if (len1 == 0 || len2 == 0) return 0;

	int &ret = cache[len1][len2];
	if (ret != -1) return ret;

	if (str1[len1 - 1] == str2[len2 - 1]) return ret = lcs(len1 - 1, len2 - 1) + 1;
	else return ret = std::max(lcs(len1 - 1, len2), lcs(len1, len2 - 1));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	printf("%d\n", lcs(len1, len2));
	return 0;
}