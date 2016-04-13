/*
 * 1744¹ø ¼ö ¹­±â
 * https://www.acmicpc.net/problem/1744
 *
 * ID: kkd927
 * Github: https://github.com/kkd927/baekjoon
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

int tmp, N;
long long result;
std::vector<int> plus, minus;

int main()
{
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &tmp);
		if (tmp > 0) plus.push_back(tmp);
		else minus.push_back(tmp);
	}

	if (minus.size() % 2 == 1) minus.push_back(1);
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	
	if (plus.size() % 2 == 1) {
		result += plus[0];
		for (size_t i = 1; i < plus.size(); i += 2) {
			if (plus[i] == 1) result += plus[i] + plus[i + 1];
			else result += 1LL * plus[i] * plus[i + 1];
		}
	}
	else {
		for (size_t i = 0; i < plus.size(); i += 2) {
			if (plus[i] == 1) result += plus[i] + plus[i + 1];
			else result += 1LL * plus[i] * plus[i + 1];
		}
	}

	for (size_t i = 0; i < minus.size(); i += 2) {
		result += 1LL * minus[i] * minus[i + 1];
	}
	printf("%lld\n", result);
	return 0;
}