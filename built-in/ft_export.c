/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:56:02 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/23 18:12:57 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <string.h>

static int	print_non_argv(t_list *list)
{
	t_list	*cur;

	cur = list->head->next;
	while ()
}

int	ft_export(char **argv, t_list *list)
{
	if (argv[1] == NULL)
		return (print_non_argv(list));
}