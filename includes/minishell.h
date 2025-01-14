/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matenda <matenda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:06:00 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 21:10:19 by matenda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include "list_token.h"

void			destroy_splited(char **splited);
int				minishell(void);
t_list_token	*tokenize(char *input);
int				is_valid_command(char *token);
void			identify_tokens(t_list_token *token);


#endif

