/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:54:30 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/19 18:08:58 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/minishell.h"


static size_t calculate_result_len(const char *str, const char *env_var,\
									size_t env_var_len, size_t env_value_len)
{
    size_t len = 0;
    size_t i = 0;
    int replaced = 0;

    while (str[i])
    {
        if (ft_strncmp(&str[i], env_var, env_var_len) == 0 && !replaced)
        {
            len += env_value_len;
            i += env_var_len;
            replaced = 1;
        }
        else
        {
            len++;
            i++;
        }
    }
    return len;
}

static void copy_result(char *result, const char *str, const char *env_var, \
						size_t env_var_len, const char *env_value)
{
    size_t i = 0;
    size_t j = 0;
    int replaced = 0;

    while (str[i])
    {
        if (ft_strncmp(&str[i], env_var, env_var_len) == 0 && !replaced)
        {
            ft_strlcpy(&result[j], env_value, ft_strlen(env_value) + 1);
            j += ft_strlen(env_value);
            i += env_var_len;
            replaced = 1;
        }
        else
        {
            result[j] = str[i];
            j++;
            i++;
        }
    }
    result[j] = '\0';
}

void replace_env_var(char **str, const char *env_var,\
											const char *env_value)
{
    size_t env_var_len = ft_strlen(env_var);
    size_t env_value_len = ft_strlen(env_value);
    size_t result_len = calculate_result_len(*str, env_var, env_var_len, env_value_len);
    char *result = (char *)malloc(result_len + 1);

    if (!result)
    {
        *str = NULL;
        return;
    }

    copy_result(result, *str, env_var, env_var_len, env_value);
    free(*str);
    *str = result;
}


// int main(void)
// {
//     char *str = ft_strdup("Dentro da Variavel de ambiente do Path encontramos=$PATH dessa maneira");
//     const char *env_value = "KICUMA";

//     // Substitui a primeira ocorrência de $PATH pelo valor de env_value
//     ft_substitute_env_var_first_occurence(&str, "$PATH", env_value);

//     if (str)
//     {
//         printf("Nova string: %s\n", str);
//         free(str); // Libera a memória alocada
//     }
//     else
//     {
//         printf("Erro ao alocar memória.\n");
//     }

//     return 0;
// }
