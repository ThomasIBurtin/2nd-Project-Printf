/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:25:50 by tburtin           #+#    #+#             */
/*   Updated: 2023/11/17 16:38:33 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "1st-Project-Libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printf_char(char c);
int	ft_printf_string(char *s);
int	ft_printf_int(int n);
int	ft_printf_unsigned_int(unsigned int n);
int	ft_printf_adresse(unsigned long value);
int	ft_printf_hex(unsigned long value, int taille);

#endif
