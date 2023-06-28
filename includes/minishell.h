/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:54:24 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/28 15:30:42 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// 원래 토큰
# define TOKEN_ORIGIN 11
// 기본 토큰
# define TOKEN_ARGV 22
// 공백 토큰
# define TOKEN_SPACE 33
// 파이프라인 토큰
# define TOKEN_PIPELINE 44
// 리다이렉션 토큰 >
# define TOKEN_R 55
// 리다이렉션 토큰 >>
# define TOKEN_RR 66
// 리다이렉션 토큰 <
# define TOKEN_L 77
// 리다이렉션 토큰 <<
# define TOKEN_LL 88

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"

typedef struct s_token
{
	int				type; // 토큰의 타입
	char			*origin; // 원래 토큰
	char			*str; // 토큰의 타입에 맞는 문자열
	struct s_token	*next; // 다음 토큰을 가리키는 포인터
}	t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
	struct s_env	*sorted_next;
}	t_env;

typedef struct s_list
{
	t_env	*head;
	t_env	*tail;
}	t_list;

typedef struct s_cmd
{
	int		flag;
	char	**cmdline;
	char	quote;
}	t_cmd;

typedef struct s_data
{
	t_list	*lstlast;
	t_cmd	*cmd;
	char	*buff;
}	t_data;

typedef struct s_glob // 전역변수 구조체
{
	t_list	*list;
	t_env	*head;
	int		exit_code;
}	t_glob;

t_glob	g_glob;

#endif