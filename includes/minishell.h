/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocha <seocha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:54:24 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/25 17:29:56 by seocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TOKEN_CHUNK 0
# define TOKEN_ARGV 1
# define TOKEN_SPACE 2
# define TOKEN_PIPELINE 3
# define TOKEN_R 4
# define TOKEN_RR 5
# define TOKEN_L 6
# define TOKEN_LL 7

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"

typedef struct s_token
{
	int				type;
	char			*original; // quote 짝 체크
	char			*str; // quote를 제외한 문자열, 환경변수를 해석하기 전 문자열. $ 유무 체크
	struct s_token	*next;
}	t_token;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
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

#endif