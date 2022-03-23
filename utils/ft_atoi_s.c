/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:00:02 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/23 15:12:54 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: convert ASCII string to integer
**
** DESCRIPTION:
**	The atoi_s() function converts the string pointed
**	to by str to int representation.
**
**	The function has an undefined behavior if the representation of the string
**	overflows the type long int
*/

#include "minitalk.h"

static	long int	calculate(const char *str)
{
	long int	nbr;
	int			k;

	nbr = 0;
	k = 0;
	while (*str > 47 && *str < 58)
	{
		nbr = nbr * 10;
		k = *str;
		nbr = nbr + (k - 48);
		str++;
	}
	if (!(ft_isdigit(*str)) && *str)
		nbr = 0;
	return (nbr);
}

int	ft_atoi_s(const char *str)
{
	long int	nbr;

	nbr = calculate(str);
	return ((int)nbr);
}
