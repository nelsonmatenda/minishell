/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:43:29 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/15 11:36:37 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_special_characters(char *str, int *j, t_list_token **tokens)
{
	char	c[254];
	char	special;
	int		i;

	ft_bzero(c, sizeof(c));
	i = 0;
	special = str[*j];
	c[i] = str[*j];
	while (str[*j + 1] == special)
	{
		c[++i] = special;
		(*j)++;
	}
	ft_lstadd_token(tokens, ft_lstnew_token(ft_strdup(c)));
}

void	add_tokens_to_list(char *str, t_list_token **tokens)
{
	int		j;
	int		k;
	char	text[1024];

	ft_bzero(text, sizeof(text));
	j = 0;
	k = 0;
	while (str[j])
	{
		k = 0;
		while (str[j] && str[j] != '|' && str[j] != '<' && str[j] != '>')
		{
			text[k++] = str[j++];
		}
		text[k] = '\0';
		if (text[0] != '\0')
			ft_lstadd_token(tokens, ft_lstnew_token(ft_strdup(text)));
		if (str[j] == '|' || str[j] == '<' || str[j] == '>')
			handle_special_characters(str, &j, tokens);
		if (str[j])
			j++;
	}
}
