/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:59:16 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/24 23:31:23 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	static char	c;
	static int	j;

	c = decode_char(sig);
	j++;
	if (j > 7 && c == '\0')
	{
		ft_putendl_fd(ACK, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

static int	send_string(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (*str && (i == 0))
		i = send_char(*str++, pid);
	i = send_char('\0', pid);
	return (i);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	struct sigaction	sa;

	if (argc == 3)
	{
		pid = ft_atoi_s(argv[1]);
		if (!(pid > 0))
			exit(EXIT_FAILURE);
		sa.sa_handler = handler;
		sigemptyset(&sa.sa_mask);
		sigaddset(&sa.sa_mask, SIGUSR1);
		sigaction(SIGUSR1, &sa, NULL);
		i = send_string(argv[2], pid);
		if (i == 0)
		{
			while (1)
				pause();
			exit(EXIT_SUCCESS);
		}
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
}
