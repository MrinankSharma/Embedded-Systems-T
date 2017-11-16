#include <stdio.h>

int fibonacci(int input) {
	if (input < 0) {
		return -1;
	}
	if (input > 1) {
		return fibonacci(input - 1) + fibonacci(input - 2);
	}
	return 1;
}

int main(int argc, const char *argv[]) {
	int i = 0;
	for (; i < 10; ++i) {
		printf("%d ", fibonacci(i));
	}
	return 0;
}
