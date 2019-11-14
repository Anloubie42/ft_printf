/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:58:04 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/12 13:36:45 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_s(t_printf *liste)
{
	char	*tmp;
	int		len;
	char	*hold;

	if (!(tmp = ft_strdup(va_arg(liste->ap, char*))))
		if (!(tmp = ft_strdup("(null)")))
			return ;
	if (liste->len >= 0)
	{
		hold = tmp;
		tmp = ft_substr(hold, 0, liste->len);
		free(hold);
		liste->len = -1;
	}
	len = ft_strlen(tmp);
	if (liste->padding > 0 && liste->tiret == 0)
		ft_add_blank(liste, len);
	if (liste->len != 0)
		ft_putstr(tmp);
	if (liste->padding > 0 && liste->tiret == 1)
		ft_add_blank(liste, len);
	liste->ret += len;
	free(tmp);
}
