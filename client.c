/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:43:32 by crobot            #+#    #+#             */
/*   Updated: 2021/09/16 16:43:37 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert(int pid, char *byte)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 8)
	{
		if ((byte[i] >> j) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				write(1, "Missing server\n", 15);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(1, "Missing server\n", 15);
		}
		j++;
		usleep(100);
	}
}

void	handler(int pid, char *str)
{
	while (*str)
	{
		convert(pid, str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Invalid arguments\n", 18);
		return (1);
	}
	handler((ft_atoi(argv[1])), argv[2]);
	return (0);
}
