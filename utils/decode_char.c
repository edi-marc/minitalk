/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:37:23 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/24 18:44:57 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	decode_char(int sig)
{
	static char	c;
	static int	j;

	if (j > 7)
	{
		c = '\0';
		j = 0;
	}
	c = (c << 1);
	if (sig == SIGUSR2)
		c++;
	j++;
	return (c);
}