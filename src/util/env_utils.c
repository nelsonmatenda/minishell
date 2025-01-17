/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:02 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/17 16:27:47 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*remove_quotes(char *input, int end_pos)
{
	char	*output;

	output = ft_strdup(&input[1]);
	output[end_pos - 1] = '\0';
	return (output);
}

e_quote	check_quotes(const char *str, char **no_quotes_str)
{
	size_t	len;
	int		i;
	int		quotes_pos;

	len = ft_strlen(str);
	if (len < 2)
		return (NO_QUOTE);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\'')
		{
			quotes_pos = ft_strrchr_pos(str, '\'');
			if (quotes_pos == NO_FOUND || quotes_pos == i)
				return (INVALID_QUOTE);
			else
			{
				*no_quotes_str = remove_quotes((char *)&str[i], quotes_pos - i);
				return(SINGLE_QUOTE);
			}
		}
		if (str[i] == '"')
		{
			quotes_pos = ft_strrchr_pos(str, '"');
			if (quotes_pos == NO_FOUND || quotes_pos == i)
				return (INVALID_QUOTE);
			else
			{
				*no_quotes_str = remove_quotes((char *)&str[i], quotes_pos - i);
				return(SINGLE_QUOTE);
			}
		}
		i++;
	}
	return (NO_QUOTE);
}

int	main(int ac, char **av)
{
	char	*str;

	while (true)
	{
		char *input = readline("Digite Alguma coisa: ");
		e_quote quote = check_quotes(input, &str);
		if (quote != NO_QUOTE && quote != INVALID_QUOTE)
			printf("%s\n", str);
		else if (quote == INVALID_QUOTE)
			perror("quotes");
	}
}
