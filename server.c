/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:51:03 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/23 22:23:13 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	decode_char(int sig)
{
	static char	c;

	c = (c << 1);
	if (sig == SIGUSR2)
		c | 1;
	return (c);
}

static int	decode_char(int sig)
{
	static int	j;
	static char	c;

	if (j < 8)
	{
		decode_sig(sig);
		j++;
	}
}


static void	decode_str(int sig)
{

}

static void	handler_sig(int sig)
{
	decode_str(sig);
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
	sa.sa_handler = handler_sig;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
