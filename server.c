/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:51:03 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:59 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_decode(int sig)
{
	static char	c;
	static int	j;

	c = decode_char(sig);
	j++;
	if (j > 7)
	{
		j = 0;
		write(1, &c, 1);
	}
}

int	main(void)
{
	char				*pid;
	struct sigaction	sa;

	pid = ft_itoa(getpid());
	if (!pid)
		exit(EXIT_FAILURE);
	ft_putendl_fd(pid, STDOUT_FILENO);
	free(pid);
	sa.sa_handler = handler_decode;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
