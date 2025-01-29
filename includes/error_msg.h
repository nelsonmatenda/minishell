/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:14:59 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/29 12:43:35 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define P_ERR_TOKEN "mini: syntax error near unexpected token\n"
# define P_ERR_QUOTES "mini: syntax error, invalid quotes\n"
# define P_ERR_NOT_FOUND "command not found\n"

enum e_error
{
	SY_ERR = -42,
	MEM_ERR = -43
};

#endif
