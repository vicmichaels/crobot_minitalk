/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crobot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:43:51 by crobot            #+#    #+#             */
/*   Updated: 2021/09/16 16:43:56 by crobot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)siginfo;
	(void)unused;
	if (signum == SIGUSR1)
		ascii += 1 << power;
	power += 1;
	if (power == 8)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server's PID: ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if ((sigaction(SIGUSR1, &sa, 0)) < 0)
		write(1, "Error\n", 6);
	if ((sigaction(SIGUSR2, &sa, 0)) < 0)
		write(1, "Error\n", 6);
	while (1)
		pause();
	return (0);
}
