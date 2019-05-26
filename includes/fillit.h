/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:19:31 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/01 20:35:56 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# define	BUF_SIZE 21
char	board[30][30];
int		size;

typedef	struct	s_tetri
{
	int	x;
	int	y;
	char	*tetris;
}	t_tetri;
t_list		*ft_read(int fd);
void		ft_createlist(t_list **sqr, char *buf, t_list **p);
char    	*codeblock(char *bc, char *buf, char c, int code[6]);
void		ft_freetetri(void *block, size_t size);
void		ft_bt(t_list *sqr);

#endif
