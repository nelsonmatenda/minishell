/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:18:02 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/19 22:33:03 by jquicuma         ###   ########.fr       */
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
	tmp = malloc(ft_strlen(*str) + 1);
	char	*str2 = *str;
	//printf("%s\n", *str);
	while (str2[i])
	{
		if (str2[i] == '$')
		{
			i++;
			j = 0;
			while (str2[i] && str2[i] != ' ')
				tmp[j++] = str2[i++];
			tmp[j] = 0;
			replace = find_env(envp, tmp); 
			if (replace != NULL)
			{
				replace_env_var(&str2, tmp, replace);
				str2 = str2 + 2;
				count_env++;
			}
		}
		i++;
	}
	printf("%s\n\n", str2);
	return (count_env);
}

e_quote	check_quotes(const char *str, char **no_quotes_str, char **envp)
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
			count_env(&no_quote_str, ft_strlen(no_quote_str), envp);
			//replace_env_var(&no_quote_str + i, "$0", "Kicuma");
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
		//int i = count_env(&input, ft_strlen(input), envp);
		//printf("%d\n%s\n\n", i, input);
		//input = ft_strjoin(input, "=");
		//printf("%s\n", find_env(envp, input));
		e_quote quote = check_quotes(input, &str, envp);
		//if (quote != NO_QUOTE && quote != INVALID_QUOTE)
		//	printf("%s\n", str);
		//else if (quote == INVALID_QUOTE)
		//	perror("quotes");
	}
}

