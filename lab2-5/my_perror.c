#include <stdio.h>
#include <errno.h>
#include <string.h>

void my_perror(const char *message) {
	if (message != NULL && message[0] != '\0') {
		fprintf(stderr, "%s: %s\n", message, strerror(errno));
	} else {
		fprintf(stderr, "%s\n", strerror(errno));
	}
}
