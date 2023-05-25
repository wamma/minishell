/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:43:27 by hyungjup          #+#    #+#             */
/*   Updated: 2023/05/12 19:49:37 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t	target_pid = atoi(argv[1]);

	int	result = kill(target_pid, SIGKILL);
	if (result == -1)
	{
		perror("Error killing process");
		return (1);
	}
	printf("Process %d killed successful\n", target_pid);
	return (0);
}
