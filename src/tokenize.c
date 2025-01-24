/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:41 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/23 16:03:36 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_wrong_comb(char *s)
{
	if (*s == '|' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '>' || *(s + 1) == '<'))
		return (-1);
	else if (*s == '>' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '<'))
		return (-1);
	else if (*s == '<' && *(s + 1) && ( *(s + 1) == '|' \
		|| *(s + 1) == '>'))
		return (-1);
	return (1);
}

int	check_multiple_limits(char *s)
{
	int	err;

	err = 0;
	while (*s && (*s == '|' || *s == '<' || *s == '>'))
	{
		if (check_wrong_comb(s) == -1)
			return (-1);
		s++;
		err++;
	}
	if (err > 2)
		return (-1);
	return (1);
}

int	is_limts(t_quote *list)
{
	char	c;

	c = list->data[0];
	if (list->type == NO_QUOTE && (c == '|' || c == '>' || c == '<'))
	{
		if (check_multiple_limits(list->data) == -1)
			return (-1);
	}
	else
		return (0);
	return (1);
}

int	first_caracter_case(t_quote *list)
{
	char	*s;

	s = list->data;
	if (list->type == NO_QUOTE)
	{
		if (*s && (*s == '|' || *s == '<' || *s == '>'))
		{
			if (*s == '|') // erro de sintax
				return (-1);
			if (check_multiple_limits(s) == -1)
				return (-1);
		}
	}
	else
		return (0);
	return (1);
}

int	sub(t_quote *aux, int *count)
{
	int	is;
	int	

	is = 0;
	while (aux != NULL)
	{
		is = is_limts(aux);
		if (is == 0)
			(*count)++;
		else if (is == -1)
			return (-1);
		else
		{
			if (aux->next == NULL)
				return (-1);
		}
		aux = aux->next;
	}
	return (1);
}

int	count_tokens(t_shell *shell)
{
	t_quote	*aux;
	int	count;
	int	is;

	aux = shell->list_input;
	count = 0;
	is = first_caracter_case(shell->list_input);
	if (is == -1)
		return (-1);
	else if (is == 1)
		aux = aux->next;
	sub(aux, &count);
	return (count);
}


int	tokenize(t_shell *shell)
{
	int	size;

	size = count_tokens(shell);
	printf("%d\n", size);
	return (1);
}

int main (int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_shell shell;

	init_shell(&shell, envp);
	shell.input = readline("👽-➤  ");
	shell.list_input = expand_env_var(shell.input, envp);
	tokenize(&shell);
}
