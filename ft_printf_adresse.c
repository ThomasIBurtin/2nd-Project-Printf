/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adresse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:23:32 by tburtin           #+#    #+#             */
/*   Updated: 2023/11/17 17:51:38 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_string(unsigned long value, int *strlen)
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

int	ft_printf_adresse(unsigned long value)
{
	unsigned long	tempval;
	char			*printout;
	int				i;

	i = 0;
	if (value == 0)
		return (i += ft_printf_string("(nil)"));
	tempval = value;
	printout = create_string(value, &i);
	if (!printout)
		return (0);
	while (i > 0)
	{
		if ((tempval % 16) < 10)
			printout[i - 1] = (tempval % 16) + 48;
		else
			printout[i - 1] = (tempval % 16) + 87;
		tempval = tempval / 16;
		i--;
	}
	i = ft_printf_string("0x");
	i = i + ft_printf_string(printout);
	free(printout);
	return (i);
}
