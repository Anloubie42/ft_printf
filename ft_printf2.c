/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:16:16 by antoine           #+#    #+#             */
/*   Updated: 2019/11/12 16:44:00 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(t_printf *liste, char *str, char *set, int i)
{
	while (str[i] && !ft_isin(set, str[i]))
	{
		if (ft_atoi(&str[i]) != 0 && liste->padding == 0 && str[i - 1] != '.')
			liste->padding = ft_atoi(&str[i]);
		if (str[i] == '*' && str[i - 1] != '.')
		{
			liste->padding = va_arg(liste->ap, int);
			if (liste->padding < 0)
			{
				liste->tiret = 1;
				if (liste->zero)
					liste->zero = 0;
				liste->padding *= -1;
			}
		}
		if (str[i] == '.' && str[i + 1] == '*')
			liste->len = va_arg(liste->ap, int);
		else if (str[i] == '.' && str[i + 1] != '*')
			liste->len = ft_atoi(&str[i + 1]);
		i++;
	}
	return (i);
}

int		ft_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
