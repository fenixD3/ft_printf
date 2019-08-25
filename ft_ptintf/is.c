//
// Created by Mort Deanne on 2019-08-25.
//

_Bool is_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'f' /*и другие типы с плавающей точкой*/)
		return (1);
	return (0);
}
