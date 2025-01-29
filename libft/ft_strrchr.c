/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:32:03 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/17 15:42:49 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	chr = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

int	ft_strrchr_pos(const char *s, int c)
{
	int		i;
	char	chr;

	chr = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == chr)
			return (i);
		i--;
	}
	return (7168);
}
//int	main()
//{
//	char s[10]; //= "some,data,in,commas";
//	char *comma = ft_strrchr(s, ',');
//	printf("%s\n", comma);
//	return (0);
//}
