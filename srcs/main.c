/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:46:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/01 20:35:10 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int argc, char **ar)
{
	int		fd;
	t_list	*sqr;

	if (argc != 2)
	{
		write (1, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	fd = open(ar[1], O_RDONLY);
	if (fd == -1 || (sqr = ft_read(fd)) == NULL || close(fd) == -1)
	{
		write(1, "error", 5);
		exit(0);
	}
	ft_bt(sqr);	
}

