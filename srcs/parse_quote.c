/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/06/21 21:55:42 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
TOKEN_ORIGIN ex) echo "ls -l" 'dd' cs "laaa"
= TOKEN_ORIGIN TOKEN_ARGV "TOKEN_ORIGIN"
= echo         ls -l      'dd' cd "laaaa"

"TOKEN_ORIGIN"
= TOKEN_ORIGIN TOKEN_ARGV TOKEN_ORIGIN
= NULL        dd         cd "laaaa"

NULL laaaa NULL
*/

void	*free_result(char **result)
{
	int	i;

	i = 0;
	if (result == NULL)
		return (NULL);
	while (i < 3 && result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
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
				new_token = create_token(token, sep[1], 1);
				add_token(&token, new_token);
				free(new_token);
				new_token = create_token(token, sep[2], 2);
				add_token(&token, new_token);
				free(new_token);
				token->origin = sep[0];
			}
		}
		if (token != NULL)
			token = token->next;
	}
}
