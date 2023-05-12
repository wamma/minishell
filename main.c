/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:54:11 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/12 21:28:46 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
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
	
}
