/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:54:14 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 15:55:14 by emdi-mar         ###   ########.fr       */
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
