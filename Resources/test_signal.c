/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:37:32 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/21 18:56:07 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:
**		Fun with Unix Signals.
**		Using both signal() and sigaction()
**
**		using SA_RESTART on sigaction() to mimic the behaviour of signal()
**
**		It's recommended to use sigaction() instead of signal() 
**
**		To terminate this process send him SIGKILL:
**			kill [PID]
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	handler_sig(int num)
{
	if (num == SIGINT)
		write(STDOUT_FILENO, "\nNope :-)\n", 10);
	else if (num == SIGQUIT)
		write(STDOUT_FILENO, "\nRetry :-)\n", 11);
	else if (num == SIGTSTP)
		write(STDOUT_FILENO, "\nNO, Please :-)\n", 16);
	else if (num == SIGKILL)
		write(STDOUT_FILENO, "\nCan't handle this :-(\n", 23);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler_sig;
	sa.sa_flags = SA_RESTART;
	signal(SIGINT, handler_sig);
	sigaction(SIGQUIT, &sa, NULL);
	signal(SIGTSTP, handler_sig);
	signal(SIGKILL, handler_sig);
	while (1)
	{
		printf("I'm running! -- PID = %d\n", getpid());
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
