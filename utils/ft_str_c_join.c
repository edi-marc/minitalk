/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_c_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:57 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/06/04 16:07:02 by emdi-mar         ###   ########.fr       */
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
	else
	{
		p = ft_calloc(2, sizeof(*p));
		if (p)
			p[0] = c;
	}
	return (p);
}
