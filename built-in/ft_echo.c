/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:25:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/27 19:54:05 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(char **argv) // echo "'"hi"'" -> 'hi' quote 처리 완료
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
