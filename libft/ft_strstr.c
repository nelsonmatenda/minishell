/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:38:39 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/06 13:50:13 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] != '\0'
			&& needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)(haystack + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}
