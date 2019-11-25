#include <stdarg.h>

#include "ft_ptintf.h"
#include "myfloat.h"

#include <stdio.h>
#include <math.h>
#include <fcntl.h>
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

/*	int i;


	int real;
	int my;*/

/*	char *str = {"@moulitest: %#.o"};
	int num = 0;
	real = printf(str, num);
	printf("\n----------\n");
   my = ft_printf(str, num);*/

/*	real = printf("%.16384Lf", LDBL_MIN);
	printf("\n----------\n");*/

	//printf("%d\n", ft_64log2(8301034833169298));

	/*printf("FT ceil\n%f\n", ft_ceil(-4.5));
	printf("LB ceil\n%f\n", ceil(-4.5));*/

	/*printf("FT floor\n%f\n", ft_floor(-4.5));
	printf("LB floor\n%f\n", floor(-4.5));*/

	/*printf("FT round\n%f\n", ft_round(0.4999999999999999));
	printf("LB round\n%f\n", round(0.4999999999999999));*/

	double		i = 0.99;
	uint64_t	*dbl;
	int32_t		exp_val;
	uint64_t	mant_val;

	dbl = (uint64_t *)&i;
	exp_val = get_exp(dbl);
	if (!exp_val)
	{
		exp_val = 1 - OFFSET_DBL;
		mant_val = get_mantissa(dbl);
	}
	else
	{
		exp_val -= OFFSET_DBL;
		mant_val = (1LL << 52) | get_mantissa(dbl);
	}
	ft_printf("%f\n", i);
	printf("%d\n", ft_log10(mant_val, exp_val));

/*	int fp = open("Logs_lg", O_WRONLY);

	for (double i = 0.00000005; i <= 5E307; i *= 10)
	{
		dbl = (uint64_t *)&i;
		exp_val = get_exp(dbl);
		if (!exp_val)
		{
			exp_val = 1 - OFFSET_DBL;
			mant_val = get_mantissa(dbl);
		}
		else
		{
			exp_val -= OFFSET_DBL;
			mant_val = (1LL << 52) | get_mantissa(dbl);
		}
		fprintf(&fp, "Num = %.10f\n\tLog 10 = %d\n\tExp2 = %d\n", i, ft_log10(mant_val, exp_val), exp_val);
	}
	close(fp);*/

	FILE *fp = fopen("Logs_lg", "w");

	for (double i = 0.00000009; i <= 5E307; i *= 10)
	{
		dbl = (uint64_t *)&i;
		exp_val = get_exp(dbl);
		if (!exp_val)
		{
			exp_val = 1 - OFFSET_DBL;
			mant_val = get_mantissa(dbl);
		}
		else
		{
			exp_val -= OFFSET_DBL;
			mant_val = (1LL << 52) | get_mantissa(dbl);
		}
		fprintf(fp, "Num = %.10f\n\tLog 10 = %d\n\tExp2 = %d\n", i, ft_log10(mant_val, exp_val), exp_val);
		fprintf(fp, "\tCeiling log value = %f\n", ((int32_t)ft_64log2(mant_val) + (exp_val - 52)) * LOG10_2 - 0.69);
	}
	fclose(fp);

/*	real = printf("@moulitest: >%#.o< >%#.0o<", 0, 0);
	printf("\n----------\n");
	my = ft_printf("@moulitest: >%#.o< >%#.0o<", 0, 0);*/

	/*printf("\n");
	printf("%d %d", real, my);*/
	//printf("%10.4m");

/*	for(int i = 0; i < 32; i++)
	{
		printf("%d\ta%ca\n", i, (char)i);
	}*/
	//printf("%d %d", real, my);
	//printf("%10.4m");

	/*printf("Int %zu\nUint %zu\nLong %zu\nUlong %zu\nLong long %zu\nUlong long %zu\n",
		   sizeof(int), sizeof(unsigned int), sizeof(long), sizeof(unsigned long),
		   sizeof(long long), sizeof(unsigned long long));*/

	/*printf("%s\n", print_double(NULL, DBL_MAX));
	printf("----------------------\n");*/

	//printf("%d\n", (uint32_t)(ft_log2(15728640)));
	//printf("%zu\n", sizeof(unsigned long long));
	/*printf("%s\n", print_long_double(NULL, 0.5));
	printf("----------------------\n");
	printf("%s\n\n", print_long_double(NULL, LDBL_MAX));*/
	/*printf("----------------------\n");
	printf("%s\n\n", print_long_double(NULL, LDBL_MAX));*/

	//printf("%f\n", ft_ceil(-0.5));

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
