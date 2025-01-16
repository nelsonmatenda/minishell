/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:28:09 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/16 12:24:12 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	identify_tokens(t_list_token *token)
{
	t_list_token *aux;

	while (token)
	{
		aux = token->next;
		if (!ft_strncmp(token->data,  "|", sizeof("|")))
			token->type = TYPE_PIPE;
		else if (!ft_strncmp(token->data, ">", sizeof(">")))
			token->type = TYPE_REDIRECT_OUT;
		else if (!ft_strncmp(token->data, ">>", sizeof(">>")))
			token->type = TYPE_REDIRECT_OUT_APPEND;
		else if (!ft_strncmp(token->data, "<", sizeof("<")))
			token->type = TYPE_REDIRECT_IN;
		else if (!ft_strncmp(token->data, "<<", sizeof("<<")))
			token->type = TYPE_HE_DOC;
		token = aux;
	}
	aux = NULL;
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
	identify_tokens(tokens);
	return (tokens);
}
// |  > >> << < $
// echo -e "hello$PATH"
int	cout_tokens(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		while (input[i] != '|' || input[i] == '<' || input[i] == '>')
		{
			if ()
			i++;
		}
		i++;
		count++;
	}
}
