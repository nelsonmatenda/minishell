/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:37:46 by matenda           #+#    #+#             */
/*   Updated: 2025/02/08 17:37:49 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	nb = 0L;
	sign = 1L;
	if (str == NULL)
		return (nb);
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1L;
	while (ft_isdigit(str[i]))
		nb = nb * 10 + str[i++] - '0';
	return (nb * sign);
}
