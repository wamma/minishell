/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricecha <ricecha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/06/02 22:09:43 by ricecha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*separate_single(char *original, int i, int j)
{
	char	**result;

	result = malloc(sizeof(char *) * 4);
	if (result == NULL)
		return (NULL);
	result[0] = ft_substr(original, 0, i);
	if (result[0] == NULL)
		return(모르겠음) 
	result[1] = ft_substr(original, i + 1, j - i - 1)
	if (result[1] == NULL)
		return(모르겠음)
	result[2] = ft_substr(original, j + 1, ft_strlen(original));
	if (result[2] == NULL)
		return(모르겠음)
	result[3] = NULL;
	return (result);
}

char	*separate_double(char *original, int i, int j)
{
	char	**result;

	result = malloc(sizeof(char *) * 4);
	if (result == NULL)
		return (NULL);
	result[0] = ft_substr(original, 0, i);
	if (result[0] == NULL)
		return(모르겠음) 
	result[1] = ft_substr(original, i + 1, j - i - 1)
	if (result[1] == NULL)
		return(모르겠음)
	result[2] = ft_substr(original, j + 1, ft_strlen(original));
	if (result[2] == NULL)
		return(모르겠음)
	result[3] = NULL;
	return (result);	
}

char	**separate_quote(char *original) //ex) echo "ls -l" 'dd' -> 'echo ', 'ls -l', 'NULL' , 'NULL' 
{
	int	i;
	int j;

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
			while (original[j] != '\0' && orignal[j] != '\'')
				j++;
			if (original[j] == '\'')
				return (separate_single(original, i, j));
		}
		if (original[i] == '\"')
		{
			while (original[j] != '\0' && orignal[j] != '\"')
				j++;
			if (original[j] == '\"')
				return (seperate_double(originalm i, j));
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
}