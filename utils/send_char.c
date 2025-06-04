/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:10:00 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 16:10:20 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_char(char c, pid_t pid)
{
	int	i;
	int	j;

	j = 8;
	i = 0;
	while (--j >= 0 && (i == 0))
	{
		if (c >> j & 1)
			i = kill(pid, SIGUSR2);
		else
			i = kill(pid, SIGUSR1);
		usleep(500);
	}
	return (i);
}
