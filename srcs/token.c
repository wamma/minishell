/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricecha <ricecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:57:25 by seocha            #+#    #+#             */
/*   Updated: 2023/06/02 22:21:57 by ricecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	init_token(void)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token != NULL)
		return (NULL);
	token->type = 0;
	token->original = NULL;
	token->str = NULL;
	token->next = NULL;
}

t_token	*create_node(int type, char *original, t_token *node)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->type = type;
	new_node->original = original;
	node->next = new_node;
	return (new_node);
}
