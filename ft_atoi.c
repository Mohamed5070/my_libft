/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:25:34 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/12 01:51:48 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle(long result, int sign, const char *str)
{
	if (result > (922337203685477580) \
		|| (result == (922337203685477580) \
		&& (*str - '0') > 7))
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	int		error;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		error = handle(result, sign, &str[i]);
		if (error != 1)
			return (error);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
