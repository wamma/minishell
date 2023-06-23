/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:43:43 by seocha            #+#    #+#             */
/*   Updated: 2023/06/23 20:00:46 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
