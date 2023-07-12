/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:54:11 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/05 23:17:55 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_readline(int signum)
{
	char	*str;

	while (1)
	{
		str = readline("prompt : ");
		if (str)
			printf("%s\n", str);
		else
			break ;
		add_history(str);
		free(str);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd_list	*cmd_lst;
	char		*str;

	(void)argc;
	(void)argv;
	print_fist();
}
