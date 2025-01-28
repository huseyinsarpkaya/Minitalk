/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:27:56 by husarpka          #+#    #+#             */
/*   Updated: 2025/01/28 18:06:00 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void	ft_res(int sig)
{
	if (sig == SIGUSR1)
		write(1, "successful", 10);
}

void	send_bits(int pid, char a)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (a >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "you entered an incorrect argument", 33);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		write(1, "pid error", 9);
		return (1);
	}
	signal(SIGUSR1, ft_res);
	while (argv[2][i])
		send_bits(pid, argv[2][i++]);
	send_bits(pid, '\0');
	return (0);
}
