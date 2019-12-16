#pragma once

/* Read whitespace delimited integers from stdin into the given array.
 * Returns -1 on error and 0 on success.
 */
int read_array(int **xs, int *size, int *len);

void sort(int *xs, int n);
