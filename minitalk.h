/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:14:57 by aconti            #+#    #+#             */
/*   Updated: 2024/03/18 16:52:21 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

# define WAIT_TIME 100
//utils
void	send_char(int pid, char c);
void	config(struct sigaction *act);
void	send_bit(int pid, int bit, int wait);
void	send_num(int pid, int n);

//client
void	send_str(int pid, char *str);
int		ft_check(int ac, char **av);
typedef struct s_minitalk
{
	int		bits;
	int		data;
	int		len;
	char	*str;
}	t_minitalk;

#endif