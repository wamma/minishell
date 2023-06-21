/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:57:25 by seocha            #+#    #+#             */
/*   Updated: 2023/06/21 20:29:37 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = 0;
	token->origin = NULL;
	token->str = NULL;
	token->next = NULL;
}

t_token	*create_token(t_token *token, char *str, int i)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	if (i == 2)
		new_node->type = TOKEN_ORIGIN;
	else
		new_node->type = TOKEN_ARGV;
	new_node->origin = str;
	new_node->next = NULL;
	return (new_node);
}

void	add_token(t_token **token, t_token *new_token)
{
	t_token	*copy_token;
	t_token	*curr;

	if (token == NULL || new_token == NULL)
		return ;
	copy_token = (t_token *)malloc(sizeof(t_token));
	if (copy_token == NULL)
	{
		free(copy_token);
		return ;
	}
	copy_token->type = new_token->type;
	copy_token->origin = new_token->origin;
	copy_token->next = NULL;
	if (*token == NULL)
		*token = copy_token;
	else
	{
		curr = *token;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = copy_token;
	}
	free(copy_token);
	free(curr);
}
