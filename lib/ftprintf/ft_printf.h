/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:24:24 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/12 12:37:29 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		my_putunbr(unsigned int nb);
int		my_putchr(int c);
int		my_dectohex(unsigned int n, char cc);
int		ft_printf(const char *format, ...);
int		my_putnbr(int nb);
int		my_putpointer(unsigned long r);
int		my_putstr(char *str);
int		my_dectohexp(unsigned long n);

#endif
