/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:04:55 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/09 15:04:17 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!dst && !src)
		return (NULL);
	ptr = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(ptr++) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
