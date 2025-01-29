/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_var_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:50:58 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 16:52:49 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isvalid_var_name(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}
