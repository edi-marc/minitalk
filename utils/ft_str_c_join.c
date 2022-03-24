/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_c_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:16:56 by edi-marc          #+#    #+#             */
/*   Updated: 2022/03/24 14:30:54 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_str_c_join(char const *str, char c)
{
	char	*p;
	size_t	len;

	p = NULL;
	if (str)
	{
		len = ft_strlen(str);
		p = ft_calloc(len + 2, sizeof(*p));
		if (p)
		{
			ft_strlcat(p, str, len + 1);
			p[len] = c;
		}
	}
	return (p);
}
