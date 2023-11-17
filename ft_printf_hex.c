/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:23:42 by tburtin           #+#    #+#             */
/*   Updated: 2023/11/17 16:35:00 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string_hex(unsigned int value, int *strlen)
{
	int		i;
	char	*str;

	i = 0;
	while (value != 0)
	{
		value = value / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i;
	return (str);
}

int	ft_printf_hex(unsigned long value, int asc)
{
	unsigned int	tempval;
	char			*printout;
	int				i;

	value = (unsigned int)value;
	tempval = value;
	printout = create_string_hex(value, &i);
	if (!printout)
		return (0);
	while (i > 0)
	{
		if ((tempval % 16) < 10)
			printout[i - 1] = (tempval % 16) + 48;
		else
			printout[i - 1] = (tempval % 16) + asc;
		tempval = tempval / 16;
		i--;
	}
	i = ft_printf_string(printout);
	free(printout);
	if (value == 0)
		i += ft_printf_char('0');
	return (i);
}
