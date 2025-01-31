/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_two_point.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:55:33 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/31 09:01:11 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_with_two_point(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		join[i] = *(s1 + j);
		i++;
		j++;
	}
	join[i++] = ':';
	j = 0;
	while (s2[j])
	{
		join[i] = *(s2 + j);
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}
