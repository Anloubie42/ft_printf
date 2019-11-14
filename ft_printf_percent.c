/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:53:21 by antoine           #+#    #+#             */
/*   Updated: 2019/11/06 14:06:34 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_char(t_printf *liste, char c)
{
	while (liste->padding > 0)
	{
		ft_putchar(c);
		liste->ret++;
		liste->padding--;
	}
}

void		ft_printf_percent(t_printf *liste)
{
	liste->padding -= 1;
	if (liste->zero == 1 && liste->padding > 0)
		ft_add_char(liste, '0');
	if (liste->padding > 0 && !liste->tiret)
		ft_add_char(liste, ' ');
	ft_putchar('%');
	if (liste->padding > 0 && liste->tiret)
		ft_add_char(liste, ' ');
	liste->ret++;
}
