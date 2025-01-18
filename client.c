/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:27 by husarpka          #+#    #+#             */
/*   Updated: 2025/01/18 21:14:39 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

void	ft_hand(int pid, char a)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (a >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc < 3)
	{
		write (1, "You entered an incomplete argument", 34);
		return (1);
	}
	else if (argc > 3)
	{
		write (1, "you entered too many arguments", 30);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_hand(pid, argv[2][i++]);
	}
	return (0);
}
