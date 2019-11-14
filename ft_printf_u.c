/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:07:49 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/13 15:50:04 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_ui(t_printf *liste, long ret, long tmp)
{
	while (liste->padding > liste->len && liste->padding > tmp && !liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
	while (liste->len > 0 && liste->len > tmp)
	{
		ft_putchar('0');
		liste->ret++;
		liste->len--;
		liste->padding--;
	}
	if (ret != 0)
		ft_putnbr_ld(ret);
	while (liste->padding > tmp && liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void		ft_print_ui2(t_printf *liste, long ret, long tmp)
{
	while (liste->padding > 0 && liste->padding > tmp && !liste->tiret &&
			!liste->zero)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
	while (liste->padding > tmp && liste->zero)
	{
		ft_putchar('0');
		liste->ret++;
		liste->padding--;
	}
	ft_putnbr_ld(ret);
	while (liste->padding > tmp && liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void		ft_printf_u(t_printf *liste)
{
	long			tmp;
	long			ret;

	ret = va_arg(liste->ap, unsigned int);
	if (ret == 0 && liste->len == 0 && liste->padding == 0)
		return ;
	tmp = ft_len(ret);
	if (ret == 0 && liste->len >= 0)
		tmp -= 1;
	if ((ret != 0) || (ret == 0 && liste->len != 0))
		liste->ret += tmp;
	if (liste->len >= 0)
		ft_print_ui(liste, ret, tmp);
	else if (liste->len < 0)
		ft_print_ui2(liste, ret, tmp);
}
