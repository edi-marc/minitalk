/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:51:03 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/22 14:43:54 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		exit(EXIT_FAILURE);
	ft_putendl_fd(pid, STDOUT_FILENO);
	free(pid);
	exit(EXIT_SUCCESS);
}
