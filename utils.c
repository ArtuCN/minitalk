/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:47:29 by aconti            #+#    #+#             */
/*   Updated: 2024/03/15 11:23:18 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_num(int pid, int n)
{
	int		i;
	char	bit;

	i = (sizeof(int) * 8);
	while (--i >= 0)
	{
		bit = (n >> i) & 1;
		send_bit(pid, bit, 1);
	}
}

void	config(struct sigaction *act)
{
	if (sigaction(SIGUSR1, act, NULL) < 0)
		exit(0);
	if (sigaction(SIGUSR2, act, NULL) < 0)
		exit(0);
}

void	send_char(int pid, char c)
{
	int		i;
	char	bit;

	i = 8;
	while (--i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit(pid, bit, 1);
	}
}

void	send_bit(int pid, int bit, int wait)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(0);
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(0);
	}
	if (wait != 0)
		pause();
}
