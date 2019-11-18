#include <stdarg.h>

#include "ft_ptintf.h"

#include <stdio.h>
void zeroing_tools(t_prsng *tools, _Bool zeroing_counter);




int main() {




/*	printf("aaaa%lfbbb\n", 12.5);
	printf("aaaa%dbb\n", sizeof(double));*/
//	printf("ooo%#5.4xooo\n", 100);

/*int a;
unsigned int b;

a = -10;
b = (unsigned int)a;
a = (int)b;
printf("%d %u\n\n\n", a, b);9223372036854775807
printf("%o %o\n\n\n", a, b);*/


	int real;
	int my;

	/*real = printf("%s %s %s %s", "this", "is", "a", "multi");
	printf("\n----------\n");
	my = ft_printf("%s %s %s %s", "this", "is", "a", "multi"); ////error %05d,  256??
	printf("\n");
	printf("%d %d", real, my);*/
	//printf("%10.4m");

	/*printf("Int %zu\nUint %zu\nLong %zu\nUlong %zu\nLong long %zu\nUlong long %zu\n",
		   sizeof(int), sizeof(unsigned int), sizeof(long), sizeof(unsigned long),
		   sizeof(long long), sizeof(unsigned long long));*/

	/*t_prsng tools;
	PrintDouble(&tools, 4.5);*/

	//printf("%d\n", (uint32_t)(ft_log2(15728640) - 22));
	//printf("%zu\n", sizeof(unsigned long long));
	print_long_double(NULL, 3.75);
	printf("\n\n\n");
	print_long_double(NULL, -3.75);

//printf("%0.*k%d\n", 3, 2, 5);
//ft_printf("%");
//	t_prsng tools;
//	zeroing_tools(&tools);
//	to_buff("1234567", &tools);
//	ft_putchar('-');
//	to_buff("AA", &tools);
//	ft_putchar('-');
//	to_buff("123", &tools);
//	ft_putchar('-');
//	to_buff("456", &tools);
//	ft_putchar('-');
//	to_buff("789", &tools);
//	ft_putchar('-');
//	to_buff("BBB", &tools);
	return 0;
}
