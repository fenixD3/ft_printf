#include <stdio.h>
#include <stdarg.h>

#include "ft_ptintf.h"

int main() {

	int *a;

	*a = 10000000;
	printf("%-040+.15dAAA\n", 123456789);

	ft_printf("%+-#0100.12hhd\n", a);

	return 0;
}