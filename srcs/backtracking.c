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

void	ft_strreplace(char *str, char old, char new)
{
	while (*str)
	{
		if (*str == old)
			*str = new;
		str++;
	}
}

void	ft_printboard()
{
	int i;

	i = 0;
	while (size > i)
	{
		write(1, board[i++], size);
		write(1, "\n", 1);
	}
}

void ft_board()
{
	int i;
	int j;

	i = 0;
	while (size > i)
	{
		j = 0;
		while (size > j)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
}

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0 || nb > 2147483647)
		return (0);
	else
	{
		while(i * i <= nb)
			{
				if (i * i == nb)
					return (i);
				if (i * i < nb && ((i + 1) * (i + 1) > nb))
					return (i + 1);
				else
					i++;
			}
		return (0);
	}
}

int	ft_listlen(t_list *sqr)
{
	int		count;
	t_list	*p;

	p = sqr;
	count = 0;
	while (p)
	{	
		count++;
		p = p->next;
	}
	return (count);
}

void	 ft_write(t_list *sqr, int x, int y)
{
	char	*tetris;
	int		i;

	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
	while(tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
			board[y][x] = tetris[i];
		else if (tetris[i] == 'r')
			x++;
		else if (tetris[i] == 'd')
			y++;
		else if (tetris[i] == 'l')
			x--;
		i++;
	}
}

int     ft_check(t_list *sqr, int x, int y)
{
	char	*tetris;
	int		i;

	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
	if ((x + ((t_tetri*)(sqr->content))->x) > size ||
		(y + ((t_tetri*)(sqr->content))->y) > size)
		return (0);
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
		{
			if (board[y][x] != '.')
				return (0);
		}
		else if(tetris[i] == 'r')
			x++;
		else if(tetris[i] == 'd')
			y++;
		else if(tetris[i] == 'l')
			x--;
		i++;
	}
	return (1);
}

void	ft_clean(t_list *sqr)
{
	char	*tetris;
	char	tetris_char;
	int		i;

	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
			tetris_char = tetris[i];
		i++;
	}
	i = 0;
	while (i < size)
		ft_strreplace(board[i++], tetris_char, '.');
}

int     solution(t_list *sqr, int x, int y)
{
	if (sqr == NULL)
		return (1);
	while (size >= y + ((t_tetri*)(sqr->content))->y)
	{
		x = 0;
		while (size >= x + ((t_tetri*)(sqr->content))->x)
		{
			if (ft_check(sqr, x, y) == 1)
			{
				ft_write(sqr, x, y);
				if (solution(sqr->next, 0, 0) == 1)
					return (1);
				else
					ft_clean(sqr);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

void	ft_bt(t_list *sqr)
{
	size = ft_sqrt(ft_listlen(sqr) * 4);
	ft_board();
	while ((solution(sqr, 0, 0)) != 1)
	{
		size++;
		ft_board();
	}
	ft_printboard();
}
