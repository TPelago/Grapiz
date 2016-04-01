/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpelago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:24:17 by tpelago           #+#    #+#             */
/*   Updated: 2016/03/30 22:11:56 by tpelago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/grapiz.h"
#define RED 1
#define BLUE 2

int		no_legal_move(int *six_moves)
{
	int	i;
	int	possible_moves;

	possible_moves = 6;
	i = 0;
	while (i < 6)
    {
      if (six_moves[i] == -1)
		  possible_moves--;
      i++;
    }
	if (possible_moves == 0)
		return (1);
	return (0);
}

void	reset_six_moves(int (*tab)[6])
{
	int	i;

	i = 0;
	while (i < 6)
    {
		(*tab)[i] = -1;
		i++;
    }
}

int		*show_possible_moves(t_hexa **tab, int pawn, int turn)
{
	static int	six_moves[6] = {-1, -1, -1, -1, -1, -1};

	printf("IN SHOW POSSIBLE MOVES: pawn #%i\n", pawn);
	reset_six_moves(&six_moves);
	int	deplacement[3] = {0, 0, 0};
	int	i;
	
	i = 0;
	deplacement[0] = count_deplacement_vertical(tab, pawn);
	six_moves[0] = up_possible_move(tab, pawn, deplacement[0], turn);
	six_moves[1] = down_possible_move(tab, pawn, deplacement[0], turn);
	deplacement[1] = count_deplacement_horizontal(tab, pawn);
	six_moves[2] = right_possible_move(tab, pawn, deplacement[1], turn);
	six_moves[3] = left_possible_move(tab, pawn, deplacement[1], turn);
	deplacement[2] = count_deplacement_diagonal(tab, pawn);
	six_moves[4] = upright_possible_move(tab, pawn, deplacement[2], turn);
	six_moves[5] = downleft_possible_move(tab, pawn, deplacement[2], turn);
	while (i < 6)
    {
		if (six_moves[i] != -1)
		{
//			if (turn == RED)
//				tab[six_moves[i] / 9][six_moves[i] % 9] = 'R' - 100;
//			else
//				tab[six_moves[i] / 9][six_moves[i] % 9] = 'B' - 200;
		  tab[six_moves[i] / 9][six_moves[i] % 9].eatable = YES;
		  tab[six_moves[i] / 9][six_moves[i] % 9].i = six_moves[i] / 9;
		  tab[six_moves[i] / 9][six_moves[i] % 9].j = six_moves[i] % 9;
		}
		i++;
    }
	if (six_moves[0] != -1)
		printf("UP       pawn=>%i x=>%i y=>%i\n", six_moves[0], six_moves[0] % 9, six_moves[0] / 9);
	if (six_moves[1] != -1)
		printf("DOWN     pawn=>%i x=>%i y=>%i\n", six_moves[1], six_moves[1] % 9, six_moves[1] / 9);
	if (six_moves[2] != -1)
		printf("LEFT     pawn=>%i x=>%i y=>%i\n", six_moves[2], six_moves[2] % 9, six_moves[2] / 9);
	if (six_moves[3] != -1)
		printf("RIGHT    pawn=>%i x=>%i y=>%i\n", six_moves[3], six_moves[3] % 9, six_moves[3] / 9);
	if (six_moves[4] != -1)
		printf("UPRIGHT  pawn=>%i x=>%i y=>%i\n", six_moves[4], six_moves[4] % 9, six_moves[4] / 9);
	if (six_moves[5] != -1)
		printf("DOWNLEFT pawn=>%i x=>%i y=>%i\n", six_moves[5], six_moves[5] % 9, six_moves[5] / 9);
//	printf("INSIDE SHOW POSSIBLE MOVES\n");
//	print_board(tab, turn);
//	print_tab(tab, turn);
	return (six_moves);
}

int		valid_pawn(t_hexa **tab, int y, int x, int turn)
{
  (void)turn;
	if (x < 0 || x > 8)
		return (-2);
	if (y < 0 || y > 8)
		return (-2);
	if (tab[y][x].color == turn)
	  {
	    printf("SAME COLOR\n");
	  return (-5);
	  }
	if (tab[y][x].color == '#')
		return (-4);
	if (tab[y][x].color == 'e')
	  {
	    printf("ESPACE\n");
		return (3);
	  }
	if (tab[y][x].color == 'B' && turn == 'R')
	  {printf("EATABLE\n");
	  return (2);
	  }
	//	if (tab[y][x].eatable == YES)
	if (tab[y][x].color == 'R' && turn == 'B')
	  {printf("EATABLE\n");
	  return (2);
	  }
	//  printf("NORMAL (VALID_PAWN) APRES UNE SAISIE ? %c\n", tab[y][x]);
	return (0);
}

int		get_pawn(t_hexa **tab, int turn)
{
	int x;
	int y;
	
	do
    {
		printf("X value of the pawn to move: ");
		scanf("%i", &x);
		printf("Y value of the pawn to move: ");
		scanf("%i", &y);
    }
	while (valid_pawn(tab, y, x, turn) != 0);
	return (y * 9 + x);
}

int		how_many_pieces(t_hexa **tab, int turn)
{
	int	number;
	int	i;
	int	j;

	if (turn == BLUE)
		turn = 'B';
	else
		turn = 'R';
	i = 0;
	number = 0;
	while (i < 9)
    {
		j = 0;
		while (j < 9)
		{
			if (tab[i][j].color == turn)
				number++;
			j++;
		}
		i++;
    }
	return (number);
}

int		is_contiguous(t_hexa tab[9][9], int color, int x, int y, int recursion)
{
//	printf("RECURSION LEVEL %d\n", recursion);
	if (x < 0 || x > 8)
		return (0);
	if (y < 0 || y > 8)
		return (0);
//	printf("tab cell vaut %c et color vaut %c\n", tab[y][x], color);
	if ((tab)[y][x].color == color)
    {
		(tab)[y][x].color = 'e';
		return (1 + is_contiguous(tab, color, x + 1, y, recursion + 1) + is_contiguous(tab, color, x - 1, y, recursion + 1) + is_contiguous(tab, color, x, y - 1, recursion + 1) + is_contiguous(tab, color, x, y + 1, recursion + 1) + is_contiguous(tab, color, x + 1, y - 1, recursion + 1) + is_contiguous(tab, color, x - 1, y + 1, recursion + 1));
    }
	return (0);
}

int		is_contiguous_pieces(t_hexa tab[9][9], int turn)
{
	int	i;
	int	number = 0;

	if (turn == BLUE)
		turn = 'B';
	else
		turn = 'R';
	i = 0;
	while (i < 81 && tab[i / 9][i % 9].color != turn)
		i++;
	if (i != 81)
	{
//	printf("WESH ALORS IS CONTIGUOUS PIECE %c\n", tab[i / 9][i % 9]);
	number = is_contiguous(tab, turn, i % 9, i / 9, 0);
	}
	return (number);
}

void	tab_copy(t_hexa **src, t_hexa dst[9][9])
{
	int		i;

	i = 0;
	while (i < 81)
	{
		dst[i / 9][i % 9].color = src[i / 9][i % 9].color;
		i++;
	}
}

int		is_game_finished(t_hexa **tab, int turn)
{
	int	red_pieces;
	int	blue_pieces;
	int	red_contiguous_pieces;
	int	blue_contiguous_pieces;
	t_hexa	tab2[9][9];

	if (turn == 'B')
	  turn = BLUE;
	else
	  turn = RED;
	print_board(tab);
	tab_copy(tab, tab2);
	red_pieces = how_many_pieces(tab, RED);
	blue_pieces = how_many_pieces(tab, BLUE);
//	printf("turn %c", turn + '0');
	red_contiguous_pieces = is_contiguous_pieces(tab2, turn);
	tab_copy(tab, tab2);
	blue_contiguous_pieces = is_contiguous_pieces(tab2, turn);
//	printf("THERE ARE %d red pieces\n", red_pieces);
//	printf("THERE ARE %d blue pieces\n", blue_pieces);
//	printf("THERE ARE %d contiguous red pieces\n", red_contiguous_pieces);
//	printf("THERE ARE %d contiguous blue pieces\n", blue_contiguous_pieces);
	if (turn == RED)
    {
		printf(RED_TEXT);
		if (red_pieces == red_contiguous_pieces)
		{
			printf("RED WINS\n");
			return (1);
		}
		if (blue_pieces == blue_contiguous_pieces)
		{
			printf(RED_TEXT);
			printf("BLUE WINS\n");
			return (1);
		}
		if (red_pieces == 3)
		{
			printf("RED WINS\n");
			return (1);
		}
		if (blue_pieces == 3)
		{
			printf("BLUE WINS\n");
			return (1);
		}
    }
	else
    {
		printf(BLUE_TEXT);
		if (blue_pieces == blue_contiguous_pieces)
		{
			printf("BLUE WINS\n");
			return (1);
		}
		if (red_pieces == red_contiguous_pieces)
		{
			printf("RED WINS\n");
			return (1);
		}
		if (blue_pieces == 3)
		{
			printf("BLUE WINS\n");
			return (1);
		}
		if (red_pieces == 3)
		{
			printf("RED WINS\n");
			return (1);
		}
    }
	return (0);
}

int		set_pawn(t_hexa **tab, int pawn, int *six_moves, int turn)
{
	int	i;
	char	piece_colour;
	int	found_pawn = 0;

	if (pawn < 0 || pawn > 80)
		return -1;
//	printf("pawn is GOOD -1 > pawn < 81\n");
	piece_colour = 'B';
	if (turn == RED || turn == 'R')
		piece_colour = 'R';
	i = 0;
	while (i < 6)
    {
		if (pawn == six_moves[i])
		{
//			printf("FOUND THE PAWN number %i\n", six_moves[i]);
			found_pawn = 1;
			printf("ON MODIFIE LA VALEUR de la piece %i\n", pawn);
			tab[pawn / 9][pawn % 9].color = piece_colour;
			tab[pawn / 9][pawn % 9].eatable = NO;
			//			tab[pawn / 9][pawn % 9].color = piece_colour;
			six_moves[i] = -1;
		}
		i++;
    }
	if (found_pawn == 0)
		return (-1);
	i = 0;
	while (i < 6)
	{
		if (tab[six_moves[i] / 9][six_moves[i] % 9].eatable == YES)
		{
			tab[six_moves[i] / 9][six_moves[i] % 9].eatable = NO;
		}
		six_moves[i++] = -1;
	}
	return (0);
}

int 	play(t_hexa **tab)
{
	int	turn = RED;
	int	pawn = -1;
	int  change_pawn;
	int	*six_moves;
//	char choice_change_pawn = 'N';
	int	x;
	int	y;

	while (!(is_game_finished(tab, turn)))
	{
		print_tab(tab);
		do
		{
			//pick a pawn
			pawn = get_pawn(tab, turn);
			change_pawn = 0; // pas implemente
			//print the number the pawn is on
			printf("PAWN cell chosen#%i\n", pawn);
//stock the 6 possible moves in a tab //print board and tab with the possible moves on it
			six_moves = show_possible_moves(tab, pawn, turn);
//			printf("SHOW POSSIBLE MOVES FUNCTIONS DONE\n");
			print_board(tab);
//if no playable move, the other player plays ELSE confirmation and setpawn 
			if (no_legal_move(six_moves))
				change_pawn = 1;
			else
			{
				do
				{
					printf("Confirm the move, enter x value: ");
					scanf("%i", &x);
					printf("Confirm the move, enter y value: ");
					scanf("%i", &y);
					printf("pawn cell => %i\n", x  + y * 9);
					print_board(tab);
				}while (set_pawn(tab, x + y * 9, six_moves, turn) == -1);
//				printf("PRINT\n");
//suppress the old pawn (that has moved)
				tab[pawn / 9][pawn % 9].color = 'e';
				print_board(tab);
				print_tab(tab);
// change turn
				change_pawn = 0;
			}
		}
		while (change_pawn == 1);
//CHANGE TURN
		if (turn == RED)
			turn = BLUE;
		else
			turn = RED;
	}
	return (0);
}
