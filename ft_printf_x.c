/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 10:17:08 by antoine           #+#    #+#             */
/*   Updated: 2019/11/12 17:13:49 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_x(t_printf *liste, char *dest, long tmp)
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
	ft_putstr(dest);
	while (liste->padding > tmp && liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void		ft_print_x2(t_printf *liste, char *dest, long tmp)
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
	ft_putstr(dest);
	while (liste->padding > tmp && liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void		ft_print_x3(t_printf *liste, long tmp)
{
	while ((liste->padding > liste->len || liste->padding > tmp) &&
			!liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
	while ((liste->padding > liste->len || liste->padding > tmp) &&
			liste->tiret)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void		ft_printf_x(t_printf *liste, char *str)
{
	int		ret;
	int		len;
	char	*dest;

	ret = va_arg(liste->ap, int);
	if (ret == 0 && liste->len == 0 && liste->padding == 0)
		return ;
	if (!(dest = ft_uitoa_base((unsigned int)ret, str)))
		return ;
	len = ft_strlen(dest);
	if ((ret != 0) || (ret == 0 && liste->len != 0))
		liste->ret += len;
	if (ret == 0 && liste->len == 0)
		ft_print_x3(liste, len);
	else if (liste->len >= 0)
		ft_print_x(liste, dest, len);
	else if (liste->len < 0)
		ft_print_x2(liste, dest, len);
	free(dest);
}
