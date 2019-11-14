/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:27:09 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/12 12:19:47 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ld(unsigned int n)
{
	unsigned int	nb;
	int				len;
	char			c;
	unsigned int	temp;

	nb = n;
	len = 1;
	temp = nb;
	while (nb /= 10)
		len *= 10;
	while (len > 0)
	{
		c = '0' + (temp / len);
		ft_putchar(c);
		temp %= len;
		len /= 10;
	}
}
