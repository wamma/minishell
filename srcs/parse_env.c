/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:14:56 by seocha            #+#    #+#             */
/*   Updated: 2023/06/21 22:02:47 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

// "" 묶인 애들이 들어옴, 하지만 ""이거는 떼고
char	*parse_env_double_quote(char *str)
{
	int		i;
	int		j;
	char	*result;
	char	*env_str;
	char	*no_env_str;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			j = i;
			no_env_str = ft_substr(str, j - i, i - j);
			while (!is_space(str[i + 1]) && (str[i + 1] != '\0'))
				i++;
			env_str = ft_substr(str, j + 1, i - j);
			result = ft_strjoin(no_env_str, env_process(env_str));
			// env_process: 환경변수 있는 애들 환경변수 실제 값 갖고오기, quote 날리기(single, double 둘 다)
			free(env_str);
			free(no_env_str);
		}
		i++;
	}
}

// quote 없는 애들 환경변수 처리
void	parse_env(t_token *token)
{
	t_token	*copy;

	while (token != NULL)
	{
		copy = token;
		if (copy->next != NULL)
			
	}
}
