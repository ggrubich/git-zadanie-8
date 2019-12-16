#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char **argv)
{
	int *xs;
	int len = 0;
	int size = 16;
	int *tmp;
	int cur, i;
	xs = malloc(size * sizeof(*xs));
	if (!xs) {
		fprintf(stderr, "malloc error\n");
		return 1;
	}
	while (scanf("%d", &cur) > 0) {
		if (len == size) {
			tmp = realloc(xs, 2 * size * sizeof(*xs));
			if (!tmp) {
				free(xs);
				fprintf(stderr, "malloc error\n");
				return 1;
			}
			xs = tmp;
			size = 2 * size;
		}
		xs[len++] = cur;

	}
	sort(xs, len);
	for (i = 0; i < len; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", xs[i]);
	}
	printf("\n");
	free(xs);
	return 0;
}
