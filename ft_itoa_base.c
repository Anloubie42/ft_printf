/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:28:45 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/12 12:38:42 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(int nb, char *base_to)
{
	char	*dest;
	int		base;
	int		tmp;
	int		size;

	size = 0;
	base = ft_strlen(base_to);
	tmp = nb;
	while (tmp /= base)
		size++;
	size++;
	if (!(dest = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	dest[size] = '\0';
	if (nb == 0)
		dest[0] = '0';
	while (nb > 0)
	{
		dest[--size] = base_to[nb % base];
		nb /= base;
	}
	return (dest);
}
