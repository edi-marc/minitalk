/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:59:51 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/24 23:31:25 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	set_string(char c, pid_t pid)
{
	static char	*str;
	char		*tmp;
	int			i;

	if (c == '\0')
	{
		ft_putendl_fd(str, STDOUT_FILENO);
		free(str);
		str = NULL;
		i = send_char(c, pid);
		if (i != 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		tmp = str;
		str = ft_str_c_join(str, c);
		free(tmp);
	}
}

static void	handler_decode(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	j;

	c = decode_char(sig);
	j++;
	if (j > 7)
	{
		j = 0;
		set_string(c, info->si_pid);
	}
	ucontext = NULL;
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		exit(EXIT_FAILURE);
	ft_putendl_fd(pid, STDOUT_FILENO);
	free(pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_decode;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
