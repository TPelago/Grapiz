/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 12:31:59 by tpelago           #+#    #+#             */
/*   Updated: 2016/03/30 17:15:23 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdio.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "../includes/grapiz.h"

//#define WIDTH 1024

int	get_X_board(int	x)
{
  int	X_board;
  
  X_board = x - 5;
  //  if (X_board < 0)
  //    X_board = -(X_board);
  printf("x vaut %d\n", X_board);
  return (X_board);
}

int	get_Y_board(int y)
{
  int	Y_board;


  Y_board = y - 5;
  //  if (Y_board < 0)
  //    Y_board = -(Y_board);
  printf("y vaut %d\n", Y_board);
  return (-Y_board);
  
}

t_hexa_polar **init_coord()
{
  t_hexa_polar **coord;
  int	i;

  i = 0;
  coord = malloc(sizeof(t_hexa_polar *) * 9);
  while (i < 9)
    {
      coord[i] = malloc(sizeof(t_hexa_polar) * 9);
      i++;
    }
  i = 0;
  while (i < 81)
    {
      (coord[i / 9][i % 9]).x = 0;
      (coord[i / 9][i % 9]).y = 0;
      //      printf("test %i %i\n", i / 9, i % 9);
      i++;
    }
  //  printf("outside of the loop\n");
  return (coord);
}

void	set_coord(t_hexa_polar **tab)
{
	(void)tab;
//  tab[0][4].x = -1.75;
//    tab[0][4].y = 0;


  //  tab[0][5].x = 2;
  //  tab[0][5].y = 0;
}

int	rotation_X(double x, double y, int cosinus, int sinus)
{
  //  printf("params %i %i %lf %lf\n", x, y, cosinus, sinus);
  //  printf("rotation_X %lf\n", (x - 1024/2) * cosinus - (y - 760/2) * sinus + 1024/2);
  return((x - 1024/2) * cosinus - (y - 760/2) * sinus + 1024/2);
}

int	rotation_Y(double x, double y, int cosinus, int sinus)
{
  //  printf("params %i %i %lf %lf\n", x, y, cosinus, sinus);
  //  printf("rotation_Y %lf\n",(x - 1024/2) * sinus + (y - 760/2) * cosinus + 760/2);
  return((x - 1024/2) * sinus + (y - 760/2) * cosinus + 760/2);
}

