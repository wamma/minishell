/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:17 by seocha            #+#    #+#             */
/*   Updated: 2023/05/25 17:46:51 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

static char	arr_argv(const char *str)
{
	int		cnt;
	char	*word;

	cnt = 0;
	if (str[cnt] && str[cnt] == '\'')
		while (str[cnt] && str[cnt + 1] != '\'')
			cnt++;
	else if (str[cnt] && str[cnt] == '\"')
		while (str[cnt] && str[cnt + 1] != '\"')
			cnt++;
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

static char	arr_chunk(const char *str)
{
	int		cnt;
	char	*word;

	cnt = 0;
	if (str[cnt] && str[cnt] == '\'')
		while (str[cnt] && str[cnt + 1] != '\'')
			cnt++;
	else if (str[cnt] && str[cnt] == '\"')
		while (str[cnt] && str[cnt + 1] != '\"')
			cnt++; 
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

static void	push_quote(char const **s)
{
	if (*(s[0]) == '\'')
		while (*(s[0]) && (*(s[0]) + 1) != '\'')
			s[0]++;
	else if (*(s[0]) == '\"')
		while (*(s[0]) && (*(s[0]) + 1) != '\"')
			s[0]++;
}

void	parse_quote(t_token *token, char const *s)
{
	int		i;
	t_token	*node;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_quote(s[i]))
			i++;
		if (s[i] == '\0')
			break ;
		node = new_node(TOKEN_CHUNK, ft_arr(s), token);
		node = new_node(TOKEN_ARGV, arr_argv(s), token);
		token = node;
		push_quote(&s);
	}
}
