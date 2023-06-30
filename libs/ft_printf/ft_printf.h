/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:25:04 by ykerdel           #+#    #+#             */
/*   Updated: 2023/03/21 17:31:33 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_charcount(const char *str, char c);
int		ft_formats(va_list args, char c);
void	ft_putchar(const char c);

int		ft_print_str(char *args);
int		ft_print_ptr(unsigned long long args);
int		ft_print_nbr(int args);
int		ft_print_unsigned(unsigned long long args);
int		ft_print_hex(unsigned int args, char c);

char	*ft_htoa(unsigned int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ptoa(unsigned long long n);

int		tt_tolower(int str);
char	*tt_itoa(int n);
size_t	tt_strlen(const char *s);
void	*tt_memcpy(const char *dest, const char *src, size_t n);
size_t	ft_unumlen(unsigned int n);
size_t	ft_intlen(int n);
char	*tt_strdup(const char *s);

#endif