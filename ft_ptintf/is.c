//
// Created by Mort Deanne on 2019-08-25.
//

_Bool is_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'f' /*и другие типы с плавающей точкой*/)
		return (1);
	return (0);
}

_Bool	is_typeflag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

_Bool 	is_diouxx(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}