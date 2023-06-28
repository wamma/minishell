/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:38:45 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/28 20:01:23 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_set_env(t_list *list, char *key, char *value)
{
	t_env	*env;
	t_env	*temp;

	temp = list;
	while (temp)
	{
		env = temp->content;
		if (strcmp(env->key, key) == 0)
		{
			free(env->value);
			env->value = ft_strdup(value);
			return ;
		}
		temp = temp->next;
	}
	env = malloc(sizeof(t_env));
	env->key = ft_strdup(key);
	env->value = ft_strdup(value);
	ft_lstadd_back(&list, ft_lstnew(env));
}

int	ft_cd(char **argv, t_list *list) // cd ., cd .., cd /절대경로
{
	char	*path;
	char	*temp;

	if (argv[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			printf("minishell: cd: HOME not set\n");
			return (1);
		}
	}
	else
		path = argv[1];
	if (chdir(path) == -1)
	{
		printf("minishell: cd: %s: %s\n", path, strerror(errno)); // stderr로 출력 putstr_fd
		return (1);
	}
	temp = getcwd(NULL, 0);
	ft_set_env(list, "PWD", temp); // 환경변수 PWD에 현재 디렉토리 경로 저장
	free(temp);
	return (0);
}
