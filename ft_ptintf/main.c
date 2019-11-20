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

	int i;


	int real;
	int my;

/*	char *str = {"@moulitest: %#.o"};
	int num = 0;
	real = printf(str, num);
	printf("\n----------\n");
   my = ft_printf(str, num);*/

	//real = printf("1%o 2%.o 3%.0o 4%#o 5%#.o", 0, 0 ,0 ,0 ,0);
	real = printf("%#.o", 1);
	printf("\n----------\n");
	my = ft_printf("%#.o", 1);

/*	real = printf("@moulitest: >%#.o< >%#.0o<", 0, 0);
	printf("\n----------\n");
	my = ft_printf("@moulitest: >%#.o< >%#.0o<", 0, 0);*/

	printf("\n");
	printf("%d %d", real, my);
	//printf("%10.4m");

/*	for(int i = 0; i < 32; i++)
	{
		printf("%d\ta%ca\n", i, (char)i);
	}*/

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