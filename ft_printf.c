/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:24:03 by tburtin           #+#    #+#             */
/*   Updated: 2023/11/17 16:30:49 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	quelle_type(char lettre, va_list arg)
{
	int	count2;

	count2 = 0;
	if (lettre == 'c')
		count2 = count2 + ft_printf_char(va_arg(arg, int));
	else if (lettre == 's')
		count2 = count2 + ft_printf_string(va_arg(arg, char *));
	else if (lettre == 'd')
		count2 = count2 + ft_printf_int(va_arg(arg, int));
	else if (lettre == 'i')
		count2 = count2 + ft_printf_int(va_arg(arg, int));
	else if (lettre == 'u')
		count2 = count2 + ft_printf_unsigned_int(va_arg(arg, unsigned int));
	else if (lettre == 'p')
		count2 = count2 + ft_printf_adresse((unsigned long)va_arg(arg, void *));
	else if (lettre == 'X')
		count2 = count2 + ft_printf_hex((unsigned long)va_arg(arg, void *), 55);
	else if (lettre == 'x')
		count2 = count2 + ft_printf_hex((unsigned long)va_arg(arg, void *), 87);
	return (count2);
}

int	ft_printf(const char *format, ...)
{
	va_list	parameters;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(parameters, format);
	while (format [i] != '\0')
	{
		if (format[i] != '%')
		{
			count = count + ft_printf_char(format[i]);
		}
		else
		{
			i++;
			if (format[i] == '%')
				count = count + ft_printf_char('%');
			else
				count = count + quelle_type(format[i], parameters);
		}
		i++;
	}
	va_end(parameters);
	return (count);
}
