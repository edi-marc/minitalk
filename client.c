/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:34:59 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/22 23:29:47 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		pid_t pid;

		pid = ft_atoi_s(argv[1]);
		if (!pid)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
