/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:49:13 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/13 16:14:31 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_loop(t_printf *liste, long tmp)
{
	while (liste->len > 0 && liste->len >= tmp)
	{
		ft_putchar('0');
		liste->ret++;
		liste->len--;
		liste->padding--;
	}
}

void			ft_print_ints_3(t_printf *liste, long ret, long tmp)
{
	if (ret != 2147483648)
		ft_putnbr(ret);
	else if (ret != 0 && liste->len != 0)
		ft_putnbr_ld(ret);
	while (liste->padding > liste->len && liste->padding > tmp && liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void			ft_print_ints(t_printf *liste, long ret, long tmp)
{
	if (ret < 0 && liste->len >= tmp && !liste->tiret)
		liste->padding--;
	while (liste->padding > liste->len && liste->padding > tmp &&
			!liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
	if (ret < 0)
	{
		ft_putchar('-');
		ret *= -1;
		ft_loop(liste, tmp);
		ft_print_ints_3(liste, ret, tmp);
	}
	else
	{
		ft_loop(liste, tmp + 1);
		ft_print_ints_3(liste, ret, tmp);
	}
}

void			ft_print_ints_2(t_printf *liste, long ret, long tmp)
{
	while (liste->padding > 0 && liste->padding > tmp && !liste->tiret &&
			!liste->zero)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
	if (ret < 0)
	{
		ft_putchar('-');
		ret *= -1;
	}
	while (liste->padding > 0 && liste->padding > tmp && liste->zero)
	{
		ft_putchar('0');
		liste->ret++;
		liste->padding--;
	}
	ft_print_ints_3(liste, ret, tmp);
}

void			ft_printf_d(t_printf *liste)
{
	long		tmp;
	long		ret;

	ret = va_arg(liste->ap, int);
	tmp = ft_len(ret);
	if ((ret != 0) || (ret == 0 && liste->len != 0))
		liste->ret += tmp;
	if (liste->len >= 0 && ret != 0)
		ft_print_ints(liste, ret, tmp);
	else if (liste->len < 0)
		ft_print_ints_2(liste, ret, tmp);
	else if (liste->len == 0 && ret == 0)
		ft_add_blank(liste, 0);
	else if (liste->len > 0 && ret == 0)
		ft_print_ints(liste, ret, tmp);
}
