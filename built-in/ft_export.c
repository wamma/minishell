/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:56:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/25 17:53:46 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <string.h>

void	print_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
}

void	set_env(char **envp, char *name, char *value)
{
	char	*env_var;
	int		i;
	int		j;
	int		k;

	env_var = malloc(strlen(name) + strlen(value) + 2); //"=" + null 문자까지 하기 위해 +2
	if (!env_var)
	{
		printf("Memory allocation failed\n");
		return ;
	}
	i = 0;
	while (i < strlen(name))
	{
		env_var[i] = name[i];
		i++;
	}
	env_var[i] = '=';
	j = 0;
	while (j < strlen(value))
	{
		env_var[i + j + 1] = value[j];
		j++;
	}
	env_var[i + j + 1] = '\0';
	k = 0;
	while (envp[k])
	{
		if (strncmp(envp[k], name, strlen(name)) == 0 && envp[k][strlen(name)] == '=')
		{
			free(envp[k]);
			envp[k] = env_var;
			return ;
		}
		k++;
	}
	envp[k] = env_var;
	envp[k + 1] = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*name;
	char	*value;

	name = strtok(argv[2], "=");
	value = strtok(NULL, "=");
	if (argc >= 2)
	{
		if (strcmp(argv[1], "export") == 0)
		{
			if (argc >= 3)
			{
				if (name != NULL && value != NULL)
					set_env(envp, name, value);
				else
					printf("Error: Export Command");
			}
			else
				print_env(envp);
		}
		else
			printf("Command not found");
	}
	else
		printf("Usage export command");
	return (0);
}
