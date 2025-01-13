/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:20:01 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 13:53:00 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

//int	main(void)
//{
//	char s[] = "matenda@hotmail.com";
//	char *domain = ft_memchar(s, '@', ft_strlen(s));
//
//	printf("domain: %s\n", domain);
//	return (0);
//}
