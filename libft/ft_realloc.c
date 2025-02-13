/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:17:52 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/11 10:13:35 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t newsize)
{
	char	*newptr;

	newptr = NULL;
	if (ptr == 0)
		return (malloc(newsize));
	if (newsize <= old_size)
		return (ptr);
	newptr = malloc(newsize);
	if (!newptr)
		return (NULL);
	ft_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}
