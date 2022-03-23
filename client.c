/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:34:59 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/23 15:06:05 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi_s(argv[1]);
		if (!pid)
			exit(EXIT_FAILURE);
		write(1, "OK", 2);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
