#include "lib.h"

static void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

// sort function uses the selection sort algorithm
void sort(int *xs, int n)
{
	int i, j;
	int min;
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
