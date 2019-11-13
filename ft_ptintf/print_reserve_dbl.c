//
// Created by da.filiptsev on 13.11.2019.
//

char		*print_nan(_Bool sign)
{
	return (sign ? "-NaN" : "+Nan");
}

char		*print_inf(_Bool sign)
{
	return (sign ? "-Inf" : "+Inf");
}

char		*print_zero(_Bool sign)
{
	return (sign ? "-0" : "+0");
}