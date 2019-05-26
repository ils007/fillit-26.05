/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:46:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/01 20:45:27 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_second(char *tetr)
{
	int i;
	int cross;

	i = 0;
	cross = 0;
	while (i < 20)
	{
		if(tetr[i] == '#')
		{
			if (tetr[i - 1] == '#')
				cross++;
			if (tetr[i + 1] == '#')
				cross++;
			if (i + 5 < 19 && tetr[i + 5] == '#')
				cross++;
			if (i - 5 >= 0 && tetr[i - 5] == '#')
				cross++;
		}
	i++;
	}
	if (cross < 6)
		return (0);
	return (1);
}

static int	ft_check_first(char *tetr, int ret)
{
	int i;
	int dot;
	int hash;

	i = 0;
	dot = 0;
	hash = 0;
	if (ret !=20 && ret != 21)
		return (0);
	while (tetr[i] != '\0')
	{
		if (tetr[i] == '.')
			dot++;
		if (tetr[i] == '#')
			hash++;
		if ((i + 1) % 5 == 0)
			if (tetr[i] != '\n')
				return (0);
		i++;
	}
	if (dot != 12 || hash != 4)
		return (0);
	if (tetr[20] != '\n' && tetr[20] != '\0')
		return (0);
	return (1);
}	

t_list *ft_read (int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	t_list *sqr;
	t_list *p;

	sqr = NULL;
	while((ret = read(fd, buf, BUF_SIZE)) > 0 )
	{
		buf[ret] = '\0';
		if (ft_check_first(buf, ret) == 0 || ft_check_second(buf) == 0)
			return (NULL);
		ft_createlist(&sqr, buf, &p);
		if (sqr == NULL)
			return (NULL);
	}
	if (ret == -1)
		return (NULL);
	return (sqr);
}

