/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:04:55 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 16:05:13 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	endl = '\n';
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd(endl, fd);
	}
}
