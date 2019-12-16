#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

static int grow_array(int **xs, size_t *size, size_t new_size)
{
	int *tmp;
	if (new_size <= *size) {
		return 0;
	}
	tmp = realloc(*xs, new_size * sizeof(*xs));
	if (!tmp) {
		return -1;
	}
	*xs = tmp;
	*size = new_size;
	return 0;
}

int read_array(int **xs, size_t *size, size_t *len)
{
	int cur, err, nread;
	*len = 0;
	if ((err = grow_array(xs, size, 16)) < 0) {
		return err;
	}
	while ((nread = scanf("%d", &cur)) > 0) {
		if (*len == *size) {
			if ((err = grow_array(xs, size, *size * 2)) < 0) {
				return err;
			}
		}
		(*xs)[*len] = cur;
		*len += 1;
	}
	return nread == EOF ? 0 : -1;
}

static void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

// sort function uses the selection sort algorithm
void sort(int *xs, size_t n)
{
	size_t i, j;
	size_t min;
	for (i = 0; i < n; ++i) {
		min = i;
		for (j = i + 1; j < n; ++j) {
			if (xs[j] < xs[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(&xs[i], &xs[min]);
		}
	}
}
