/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:14:56 by seocha            #+#    #+#             */
/*   Updated: 2023/06/26 15:23:36 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 환경변수 안에 space 가 없는 애들 ex)abc=hello
void	parse_env_no_space(t_token *token, char *str)
{
	int		i;
	char	**sep;
	t_token	*new_token;

	i = 0;
	while (str[i] != '\0')
	{
		// 환경 변수 이름이 잘못되었을 때
		// 환경 변수 해석 없이 들어온 문자열 그대로의 값을 ORIGIN으로 넘김
		if (!is_env(str[i]))
		{
			create_free_token(token, str, TOKEN_ORIGIN);
			return ;
		}
		i++;
	}
	sep = ft_split_space(env_process(str));
	while (sep[i] != NULL)
	{
		create_free_token(token, sep[i], TOKEN_ARGV);
		if (i != ft_strlen2(sep) - 1)
			create_free_token(token, "", TOKEN_SPACE);
		i++;
	}
}

// 환경변수 안에 space 가 있는 애들 ex)abc="ls -l"
void	parse_env_space(t_token *token, char *before_space, char *after_space)
{
	int		i;
	char	**sep;

	i = 0;
	while (before_space[i] != '\0')
	{
		// $? 들어오는 애들 처리
		if (before_space[0] != '?')
		{
			// env_question_process : $? 해석한 값 갖고오기
			create_free_token(token, env_question_process(token), TOKEN_ARGV);
			return ;
		}
		// 환경 변수 이름이 잘못되었을 때
		// 환경 변수 해석 없이 들어온 문자열 그대로의 값을 ORIGIN으로 넘김
		if (!is_env(before_space[i]) || ft_isalnum(before_space[0]))
		{
			create_free_token(token, before_space, TOKEN_ORIGIN);
			return ;
		}
		i++;
	}
	i = 0;
	sep = ft_split_space(env_process(before_space));
	while (sep[i] != NULL)
	{
		create_free_token(token, sep[i], TOKEN_ARGV);
		if (i != ft_strlen2(sep) - 1)
			create_free_token(token, "", TOKEN_SPACE);
		i++;
	}
	// after_space 문자열은 그냥 바로 TOKEN_ORIGIN으로 만들어서 넣어버리기
	create_free_token(token, after_space, TOKEN_ORIGIN);
}

// quote 없이 들어오는 환경변수 처리: argv + space + argv
void	parse_env_no_quote(t_token *token, char *str)
{
	int		i;
	int		j;
	char	**sep;

	i = 0;
	if (str == NULL || token == NULL)
		return (NULL);
	sep = ft_split(str, '$');
	while (sep[i] != NULL)
	{
		if (i == 0)
			token->origin = sep[0];
		else
		{
			j = 0;
			while (!is_space(sep[i][j]))
				j++;
			if (sep[i][j] == '\0')
				parse_env_no_space(token, sep[i]);
			else
				parse_env_space(token, ft_substr(sep[i], 0, j), \
				ft_substr(sep[i], j, ft_strlen(sep[i]) - j - 2));
		}
	}
}

// quote 없는 애들 환경변수 처리
void	parse_env(t_token *token)
{
	t_token	*copy;

	while (token != NULL)
	{
		copy = token->next;
		if (copy->type == TOKEN_ORIGIN)
			parse_env_no_quote(token, copy->origin);
		token = copy;
	}
}
