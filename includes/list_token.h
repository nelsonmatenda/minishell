/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:00:44 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 12:33:38 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TOKEN_H
# define LIST_TOKEN_H

typedef enum e_type
{
	TYPE_COMMAND,
	TYPE_ARGUMMENT,
	TYPE_PIPE, // |
	TYPE_REDIRECT_OUT, // >
	TYPE_REDIRECT_OUT_APPEND, // >>
	TYPE_REDIRECT_IN, // <
	TYPE_HE_DOC // <<
}	t_token_type;

typedef struct s_list_token
{
	char				*data;
	t_token_type		type;
	struct s_list_token	*next;
}						t_list_token;

t_list_token	*ft_lstnew_token(char *data);
void			ft_lstadd_token(t_list_token **lst, t_list_token *new_node);
void			destroy_list_token (t_list_token *tokens);


#endif
