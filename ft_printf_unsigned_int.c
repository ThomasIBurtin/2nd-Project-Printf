/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:23:55 by tburtin           #+#    #+#             */
/*   Updated: 2023/11/17 17:04:30 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_size_unsigned(unsigned int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	long	num;
	size_t	size;

	num = n;
	size = get_size_unsigned(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	*(str + size--) = '\0';
	while (num > 0)
	{
		*(str + size--) = num % 10 + '0';
		num /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1])
		*(str + size) = '-';
	return (str);
}

int	ft_printf_unsigned_int(unsigned int n)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_itoa_unsigned(n);
	ft_putstr_fd(result, 1);
	while (result[i] != '\0')
		i++;
	free(result);
	return (i);
}
