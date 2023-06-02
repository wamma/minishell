/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:50:13 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/02 19:00:28 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", *envp);
		i++;
	}
}

int	main(int argc, char* argv[], char* envp[])
{
	char	**env;

	env = envp;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
