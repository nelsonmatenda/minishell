/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:24:10 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/23 09:06:06 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_wrong_comb(char **s)
{
	if (**s == '|' && *(*s + 1) && ( *(*s + 1) == '|' \
		|| *(*s + 1) == '>' || *(*s + 1) == '<'))
		return (-1);
	else if (**s == '>' && *(*s + 1) && ( *(*s + 1) == '|' \
		|| *(*s + 1) == '<'))
		return (-1);
	else if (**s == '<' && *(*s + 1) && ( *(*s + 1) == '|' \
		|| *(*s + 1) == '>'))
		return (-1);
	return (1);
}

int	check_multiple_limits(char **s)
{
	int	err;

	err = 0;
	while (*s && (**s == '|' || **s == '<' || **s == '>'))
	{
		if (check_wrong_comb(s) == -1)
			return (-1);
		(*s)++;
		err++;
	}
	while (**s && (**s == ' ' || (**s >= 0 && **s <= 9)))
	{
		(*s)++;
		if (**s && (**s == '|' || **s == '<' || **s == '>'))
			return (-1);
		if (**s == '\0')
			return (-1);
	}
	if (err > 2)
		return (-1);
	if (*(*s -1) && (*(*s -1) == '|' || *(*s -1) == '<' || *(*s -1) == '>'))
		return (-1);
	return (1);
}

int	first_caracter_case(char **s)
{
	if (ft_iswhitespace(**s))
	{
		while (ft_iswhitespace(**s))
			(*s)++;
	}
	if (**s && (**s == '|' || **s == '<' || **s == '>'))
	{
		if (**s == '|') // erro de sintax
			return (-1);
		if (check_multiple_limits(s) == -1)
			return (-1);
	}
	return (1);
}

// int	verif_quotes(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (s[i] && (s[i] == '\'' || s[i] == '"'))
// 	{
// 		while (s[i] && (s[i] != '\'' || s[i] != '"'))
// 			i++;
// 		if (s[i] == '\0')
// 			return (-1);
// 	}
// 	return (i);
// }

int	count_command(char	*s)
{
	int	count;

	count = 0;
	if (first_caracter_case(&s) == -1)
		return (-1);
	while (s)
	{
		while (*s && (*s != '|' && *s != '<' && *s != '>'))
			s++;
		if (check_multiple_limits(&s) == -1)
			return (-1);
		count++;
		while (*s && (*s == ' ' || (*s >= 0 && *s <= 9)))
			s++;
		if (*s == '\0')
			break;
	}
	return (count);
}
int	create_token(t_shell *shell, char **s, int *k)
{
	int	i;
	int	j;

	i = 0;
	while ((*s)[i] && (*s)[i] != '|' && (*s)[i] != '<' && (*s)[i] != '>')
		i++;
	shell->tokens[++(*k)].data = malloc(sizeof(char) * (i + 1));
	if (!shell->tokens[*k].data)
		return (-1);
	j = -1;
	while (**s && **s != '|' && **s != '<' && **s != '>')
	{
		shell->tokens[*k].data[++j] = **s;
		(*s)++;
	}
	shell->tokens[*k].data[++j] = '\0';
	return (1);
}

int	split_tokens(t_shell *shell)
{
	//int	j;
	int	k;
	//char	tmp[255];
	char	*aux;

	k = -1;
	aux = shell->input;
	while (*aux)
	{
		//j = -1;
		first_caracter_case(&aux);
		// while (*aux && *aux != '|' && *aux != '<' && *aux != '>')
		// {
		// 	tmp[++j] = *aux;
		// 	aux++;
		// }
		// tmp[++j] = '\0';
		// shell->tokens[++k].data = ft_strdup(tmp);
		if (create_token(shell, &aux, &k) == -1)
			return (-1);
		if (check_multiple_limits(&aux) == -1)
			return (-1);
		//ft_bzero(tmp, sizeof(tmp));
		if (*aux == '\0')
			break ;
	}
	return (1);
}

int	tokenize(t_shell *shell, int nbr)
{

	shell->tokens = malloc(sizeof(t_token) * nbr);
	if (!shell->tokens)
		exit(-1);
	if (split_tokens(shell) == -1)
		return (-1);
	return (1);
}

// int	main(void)
// {
// 	t_shell	shell;
// 	int	nbr_of_tokens;

// 	init_shell(&shell);
// 	shell.input = "a >> b |    ";
// 	nbr_of_tokens = count_command(shell.input);
// 	if (tokenize(&shell, nbr_of_tokens) == -1)
// 	{
// 		printf("Algum erro\n");
// 		exit(42);
// 	}
// 	printf ("%s\n", shell.tokens[0].data);
// 	int i = 0;
// 	while (i < nbr_of_tokens)
// 	{
// 		free(shell.tokens[i].data);
// 		i++;
// 	}
// 	free(shell.tokens);
// }
