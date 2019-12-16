#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lib.h"

int main(int argc, char **argv)
{
	int *xs = NULL;
	int size = 0;
	int len = 0;
	int i;
	if (read_array(&xs, &size, &len) < 0) {
		if (errno == ENOMEM) {
			fprintf(stderr, "out of memory\n");
		} else {
			fprintf(stderr, "failed to read numbers\n");
		}
		free(xs);
		return 1;
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
