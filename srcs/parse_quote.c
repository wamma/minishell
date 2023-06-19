/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/06/19 21:57:20 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**separate_single(char *original, int i, int j)
{
	char	**result;

	result = malloc(sizeof(char *) * 4);
	if (result == NULL)
		return (NULL);
	result[0] = ft_substr(original, 0, i);
	if (result[0] == NULL)
		return (NULL);
	result[1] = ft_substr(original, i + 1, j - i - 1);
	if (result[1] == NULL)
		return (NULL);
	result[2] = ft_substr(original, j + 1, ft_strlen(original));
	if (result[2] == NULL)
		return (NULL);
	result[3] = NULL;
	return (result);
}

char	**separate_double(char *original, int i, int j)
{
	char	**result;

	result = malloc(sizeof(char *) * 4);
	if (result == NULL)
		return (NULL);
	result[0] = ft_substr(original, 0, i);
	if (result[0] == NULL)
		return (NULL);
	result[1] = ft_substr(original, i + 1, j - i - 1);
	if (result[1] == NULL)
		return (NULL);
	result[2] = ft_substr(original, j + 1, ft_strlen(original));
	if (result[2] == NULL)
		return (NULL);
	result[3] = NULL;
	return (result);
}

char	**separate_quote(char *original) //ex) echo "ls -l" 'dd' -> 'echo ', 'ls -l', 'NULL' , 'NULL'
{
	int	i;
	int	j;

	i = 0;
	while (original[i] != '\0')
	{
		while (original[i] == '\0' || original[i] != '\'' || original[i] != '\"')
			i++;
		if (original[i] == '\0')
			return (NULL);
		j = i;
		if (original[i] == '\'')
		{
			while (original[j] != '\0' && original[j] != '\'')
				j++;
			if (original[j] == '\'')
				return (separate_single(original, i, j));
		}
		if (original[i] == '\"')
		{
			while (original[j] != '\0' && original[j] != '\"')
				j++;
			if (original[j] == '\"')
				return (seperate_double(original, i, j));
		}
	}
	return (NULL);
}

/*
TOKEN_ORIGIN ex) echo "ls -l" 'dd' cs "laaa"
= TOKEN_ORIGIN TOKEN_ARGV "TOKEN_ORIGIN"
= echo         ls -l      'dd' cd "laaaa"

"TOKEN_ORIGIN"
= TOKEN_ORIGIN TOKEN_ARGV TOKEN_ORIGIN
= NULL        dd         cd "laaaa"

NULL laaaa NULL
*/

/*원래 코드
void	parse_quote(t_token *token)
{
	char	**sep;

	while (token != NULL)
	{
		if (token->type == TOKEN_ORIGIN)
		{
			sep = separate_quote(token->original);
			if (sep != NULL)
			{
				node1 = TOKEN_ORIGIN;
				node2 = TOKEN_ARGV;
			}
		}
	}
}*/

void	parse_quote(t_token *token)
{
	char	**sep;
	t_token	*node1;
	t_token	*node2;
	t_token	*new_tokens;
	t_token	*prev_token;

	new_tokens = NULL;
	prev_token = NULL;
	while (token != NULL)
	{
		if (token->type == TOKEN_ORIGIN)
		{
			sep = separate_quote(token->original);
			if (sep != NULL)
			{
				// 분리된 서브스트링을 처리합니다
				// ex) echo "ls -l" 'dd' -> 'echo ', 'ls -l', 'NULL', 'NULL'

				// 첫 번째 서브스트링은 원래 토큰의 역할을 유지합니다 (TOKEN_ORIGIN)
				node1 = create_node(TOKEN_ORIGIN, sep[0], NULL);
				if (new_tokens == NULL)
				{
					new_tokens = node1;
					prev_token = node1;
				}
				else
				{
					prev_token->next = node1;
					prev_token = node1;
				}

				// 두 번째 서브스트링은 ARGV 역할을 갖습니다(TOKEN_ARGV)
				node2 = create_node(TOKEN_ARGV, sep[1], NULL);
				prev_token->next = node2;
				prev_token = node2;

				// 필요에 따라 추가 서브스트링을 처리합니다
			}
		}
		token = token->next;
	}
}