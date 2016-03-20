#include <stdio.h>

int N;
char a, b;
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getc(stdin);
		while (a = getc(stdin)) {
			if (a == '\n')
				break;
			b = a;
		}

		if (((b - 48) & 1) == 0)
			printf("even\n");
		else
			printf("odd\n");
	}

	return 0;
}
