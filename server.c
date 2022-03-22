/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:51:03 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/22 19:25:12 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	write_sig(int num)
{
	char	*sig;

	sig = ft_itoa(num);
	if (!sig)
		exit(EXIT_FAILURE);
	ft_putendl_fd(sig, STDOUT_FILENO);
}

static void	handler_sig(int num)
{
	if (num == SIGUSR1)
	{
		write(STDOUT_FILENO, "OK_SIGUSR1\n", 11);
		write_sig(SIGUSR1);
	}
	else if (num == SIGUSR2)
	{
		write(STDOUT_FILENO, "OK_SIGUSR2\n", 11);
		write_sig(SIGUSR2);
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
