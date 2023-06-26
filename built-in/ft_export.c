/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:56:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/26 23:18:20 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <string.h>

static int	print_no_argv(t_list *list)
{
	t_list	*cur;

	cur = list->head->next;
	while (cur != list->tail)
	{
		printf("declare -x %s=%s\n", cur->key, cur->value);
		cur = cur->next;
	}
	return (0);
}

static int	check_valid_key(char *str) // str -> a="ls -l"
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) == 1) // 숫자로 시작하는 키는 안됨
		return (1);
	else if (str[0] == '=') // =로 시작하는 키는 안됨
		return (1);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_') // 알파벳, 숫자, _ 가 아니면 안됨
			return (1);
		i++;
	}
	if (str[i] != '=') // =가 없으면 안됨, str[i]인가 str[i + 1]인가?
		return (1);
	return (0);
}

t_list	*find_key_in_list(t_list *list, char *key)
{
	t_list	*cur;

	cur = list->head->next;
	while (cur != list->tail)
	{
		if (ft_strcmp(cur->key, key) == 0)
			return (cur);
		cur = cur->next;
	}
	return (0);
}

static void	free_value(char **value)
{
	free(value[0]);
	free(value[1]);
	free(value);
}

int	ft_export(char **argv, t_list *list) // key만 있어도 됨, key=value도 됨
{
	int		key;
	int		i;
	char	**value; // key, value를 저장한 문자열 배열을 가리키기 때문에 이중 포인터다.

	if (argv[1] == NULL)
		return (print_no_argv(list));
	key = check_valid_key(argv[1]); // export a="ls -l"
	if (key == 1)
	{
		printf("bash: export: `%s': not a valid identifier\n", argv[1]);
		return (1);
	}
	else if (key == 0)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			value = ft_split(argv[i], '='); // value[0] = a, value[1] = "ls -l"
			if (find_key_in_list(list, value[0]) != 0) // 기존 env list에 key가 있으면
				update_list(); // 기존 env list에 있는 값에 value[1]을 덮어씌움
			else
				ft_lstadd_back(기존 env list, ft_lstnew(value[0], value[1]));
			free_value(value);
			i++;
		}
	}
	return (0);
}