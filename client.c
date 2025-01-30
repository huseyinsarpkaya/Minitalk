/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:27 by husarpka          #+#    #+#             */
/*   Updated: 2025/01/30 16:06:21 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

volatile int	g_ack = 0;

static void	ft_res(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

static void	ft_hand(int pid, char a)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		g_ack = 0;
		if (a >> bit & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (!g_ack)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write (1, "you have entered the wrong argument", 35);
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
		ft_hand(pid, argv[2][i++]);
	return (0);
}
