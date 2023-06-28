/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:43:43 by seocha            #+#    #+#             */
/*   Updated: 2023/06/27 20:33:47 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_space_split(t_token *token, char *origin)
{
	int		i;
	int		j;
	char	**sep;

	i = 0;
	if (origin == NULL || token == NULL)
		return (NULL);
	sep = ft_split_space(origin);
	while (sep[i] != NULL)
	{
		create_free_token(token, sep[i], TOKEN_ORIGIN);
		if (i != ft_strlen2(sep) - 1)
			create_free_token(token, "", TOKEN_SPACE);
		i++;
	}
}

void	parse_space(t_token *token)
{
	t_token	*copy;

	while (token != NULL)
	{
		copy = token->next;
		if (copy->type == TOKEN_ORIGIN)
			parse_space_split(token, copy->origin);
		token = copy;
	}
}
