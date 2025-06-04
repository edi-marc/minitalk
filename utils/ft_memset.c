/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:03:05 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 16:03:47 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	int		i;

	p = (char *)b;
	i = 0;
	while (((size_t)i < len) && len != 0)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}
