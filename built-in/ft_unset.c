/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:41:38 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/27 21:42:26 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(argv[i][0]) || !ft_isalpha(argv[i][0]))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", argv[i]);
			g_glob.exit_code = 1;
		}
		else
			ft_unset_env(argv[i]);
		i++;
	}
}