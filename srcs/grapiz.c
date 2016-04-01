/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grapiz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:06:18 by tpelago           #+#    #+#             */
/*   Updated: 2016/03/30 22:17:15 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "../includes/grapiz.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_x(int space)
{
	write(1, "\e[1;36m", 7);
//	write(1, "\e[1;107m", 8);
	ft_putchar('R');
	write(1, "\e[0m", 4);
	if (space)
		print_empty();
}

void	print_xy(t_hexa **board)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9 )
		{
//			printf("x=>%d ; y=>%d | ", board[i][j].x, board[i][j].y);
			(void)board;
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_tab(t_hexa **board)
{
	int	i;
	int	j;

	i = 0;
	printf(" 012345678\n");
	while (i < 9)
    {
		j = 0;
		ft_putchar(i + '0');
		while (j < 9)
      	{
			if (board[i][j].color == '#')
				print_x(0);
			else if (board[i][j].color == 'R')
				print_red(0);
			else if (board[i][j].color == 'B')
				print_blue(0);
			else if (board[i][j].eatable == YES)
			{
				if (board[i][j].color == 'B')
					print_darkred(1);
				else
					print_darkblue(1);
			}
			else
				print_empty();
			j++;
		}
		i++;
		write(1, "\n", 1);
    }
}

void	print_board(t_hexa **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
    {
		padding(i);
		j = 0;
		while (j < 9)
		{
	  if (board[i][j].color == 'e')
	  {
	      print_empty();
	      print_empty();
	  }
	  else if(board[i][j].color == '#')
	  {
	      print_empty();
	  }
	  else
	  {
		  if (board[i][j].eatable == YES)
		  {
		    //			  if (board[i][j].color == 'B')
		    //				  print_darkred(1);
		    //			  else
		    ft_putchar('A');
		  }
	      else if (board[i][j].color == 'R')
			  print_red(1);
	      else if (board[i][j].color == 'B')
			  print_blue(1);
		  else
			  print_empty();
	  }
	  j++;
		}
		write(1, "\n", 1);
		i++;
    }
}

void		change_hexa(t_hexa **board, int cell, double x, double y, int z, int color, int eatable)
{
	board[cell / 9][cell % 9].x = x;
	board[cell / 9][cell % 9].y = y;
	board[cell / 9][cell % 9].z = z;
	board[cell / 9][cell % 9].color = color;
	board[cell / 9][cell % 9].eatable = eatable;	
}

t_hexa		**init_board(void)
{
	t_hexa	**board;
	int i;

	i = 0;
	board = malloc(sizeof(t_hexa *) * 9);
	while (i < 9)
    {
		board[i] = malloc(sizeof(t_hexa) * 9);
		i++;
    }
	i = 0;
	while (i < 81)
	{
		change_hexa(board, i, 0, 0, 0, 'e', NO);
		i++;
	}
	return (board);
}

void		set_board(t_hexa **board)
{

	int	finished_board = 1;
	
	if (finished_board == 1)
	{
		int		i;

		i = 0;
/*
		change_hexa(board, i++, -4, -4, 0, '#', NO);
		change_hexa(board, i++, -3, -4, 0, '#', NO);
		change_hexa(board, i++, -2, -4, 0, '#', NO);
		change_hexa(board, i++, -1, -4, 0, '#', NO);
		change_hexa(board, i++, 0, -4, 0, 'R', NO);
		change_hexa(board, i++, 1, -4, 0, 'B', NO);
		change_hexa(board, i++, 2, -4, 0, 'e', NO);
		change_hexa(board, i++, 3, -4, 0, 'R', NO);
		change_hexa(board, i++, 4, -4, 0, 'B', NO);

VERSION DE BASE
*/
		change_hexa(board, i++, -6, -4, 0, '#', NO);
		change_hexa(board, i++, -5, -4, 0, '#', NO);
		change_hexa(board, i++, -4, -4, 0, '#', NO);
		change_hexa(board, i++, -3, -4, 0, '#', NO);
		change_hexa(board, i++, -2, -4, 0, 'R', NO);
		change_hexa(board, i++, -1, -4, 0, 'B', NO);
		change_hexa(board, i++, 0, -4, 0, 'e', NO);
		change_hexa(board, i++, 1, -4, 0, 'R', NO);
		change_hexa(board, i++, 2, -4, 0, 'B', NO);



		change_hexa(board, i++, -5.5, -3, 0, '#', NO);
		change_hexa(board, i++, -4.5, -3, 0, '#', NO);
		change_hexa(board, i++, -3.5, -3, 0, '#', NO);
		change_hexa(board, i++, -2.5, -3, 0, 'B', NO);
		change_hexa(board, i++, -1.5, -3, 0, 'e', NO);
		change_hexa(board, i++, -0.5, -3, 0, 'e', NO);
		change_hexa(board, i++, 0.5, -3, 0, 'e', NO);
		change_hexa(board, i++, 1.5, -3, 0, 'e', NO);
		change_hexa(board, i++, 2.5, -3, 0, 'R', NO);



		change_hexa(board, i++, -5, -2, 0, '#', NO);
		change_hexa(board, i++, -4, -2, 0, '#', NO);
		change_hexa(board, i++, -3, -2, 0, 'e', NO);
		change_hexa(board, i++, -2, -2, 0, 'e', NO);
		change_hexa(board, i++, -1, -2, 0, 'e', NO);
		change_hexa(board, i++, 0, -2, 0, 'e', NO);
		change_hexa(board, i++, 1, -2, 0, 'e', NO);
		change_hexa(board, i++, 2, -2, 0, 'e', NO);
		change_hexa(board, i++, 3, -2, 0, 'e', NO);

		change_hexa(board, i++, -4.5, -1, 0, '#', NO);
		change_hexa(board, i++, -3.5, -1, 0, 'R', NO);
		change_hexa(board, i++, -2.5, -1, 0, 'e', NO);
		change_hexa(board, i++, -1.5, -1, 0, 'e', NO);
		change_hexa(board, i++, -0.5, -1, 0, 'e', NO);
		change_hexa(board, i++, 0.5, -1, 0, 'e', NO);
		change_hexa(board, i++, 1.5, -1, 0, 'e', NO);
		change_hexa(board, i++, 2.5, -1, 0, 'e', NO);
		change_hexa(board, i++, 3.5, -1, 0, 'B', NO);

		change_hexa(board, i++, -4, 0, 0, 'B', NO);
		change_hexa(board, i++, -3, 0, 0, 'e', NO);
		change_hexa(board, i++, -2, 0, 0, 'e', NO);
		change_hexa(board, i++, -1, 0, 0, 'e', NO);
		change_hexa(board, i++, 0, 0, 0, 'e', NO);
		change_hexa(board, i++, 1, 0, 0, 'e', NO);
		change_hexa(board, i++, 2, 0, 0, 'e', NO);
		change_hexa(board, i++, 3, 0, 0, 'e', NO);
		change_hexa(board, i++, 4, 0, 0, 'R', NO);

		change_hexa(board, i++, -3.5, 1, 0, 'R', NO);
		change_hexa(board, i++, -2.5, 1, 0, 'e', NO);
		change_hexa(board, i++, -1.5, 1, 0, 'e', NO);
		change_hexa(board, i++, -0.5, 1, 0, 'e', NO);
		change_hexa(board, i++, 0.5, 1, 0, 'e', NO);
		change_hexa(board, i++, 1.5, 1, 0, 'e', NO);
		change_hexa(board, i++, 2.5, 1, 0, 'e', NO);
		change_hexa(board, i++, 3.5, 1, 0, 'B', NO);
		change_hexa(board, i++, 4.5, 1, 0, '#', NO);

		change_hexa(board, i++, -3, 2, 0, 'e', NO);
		change_hexa(board, i++, -2, 2, 0, 'e', NO);
		change_hexa(board, i++, -1, 2, 0, 'e', NO);
		change_hexa(board, i++, 0, 2, 0, 'e', NO);
		change_hexa(board, i++, 1, 2, 0, 'e', NO);
		change_hexa(board, i++, 2, 2, 0, 'e', NO);
		change_hexa(board, i++, 3, 2, 0, 'e', NO);
		change_hexa(board, i++, 4, 2, 0, '#', NO);
		change_hexa(board, i++, 5, 2, 0, '#', NO);

		change_hexa(board, i++, -2.5, 3, 0, 'B', NO);
		change_hexa(board, i++, -1.5, 3, 0, 'e', NO);
		change_hexa(board, i++, -0.5, 3, 0, 'e', NO);
		change_hexa(board, i++, 0.5, 3, 0, 'e', NO);
		change_hexa(board, i++, 1.5, 3, 0, 'e', NO);
		change_hexa(board, i++, 2.5, 3, 0, 'R', NO);
		change_hexa(board, i++, 3.5, 3, 0, '#', NO);
		change_hexa(board, i++, 4.5, 3, 0, '#', NO);
		change_hexa(board, i++, 5.5, 3, 0, '#', NO);

		change_hexa(board, i++, -2, 4, 0, 'R', NO);
		change_hexa(board, i++, -1, 4, 0, 'B', NO);
		change_hexa(board, i++, 0, 4, 0, 'e', NO);
		change_hexa(board, i++, 1, 4, 0, 'R', NO);
		change_hexa(board, i++, 2, 4, 0, 'B', NO);
		change_hexa(board, i++, 3, 4, 0, '#', NO);
		change_hexa(board, i++, 4, 4, 0, '#', NO);
		change_hexa(board, i++, 5, 4, 0, '#', NO);
		change_hexa(board, i++, 6, 4, 0, '#', NO);
		print_tab(board);
	}
}

/*// WHEN NO SDL UNCOMMENT IT*/
/*
int	main(void)
{
	t_hexa		**board;

	board = init_board();
	set_board(board);
	play(board);
	//  print_board(board);
	//  print_tab(board, turn);
	//  write(1, "\n\n\n", 3);
	return (0);
}



*/
