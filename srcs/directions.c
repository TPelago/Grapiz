/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:22:02 by tpelago           #+#    #+#             */
/*   Updated: 2016/03/30 22:29:22 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/grapiz.h"
#define RED 1
#define BLUE 2

int		count_deplacement_vertical(t_hexa **array, int pawn)
{
  //  printf("pawn %i \n", pawn);
	int	pawn_x;
	int	pawn_y;
	int	deplacement = 0;

	//	printf("%d\n", pawn);
	pawn_y = 0;
	pawn_x = pawn % 9;
	while (pawn_y > -1 && pawn_y < 9)
    {
		//      printf("On regarde la case %i ; %i\n", pawn_y, pawn_x);
		if (array[pawn_y][pawn_x].color == 'R' || array[pawn_y][pawn_x].color == 'B')
			deplacement++;
		pawn_y++;
    }
    printf("le pion doit bouger de %i units verticalement\n", deplacement);
	return (deplacement);
}

int		count_deplacement_horizontal(t_hexa **array, int pawn)
{
	//  printf("horizontal move %i\n", pawn);
	int	pawn_x;
	int	pawn_y;
	int	deplacement = 0;

	pawn_y = pawn / 9;
	pawn_x = 0;
	while (pawn_x > -1 && pawn_x < 9)
    {
		if (array[pawn_y][pawn_x].color == 'R' || array[pawn_y][pawn_x].color == 'B')
		{
			//	  printf("%i %i\n", pawn_y, pawn_x);	  
			deplacement++;
		}
		//      printf("%i %i\n", pawn_y, pawn_x);	  
		pawn_x++;
    }
    printf("le pion doit bouger de %i units horizontalement\n", deplacement);
	return (deplacement);
}

int		count_deplacement_diagonal(t_hexa **array, int pawn)
{
	//  printf("diagonal move \n");
	int	pawn_x;
	int	pawn_y;
	int	deplacement = 0;

	pawn_y = pawn / 9;
	pawn_x = pawn % 9;
	while ((pawn_x > -1 && pawn_x < 9) && (pawn_y > -1 && pawn_y < 9))
    {
		if (array[pawn_y][pawn_x].color == 'R' || array[pawn_y][pawn_x].color == 'B')
		{
			deplacement++;
			//	printf("+1 deplacement en diago\n");
		}
		pawn_x++;
		pawn_y--;
    }
	pawn_y = pawn / 9;
	pawn_x = pawn % 9;
	pawn_x--;
	pawn_y++;
    while ((pawn_x > -1 && pawn_x < 9) && (pawn_y > -1 && pawn_y < 9))
    {
		if (array[pawn_y][pawn_x].color == 'R' || array[pawn_y][pawn_x].color == 'B')
			deplacement++;
		pawn_x--;
		pawn_y++;
    }
	printf("le pion doit bouger de %i units diagonalement\n", deplacement);
	return (deplacement);
}

int		up_possible_move(t_hexa **array, int pawn, int deplacement, int turn)
{
	int	deplacement_copy = deplacement;
	int	i;

	i = 0;
	
	if (valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 , turn) > 0)
    {
      printf("====>\n");
      printf("UP POSSIBLE MOVE\n");
		while (deplacement > 0)
		{
		  printf("%c\n", array[pawn /9 - deplacement][pawn%9].color);
		  if ((valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 , turn) == 3 || valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 , turn) == 2) && i == 0)
		    {
		      i++;
				deplacement--;
		    }
		  else if ((array[pawn / 9 - deplacement][pawn % 9].color == turn || valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 , turn) == 3) && i != 0)
				deplacement--;
			else
				break;
		}
		if (deplacement == 0)
			return (((pawn / 9) - deplacement_copy) * 9 + pawn % 9);
    }
	return (-1);
}

int		down_possible_move(t_hexa **array, int pawn, int deplacement, int turn)
{
    int	deplacement_copy = deplacement;
    int	i;

    i = 0;

      	if (valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 , turn) > 0)
    {
            printf("====>\n");
	    printf("DOWN POSSIBLE MOVE\n");
		while (deplacement > 0)
		{
		  printf("%c\n", array[pawn /9 + deplacement][pawn%9].color);
		  if ((valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 , turn) == 3 || valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 , turn) == 2) && i == 0)
		    {
		    deplacement--;
		    i++;
		    }
		  else if ((array[pawn / 9 + deplacement][pawn % 9].color == turn || valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 , turn) == 3) && i != 0)
		    deplacement--;
		  else
		    break;

		}
		if (deplacement == 0)
			return (((pawn / 9) + deplacement_copy) * 9 + pawn % 9);
    }
	return (-1);  
}

int		left_possible_move(t_hexa **array, int pawn, int deplacement, int turn)
{
	int	deplacement_copy = deplacement;
	int	i;
	i = 0;

	
	if (valid_pawn(array, pawn / 9, + pawn % 9 - deplacement, turn) > 0)
    {
      	              printf("====>\n");
		      printf("LEFT POSSIBLE MOVE\n");
		      
      while (deplacement > 0)
	{
	  printf("%c\n", array[pawn /9][pawn%9 - deplacement].color);
      		  if ((valid_pawn(array, pawn / 9, + pawn % 9 - deplacement, turn) == 3 || valid_pawn(array, pawn / 9, + pawn % 9 - deplacement , turn) == 2) && i == 0)
		    {
		      i++;
				deplacement--;
		    }
		  else if ((array[pawn / 9][pawn % 9 - deplacement].color == turn || valid_pawn(array, pawn / 9, + pawn % 9 - deplacement, turn) == 3) && i != 0)
				deplacement--;
			else
				break;
    }
		if (deplacement == 0)
			return (((pawn / 9)) * 9 + pawn % 9 - deplacement_copy);
    }
	return (-1);    
}

int		right_possible_move(t_hexa **array, int pawn, int deplacement, int turn)
{
    int	deplacement_copy = deplacement;
    int	i;

    i = 0;
	
	if (valid_pawn(array, pawn / 9, pawn % 9 + deplacement, turn) > 0)
	  {
	    	              printf("====>\n");
		      printf("RIGHT POSSIBLE MOVE\n");
		      
	    while (deplacement > 0)
	      {
		printf("%c\n", array[pawn /9][pawn%9 + deplacement].color);
	    if ((valid_pawn(array, pawn / 9, + pawn % 9 + deplacement, turn) == 3 || valid_pawn(array, pawn / 9, + pawn % 9 + deplacement , turn) == 2) && i == 0)
	      {
		i++;
	      deplacement--;
	      }
	    else if ((array[pawn / 9][pawn % 9 + deplacement].color == turn || valid_pawn(array, pawn / 9, + pawn % 9 + deplacement, turn) == 3) && i != 0)
	      {
		printf("CA PASSE LE DEUXIEME IF\n");
		printf("%c\n", array[pawn / 9][pawn%9 + deplacement].color);
	      deplacement--;
	      }
	    else
	      break;
	  }
		if (deplacement == 0)
			return (((pawn / 9)) * 9 + pawn % 9 + deplacement_copy);
	  }
	printf("%d", deplacement);
	return (-1);      
}

int		upright_possible_move(t_hexa **array, int pawn, int deplacement, int turn)
{
	int	deplacement_copy = deplacement;
	int	i;

	i = 0;

	
	if (valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 + deplacement, turn) > 0)
	  {
	    	    	              printf("====>\n");
				      printf("UPRIGHT POSSIBLE MOVE\n");
	    while (deplacement > 0)
	      {
		printf("%c\n", array[pawn /9 - deplacement ][pawn%9 + deplacement].color);
		if ((valid_pawn(array, pawn / 9 - deplacement, pawn % 9 + deplacement, turn) == 3 || valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 + deplacement , turn) == 2) && i == 0)
		  {
		    i++;
		  deplacement--;
		  }
		else if ((array[pawn / 9 - deplacement][pawn % 9 + deplacement].color == turn || valid_pawn(array, pawn / 9 - deplacement, + pawn % 9 + deplacement, turn) == 3) && i != 0)
		  {
		  deplacement--;
		  }
		else
		  break;
	      }
	    if (deplacement == 0)
	      return (((pawn / 9) - deplacement_copy) * 9 + pawn % 9 + deplacement_copy);
	  }
	return (-1);      
}

int		downleft_possible_move(t_hexa **array, int pawn, int deplacement, int turn)
{
    int	deplacement_copy = deplacement;
    int	i;

    i = 0;

	
	if (valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 - deplacement, turn) > 0)
    {
      	    	    	              printf("====>\n");
				      printf("DOWNLEFT POSSIBLE MOVE\n");
      	    while (deplacement > 0)
	      {
		printf("%c\n", array[pawn /9 + deplacement][pawn%9 - deplacement].color);
		if ((valid_pawn(array, pawn / 9 + deplacement, pawn % 9 - deplacement, turn) == 3 || valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 - deplacement , turn) == 2) && i == 0)
		  {
		  deplacement--;
		  i++;
		  }
		else if ((array[pawn / 9 + deplacement][pawn % 9 - deplacement].color == turn || valid_pawn(array, pawn / 9 + deplacement, + pawn % 9 - deplacement, turn) == 3) && i != 0)
		  deplacement--;
		else
		  break;
	      }
	    if (deplacement == 0)
	      return (((pawn / 9) + deplacement_copy) * 9 + pawn % 9 - deplacement_copy);
    }
	return (-1);
}
