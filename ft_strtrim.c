/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaatik <moaatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:17:44 by moaatik           #+#    #+#             */
/*   Updated: 2024/11/11 15:35:44 by moaatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	start_count(char const *s1, char const *set, size_t set_len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (s1[i])
	{
		j = 0;
		temp = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				temp++;
			j++;
		}
		if (temp == set_len)
			break ;
		i++;
	}
	return (i);
}

static	size_t	end_count(char const *s1, char const *set, size_t set_len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = ft_strlen(s1) - 1;
	j = 0;
	temp = 0;
	while (i > 0)
	{
		j = 0;
		temp = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				temp++;
			j++;
		}
		if (temp == set_len)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	set_len;
	char	*ptr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	set_len = ft_strlen(set);
	start = start_count(s1, set, set_len);
	end = end_count(s1, set, set_len);
	if (start > end)
		return (ft_strdup(""));
	ptr = malloc(sizeof(char) * (end - start + 2));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[start] && start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
