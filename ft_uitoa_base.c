/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:05:59 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/12 12:40:29 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(unsigned long long int nb, char *base_to)
{
	char			*dest;
	int				base;
	uintptr_t		tmp;
	int				size;

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
	while (nb)
	{
		dest[--size] = base_to[nb % base];
		nb /= base;
	}
	return (dest);
}
