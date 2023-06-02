/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:25:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/25 16:02:19 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <string.h>

void	ft_echo(char **argv)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (argv[i] && strcmp(argv[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	if (newline)
		printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (strcmp(argv[1], "echo") == 0)
		{
			if (argc > 2)
				ft_echo(argv + 1);
			else
				printf("\n");
		}
		else
			printf("command not found");
	}
	else
		printf("\n");
	return (0);
}
