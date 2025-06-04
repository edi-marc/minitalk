/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:05:37 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 16:05:57 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
