//
// Created by Mort Deanne on 2019-09-03.
//

#include "ft_ptintf.h"

_Bool	set_buff_diouxx(t_mkfld *fld, t_prsng *tls)
{
	if (!(fld->str = (char*)malloc(sizeof(char) * (fld->lennum + fld->len + 1))))
		return (0);
	ft_memset(fld->str, ' ', fld->lennum + fld->len);//// или нулями?
	if (tls->flags & M_MINUS)
		fld->len -= fld->len_empty_field;
	itoa_base_union(tls, fld, &fld->str[fld->len]);
	/// заполнение нулями избытка точности
	if (tls->precision > fld->lennum)
	{
		fld->len -= tls->precision - fld->lennum;
		ft_memset(&fld->str[fld->len], '0', tls->precision - fld->lennum);
	}
	set_flags(fld, tls);
	to_buff(fld->str, tls);
	free(fld->str);
	return (1);
}

_Bool	set_buff_csp(t_mkfld *fld, t_prsng *tls)
{

}

void	set_buff_not_typeflag(t_mkfld *field, t_prsng *tools)
{

}