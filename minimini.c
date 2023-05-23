/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:05:22 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/23 15:13:20 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

void	execute_command(char *command)
{
	char	*args[BUFFER_SIZE];
	int		arg_count;
	char	*token;
	pid_t	pid;

	arg_count = 0;
	token = strtok(command, " ");
	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

int	main(void)
{
	char	buffer[BUFFER_SIZE];

	while (1)
	{
		printf("minishell> ");

		fgets(buffer, BUFFER_SIZE, stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		if (strcmp(buffer, "exit") == 0)
			break ;
		execute_command(buffer);
	}
	return (0);
}
