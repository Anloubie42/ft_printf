/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloubie <anloubie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:24:04 by anloubie          #+#    #+#             */
/*   Updated: 2019/11/12 15:19:48 by anloubie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct			s_printf
{
	va_list				ap;
	int					zero;
	int					tiret;
	char				c;
	int					padding;
	int					ret;
	int					len;
}						t_printf;

int						ft_printf(const char *str, ...);
void					ft_printf_c(t_printf *liste);
void					ft_printf_s(t_printf *liste);
void					ft_printf_p(t_printf *liste);
void					ft_printf_d(t_printf *liste);
void					ft_printf_u(t_printf *liste);
void					ft_printf_x(t_printf *liste, char *str);
void					ft_printf_percent(t_printf *liste);
void					ft_add_blank(t_printf *liste, int len);
void					ft_add_zero(t_printf *liste, int len);
char					*ft_itoa_base(int nb, char *base_to);
char					*ft_uitoa_base(unsigned long long int nb,
						char *base_to);
void					ft_putnbr_ld(unsigned int n);
int						ft_isin(char const *str, char c);
int						ft_flags(t_printf *liste, char *str, char *set, int i);
void					ft_print_flags(t_printf *liste);
int						ft_len(long n);
void					ft_print_ints(t_printf *liste, long ret, long tmp);
void					ft_print_ints_3(t_printf *liste, long ret, long tmp);
void					ft_loop(t_printf *liste, long tmp);
char					*ft_substr(char const *s, unsigned int start,
									size_t len);
void					ft_putnbr(int n);
void					ft_putstr(char *str);
void					ft_putchar(char c);
int						ft_atoi(const char *str);
char					*ft_strdup(const char *s1);
int						ft_strlen(const char *str);
#endif
