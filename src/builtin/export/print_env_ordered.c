/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_ordered.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:46:21 by jquicuma          #+#    #+#             */
/*   Updated: 2025/02/11 09:28:35 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_env_list(t_env_str *head)
{
	t_env_str	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->data);
		free(tmp);
	}
}

static t_env_str	*init(char **env)
{
	t_env_str	*head;
	t_env_str	*new_node;
	t_env_str	*last;
	int			i;

	if (!env || !env[0])
		return (NULL);
	head = NULL;
	last = NULL;
	i = 0;
	while (env[i])
	{
		new_node = malloc(sizeof(t_env_str));
		if (!new_node)
			return (NULL);
		new_node->data = ft_strdup(env[i]);
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
			last->next = new_node;
		last = new_node;
		i++;
	}
	return (head);
}

static void	sort_env_list(t_env_str *head)
{
	t_env_str	*current;
	t_env_str	*next_node;
	char		*temp;
	int			swapped;

	if (!head)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current->next)
		{
			next_node = current->next;
			if (ft_strcmp(current->data, next_node->data) > 0)
			{
				temp = current->data;
				current->data = next_node->data;
				next_node->data = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void	print_env_ordered(char **env)
{
	t_env_str	*env_str;
	t_env_str	*tmp_first_pos;

	env_str = init(env);
	sort_env_list(env_str);
	tmp_first_pos = env_str;
	while (env_str)
	{
		printf("%s\n", env_str->data);
		env_str = env_str->next;
	}
	free_env_list(tmp_first_pos);
}

// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	print_env_ordered(env);
// 	return (0);
// }
