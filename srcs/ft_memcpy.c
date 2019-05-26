/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbritni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:34:09 by lbritni           #+#    #+#             */
/*   Updated: 2019/04/03 12:34:14 by lbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *csrc;
	unsigned char *cdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (n)
	{
		n--;
		*cdest++ = *csrc++;
	}
	return (dest);
}
