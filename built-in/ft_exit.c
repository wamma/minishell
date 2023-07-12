/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:44:45 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/30 20:25:58 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_exit(char **argv)
{
	int	i;

	i = 0;
	if (argv[1] == NULL)
	{
		printf("exit\n");
		g_glob.exit_code = 0;
		return (0);
	}
	else if (argv[1] != NULL)
	{
		if (argv[1][0] == '-')
			i++;
		while (argv[1][i] != '\0')
		{
			if (ft_isdigit(argv[1][i]) == 0)
			{
				printf("exit\n");
				printf("minishell: exit: %s: numeric argument required\n", argv[1]);
				g_glob.exit_code = 255;
				return (255);
			}
			i++;
		}
			g_glob.exit_code = ft_atoi(argv[1] + 256);
			return (g_glob.exit_code);
	}
}
