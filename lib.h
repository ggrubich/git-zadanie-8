#pragma once

/* Read whitespace delimited integers from stdin into the given array.
 * Returns -1 on error and 0 on success.
 */
int read_array(int **xs, size_t *size, size_t *len);

void sort(int *xs, size_t n);
