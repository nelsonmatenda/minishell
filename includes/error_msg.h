/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:14:59 by nfigueir          #+#    #+#             */
/*   Updated: 2025/02/06 10:24:20 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define P_ERR_TOKEN "mini: syntax error near unexpected token\n"
# define P_ERR_QUOTES "mini: syntax error, invalid quotes\n"
# define P_ERR_NOT_FOUND "command not found\n"
# define HR_FILENAME "/tmp/miniheredoc1"
# define P_ERR_EXIT_HR "mini: warning: here-document delimited \
						by end-of-file (wanted)\n"

# define SIGNAL_ERR_SYNTAX 2
# define SIGNAL_CTRL_C 130
# define STATUS_CMD_NOT_FOUND 127

#endif
