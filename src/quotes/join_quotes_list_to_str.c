/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes_list_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:11 by jquicuma          #+#    #+#             */
/*   Updated: 2025/01/22 11:35:56 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*join_quotes_list_to_str(t_quotes **list)
{

}

int	main(int argc, char **argv, char **envp)
{
	char	*str;

	(void)argc;
	(void)argv;
	(void)envp;
	str = ft_strdup("echo  \"\'$USER\' $USER $PATH\"my  $PATH  pure \'\"world\"\' \"cruel");
	t_quote *list = expand_env_var(str, envp);
	for (t_quote *lst = list; lst; lst = lst->next)
		printf("|%s|\n", lst->data);
	free_quote_list(list);
	free(str);
	return (0);
}
