/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbritni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 09:28:29 by lbritni           #+#    #+#             */
/*   Updated: 2019/04/08 09:28:32 by lbritni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *cdest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(cdest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	cdest = ft_strcpy(cdest, s1);
	cdest = ft_strcat(cdest, s2);
	return (cdest);
}
