/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/06/23 19:57:03 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
			// env_process: 환경변수 있는 애들 환경변수 실제 값 갖고오기)
			free(env_str);
			free(no_env_str);
		}
		i++;
	}
	return (result);
}

char	**separate_single_double(char *origin, int i, int j, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * 4);
	if (result == NULL)
		return (NULL);
	result[0] = ft_substr(origin, 0, i);
	if (result[0] == NULL)
		return (free_result(result));
	result[1] = ft_substr(origin, i + 1, j - i - 1);
	if (c == "\"")
		result[1] = parse_env_double_quote(result[1]); // ARGV는 그냥 ARGV ORIGIN애들을 처리
	if (result[1] == NULL)
		return (free_result(result));
	result[2] = ft_substr(origin, j + 1, ft_strlen(origin));
	if (result[2] == NULL)
		return (free_result(result));
	result[3] = NULL;
	return (result);
}

//ex) echo "ls -l" 'dd' -> 'echo ', 'ls -l', 'NULL' , 'NULL'
char	**separate_quote(char *origin)
{
	int	i;
	int	j;

	i = -1;
	while (origin[++i] == '\0' || origin[i] != '\'' || origin[i] != '\"')
		;
	if (origin[i] == '\0')
		return (NULL);
	j = i;
	if (origin[i] == '\'')
	{
		while (origin[++j] != '\0' && origin[j] != '\'')
			;
		if (origin[j] == '\'')
			return (separate_single_double(origin, i, j, origin[j]));
	}
	if (origin[i] == '\"')
	{
		while (origin[++j] != '\0' && origin[j] != '\"')
			;
		if (origin[j] == '\"')
			return (seperate_single_double(origin, i, j, origin[j]));
	}
	return (NULL);
}

void	parse_quote(t_token *token)
{
	int		i;
	char	**sep;
	t_token	*new_token;

	while (token != NULL)
	{
		i = 0;
		if (token->type == TOKEN_ORIGIN)
		{
			sep = separate_quote(token->origin);
			if (sep != NULL)
			{
				new_token = create_token(token, sep[1], TOKEN_ARGV);
				add_token(&token, new_token);
				free(new_token);
				new_token = create_token(token, sep[2], TOKEN_ORIGIN);
				add_token(&token, new_token);
				free(new_token);
				token->origin = sep[0];
			}
		}
		if (token != NULL)
			token = token->next;
	}
}
