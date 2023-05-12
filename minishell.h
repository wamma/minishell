/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:54:24 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/12 21:25:33 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

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