/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:30:40 by aconti            #+#    #+#             */
/*   Updated: 2024/03/25 17:37:20 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	i = -1;
	while (av[1][++i])
	{
		if (!ft_strchr("0123456789", av[1][i]))
			return (1);
	}
	return (0);
}

void	send_str(int pid, char *str)
{
	int	i;

	i = -1;
	send_num(pid, ft_strlen(str));
	ft_putstr_fd("\033[0;34m", 1);
	ft_putstr_fd("Sent length\n", 1);
	while (str[++i] != '\0')
		send_char(pid, str[i]);
	ft_putstr_fd("\033[0;34m", 1);
	ft_putstr_fd("Sent string\n", 1);
	send_char(pid, '\0');
}

void	client_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
	{
		write(1, "\033[0;31m", 7);
		ft_putstr_fd("Signal receive from server: ", 1);
		write(1, "\033[0;32m", 7);
		ft_putnbr_fd(info->si_pid, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (sig == SIGUSR2)
	{
		write(1, "\033[0;34m", 7);
		ft_putstr_fd("End of message signal received from server: ", 1);
		write(1, "\033[0;32m", 7);
		ft_putnbr_fd(info->si_pid, 1);
		ft_putstr_fd("\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	int					server;
	char				*str_to_send;
	struct sigaction	client;

	if (ft_check(ac, av))
		return (write(1, "error\n", 7));
	ft_putstr_fd("\033[0;35m", 1);
	ft_putstr_fd("String lenght: ", 1);
	ft_putnbr_fd(ft_strlen(av[2]), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&client.sa_mask);
	client.sa_flags = SA_RESTART | SA_SIGINFO;
	client.sa_sigaction = client_handler;
	config(&client);
	server = ft_atoi(av[1]);
	if (server <= 0)
		return (-1);
	str_to_send = av[2];
	send_str(server, str_to_send);
	return (0);
}
