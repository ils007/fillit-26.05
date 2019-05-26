/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbritni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:00:29 by lbritni           #+#    #+#             */
/*   Updated: 2019/04/04 11:00:31 by lbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *res;
	void *memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	res = memory;
	while (size)
	{
		*(char *)memory = 0;
		size--;
		memory++;
	}
	return (res);
}
