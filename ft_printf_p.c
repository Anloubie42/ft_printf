/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:11:02 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/04 17:52:51 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_p(t_printf *liste)
{
	void		*tmp;
	char		*hex;
	char		*dest;
	int			len;

	hex = "0123456789abcdef";
	tmp = va_arg(liste->ap, void *);
	if (!(dest = ft_uitoa_base((uintptr_t)tmp, hex)))
		return ;
	len = ft_strlen(dest) + 2;
	if (liste->padding > 0 && liste->tiret == 0)
		ft_add_blank(liste, len);
	ft_putstr("0x");
	liste->ret += len;
	ft_putstr(dest);
	if (liste->padding > 0 && liste->tiret == 1)
		ft_add_blank(liste, len);
	free(dest);
}
