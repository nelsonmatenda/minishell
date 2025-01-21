/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:02 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/20 11:46:32 by jquicuma         ###   ########.fr       */
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

int	count_env(char **str, int end, char **envp)
{
	char	*tmp;
	int		i;
	int		j;
	int		count_env;
	char	*replace;

	i = 0;
	count_env = 0;
	tmp = malloc(ft_strlen(str[0]) + 1);
	while (str[0][i])
	{
		if (str[0][i] == '$')
		{
			i++;
			j = 0;
			while (str[0][i] && str[0][i] != ' ')
				tmp[j++] = str[0][i++];
			tmp[j++] = '=';
			tmp[j] = 0;
			replace = find_env(envp, tmp);
			tmp[--j] = 0;
			tmp = ft_strjoin("$", tmp);
			if (replace != NULL)
			{
				replace_env_var(&str[0], tmp, replace);
				count_env++;
			}
		}
		i++;
	}
	return (count_env);
}

e_quote	check_quotes(const char *str, char **no_quotes_str, char **envp)
{
	char	**split_quotes;
	size_t	len;
	int		i;
	int		quotes_qtt;
	int		last_quote_pos;
	int		first_quote_pos;

	len = ft_strlen(str);
	if (len < 2)
		return (NO_QUOTE);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			first_quote_pos = i;
			last_quote_pos = ft_strrchr_pos(str, '\'');
			split_quotes = ft_split_quotes(str, '\'', &quotes_qtt);
			*no_quotes_str = join_words(split_quotes);
			//count_env(no_quotes_str, ft_strlen(*no_quotes_str), envp);
			return (NO_QUOTE);
		}
		else if (str[i] == '"')
		{
			first_quote_pos = i;
			last_quote_pos = ft_strrchr_pos(str, '"');
			split_quotes = ft_split_quotes(str, '"', &quotes_qtt);
			*no_quotes_str = join_words(split_quotes);
			count_env(no_quotes_str, ft_strlen(*no_quotes_str), envp);
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
		char *input = readline("hell$ ");
		e_quote quote = check_quotes(input, &str, envp);
		printf("%s\n", str);
	}
}

