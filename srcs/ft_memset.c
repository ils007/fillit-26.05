/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbritni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:34:41 by lbritni           #+#    #+#             */
/*   Updated: 2019/04/02 11:52:23 by lbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int		i;
	void	*result;

	result = str;
	i = 0;
	while (n)
	{
		*(unsigned char *)str = (unsigned char)c;
		str++;
		n--;
	}
	return (result);
}
