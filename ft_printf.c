/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:23:19 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/12 16:44:13 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_printf *liste)
{
	liste->zero = 0;
	liste->tiret = 0;
	liste->padding = 0;
	liste->len = -1;
}

void	ft_choose(t_printf *liste)
{
	if (liste->c == 'c')
		ft_printf_c(liste);
	else if (liste->c == 's')
		ft_printf_s(liste);
	else if (liste->c == 'p')
		ft_printf_p(liste);
	else if (liste->c == 'd' || liste->c == 'i')
		ft_printf_d(liste);
	else if (liste->c == 'u')
		ft_printf_u(liste);
	else if (liste->c == 'x')
		ft_printf_x(liste, "0123456789abcdef");
	else if (liste->c == 'X')
		ft_printf_x(liste, "0123456789ABCDEF");
	else if (liste->c == '%')
		ft_printf_percent(liste);
}

int		ft_isin(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_parse(char *str, t_printf *liste)
{
	char		*set;
	int			i;

	i = 0;
	set = "cspdiuxX%";
	ft_init_struct(liste);
	if (str[i] == '0')
	{
		liste->zero = 1;
		i++;
	}
	if (str[i] == '-')
	{
		liste->tiret = 1;
		i++;
	}
	i = ft_flags(liste, str, set, i);
	liste->c = str[i++];
	ft_choose(liste);
	return (&str[i]);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	t_printf	liste;

	liste.ret = 0;
	i = 0;
	va_start(liste.ap, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i++]);
			liste.ret++;
		}
		if (str[i] && str[i] == '%')
		{
			str = ft_parse((char*)(str + i + 1), &liste);
			i = 0;
		}
	}
	return (liste.ret);
}
