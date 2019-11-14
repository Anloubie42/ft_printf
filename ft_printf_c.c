/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:59:01 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/04 15:07:34 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_c(t_printf *liste)
{
	if (liste->padding > 0 && liste->tiret == 0)
		ft_add_blank(liste, 1);
	ft_putchar(va_arg(liste->ap, int));
	if (liste->padding > 0 && liste->tiret == 1)
		ft_add_blank(liste, 1);
	liste->ret++;
}
