/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:46:14 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/24 11:51:29 by edi-marc         ###   ########.fr       */
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
		usleep(50);
	}
	return (i);
}
