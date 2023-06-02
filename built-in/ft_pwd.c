/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:22:38 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/02 18:39:02 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char	*pwd;
	int		ret;

	ret = 0;
	pwd = getcwd(0, MAX_SIZE);
	if (pwd != NULL)
	{
		printf("%s\n", pwd);
		free(pwd);
	}
}
