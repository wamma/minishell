/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricecha <ricecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:54:11 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/02 22:09:45 by ricecha          ###   ########.fr       */
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
	
}
