/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:57 by moaatik           #+#    #+#             */
/*   Updated: 2024/10/24 20:32:08 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long i)
{
	int	count;

	if (i == 0)
		return (1);
	count = 0;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static long	if_neg(int n, int *sign)
{
	long	nbr;

	nbr = n;
	*sign = 0;
	if (nbr < 0)
	{
		*sign = 1;
		nbr *= -1;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		sign;
	long	nbr;

	nbr = if_neg(n, &sign);
	len = count(nbr);
	ptr = malloc(sizeof(char) * (len + sign + 1));
	if (!ptr)
		return (NULL);
	if (sign == 1)
		ptr[0] = '-';
	ptr[len + sign] = 0;
	len--;
	while (len >= 0)
	{
		ptr[len + sign] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (ptr);
}
