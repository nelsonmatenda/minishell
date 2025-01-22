/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes_list_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:11 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 12:38:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



// char *join_strings(char **array, size_t size) {
//     if (!array || size == 0)
//         return NULL;

//     char *result = strdup(array[0]); // Copia a primeira string
//     if (!result)
//         return NULL;

//     for (size_t i = 1; i < size; i++) {
//         char *temp = ft_strjoin(result, array[i]); // Junta a string atual
//         free(result); // Libera a string antiga
//         if (!temp)
//             return NULL; // Retorna NULL em caso de erro
//         result = temp; // Atualiza o resultado
//     }

//     return result;
// }

char	*remove_quotes_expand_env_var(char *input, char **envp)
{
	t_quote	*quote_list;
	t_quote	*tmp_list_free;
	char	*tmp;
	char	*output;

	quote_list = expand_env_var(input, envp);
	tmp_list_free = quote_list;
	output = NULL;
	if (quote_list)
		output = ft_strdup(quote_list->data);
	quote_list = quote_list->next;
	while (quote_list)
	{
		tmp = ft_strjoin(output, quote_list->data);
		free(output);
		output = tmp;
		quote_list = quote_list->next;
	}
	free_quote_list(tmp_list_free);
	return (output);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*str;

// 	(void)argc;
// 	(void)argv;
// 	(void)envp;
// 	str = ft_strdup("echo  \"\'$USER\' $USER $USER\"$USER  $PATH  pure \'\"world\"\' \"cruel");
// 	//t_quote *list = expand_env_var(str, envp);
// 	// for (t_quote *lst = list; lst; lst = lst->next)
// 	// 	printf("|%s|\n", lst->data);
// 	// free_quote_list(list);
// 	char *str2 = remove_quotes_expand_env_var(str, envp);
// 	printf("%s\n\n", str2);
// 	free(str);
// 	free(str2);
// 	return (0);
// }
