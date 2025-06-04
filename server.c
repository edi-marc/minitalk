/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:19:06 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 16:19:09 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	set_string(char c)
{
	static char	*str;
	char		*tmp;

	if (c == '\0')
	{
		ft_putendl_fd(str, STDOUT_FILENO);
		free(str);
		str = NULL;
	}
	else
	{
		tmp = str;
		str = ft_str_c_join(str, c);
		free(tmp);
	}
}

static void	handler_decode(int sig)
{
	static char	c;
	static int	j;

	c = decode_char(sig);
	j++;
	if (j > 7)
	{
		j = 0;
		set_string(c);
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
