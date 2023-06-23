/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:55:14 by seocha            #+#    #+#             */
/*   Updated: 2023/06/23 19:55:36 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_process(char *env_str)
{
	char	*env_value;

	env_value = getenv(env_str);
	if (env_value == NULL)
		return (ft_strdup("")); // 메모리 free를 위해
	else if (env_value != NULL)
		return (ft_strdup(env_value));
	return (NULL);
}
