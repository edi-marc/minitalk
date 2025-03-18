/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:16:58 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/22 14:00:39 by edi-marc         ###   ########.fr       */
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
