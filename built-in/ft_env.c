/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:50:13 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/27 16:45:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_list *list)
{
	t_env	*cur;

	cur = list->head->next;
	while (cur != list->tail)
	{
		printf("%s=%s\n", cur->key, cur->value);
		cur = cur->next;
	}
	return (0);
}
