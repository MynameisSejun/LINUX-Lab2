#include <stdio.h>
#include <stdlib.h>

void my_assert(int expression, const char *expression_str, const char *file, int line) {
	if (!expression) {
		fprintf(stderr, "Assertion failed: (%s), file %s, line %d\n", expression_str, file, line);
		exit(EXIT_FAILURE);
	}
}
