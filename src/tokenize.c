/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:28:09 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/14 12:25:56 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_special_characters(char *str, int *j, t_list_token **tokens)
{
	char	c[3];

	ft_bzero(c, sizeof(c));
	c[0] = str[*j];
	if (str[*j + 1] == str[*j])
	{
		c[1] = str[*j];
		(*j)++;
	}
	ft_lstadd_token(tokens, ft_lstnew_token(ft_strdup(c)));
}

static void	add_tokens_to_list(char *str, t_list_token **tokens)
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

t_list_token	*tokenize(char *input)
{
	t_list_token	*tokens;
	char			**splited;
	int				i;

	splited = ft_split(input, ' ');
	tokens = NULL;
	if (!splited)
		return (NULL);
	i = 0;
	while (splited[i] != NULL)
	{
		add_tokens_to_list(splited[i], &tokens);
		free(splited[i]);
		i++;
	}
	free(splited);
	return (tokens);
}
