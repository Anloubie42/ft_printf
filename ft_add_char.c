/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:35:55 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/07 13:57:35 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_blank(t_printf *liste, int len)
{
	if (liste->len >= 0)
		liste->padding -= liste->len;
	else
		liste->padding -= len;
	while (liste->padding > 0)
	{
		ft_putchar(' ');
		liste->ret++;
		liste->padding--;
	}
}

void		ft_add_zero(t_printf *liste, int len)
{
	if (liste->len >= 0)
		liste->padding -= liste->len;
	else
		liste->padding -= len;
	while (liste->padding > 0)
	{
		ft_putchar('0');
		liste->ret++;
		liste->padding--;
	}
}
