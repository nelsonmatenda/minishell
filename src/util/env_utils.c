/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:02 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/19 18:27:39 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t calculate_total_length(char **words)
{
    size_t total_length = 0;
    int i = 0;

    while (words[i])
    {
        total_length += ft_strlen(words[i]);
        i++;
    }
    total_length += (i > 1) ? (i - 1) : 0;
    return total_length;
}

char *join_words(char **words)
{
    size_t total_length = calculate_total_length(words);
    char *result = malloc(total_length + 1); // +1 para o terminador nulo
    int i = 0;
    size_t pos = 0;

    if (!result)
        return NULL;

    while (words[i])
    {
        size_t len = strlen(words[i]);
        ft_memcpy(result + pos, words[i], len);
        pos += len;
        i++;
    }
    result[pos] = '\0'; // Finaliza a string
    return result;
}

static char	*find_env(char **envp, char *env_var)
{
	char	*tmp;
	int	i;
	i = 0;
	while (envp[i] != NULL)
	{
		tmp = envp[i];
		if (!ft_strncmp(tmp, env_var, ft_strlen(env_var)))
			return (tmp + ft_strlen(env_var));
		i++;
	}
	return (NULL);
}

e_quote	check_quotes(const char *str, char **no_quotes_str)
{
	char	**split_quotes;
	char	*no_quote_str;
	size_t	len;
	int		i;
	int		quotes_qtt;
	int		last_quote_pos;
	int		first_quote_pos;

	len = ft_strlen(str);
	if (len < 2)
		return (NO_QUOTE);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\'')
		{
			first_quote_pos = i;
			last_quote_pos = ft_strrchr_pos(str, '\'');
			split_quotes = ft_split_quotes(str, '\'', &quotes_qtt);
			no_quote_str = join_words(split_quotes);
			replace_env_var(&no_quote_str + i, "$0", "Kicuma");
			printf("%s\n\n", no_quote_str);
			return (NO_QUOTE);
		}
		if (str[i] == '"')
		{
			last_quote_pos = ft_strrchr_pos(str, '"');
			split_quotes = ft_split_quotes(str, '"', &quotes_qtt);
			no_quote_str = join_words(split_quotes);
			replace_env_var(&no_quote_str + i, "$0", "Kicuma");
			printf("%s\n\n", no_quote_str);
			while (str[i])
				i++;
			return (NO_QUOTE);
		}
		i++;
	}
	return (NO_QUOTE);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;

	while (true)
	{
		char *input = readline("Digite Alguma coisa: ");
		//input = ft_strjoin(input, "=");
		//printf("%s\n", find_env(envp, input));
		e_quote quote = check_quotes(input, &str);
		//if (quote != NO_QUOTE && quote != INVALID_QUOTE)
		//	printf("%s\n", str);
		//else if (quote == INVALID_QUOTE)
		//	perror("quotes");
	}
}

