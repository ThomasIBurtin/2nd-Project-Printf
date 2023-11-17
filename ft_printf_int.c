/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:23:47 by tburtin           #+#    #+#             */
/*   Updated: 2023/11/17 16:29:52 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int n)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_itoa(n);
	ft_putstr_fd(result, 1);
	while (result[i] != '\0')
		i++;
	free(result);
	return (i);
}
