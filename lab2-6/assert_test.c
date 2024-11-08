#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void foo(int num) {
	assert(((num >= 0) && (num <= 100)));
	printf("foo: num = %d\n", num);
}

void main(int argc, char *argv[]) {
	int num;
	if(argc < 2) {
		fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= \n");
		exit(1);
	}

	num = atoi (argv[1]);
	foo(num);
}
