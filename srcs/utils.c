/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:50:50 by seocha            #+#    #+#             */
/*   Updated: 2023/06/23 17:31:07 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_env(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || \
	(c >= 'a' && c <= 'z') || c == '_')
		return (1);
	return (0);
}

size_t	ft_strlen2(const char **s)
{
	size_t	cnt;

	cnt = 0;
	while (*s != NULL)
	{
		cnt++;
		s++;
	}
	return (cnt);
}
