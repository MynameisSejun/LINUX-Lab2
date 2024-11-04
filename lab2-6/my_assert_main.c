#include <stdio.h>
#include <stdlib.h>
#include "my_assert.c"

void foo(int num) {
	my_assert((num >= 0) && (num <= 100), "(num >= 0 && (num <= 100)", __FILE__, __LINE__);
	printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]) {
	int num;
	if (argc < 2) {
		fprintf(stderr, "Usage: assert_test aBumber\n(0 <= aNumber <= 100)\n");
		exit(1);
	}

	num = atoi(argv[1]);
	foo(num);

	return 0;
}
