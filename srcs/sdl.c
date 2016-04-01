#include <math.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../includes/grapiz.h"
#include <time.h>

void	init_flags(t_flags *flags)
{
	flags->ai = NO;
	printf("%d\n", rand());
	srand(time(0));
	if (rand() % 2 == 1)
		flags->turn = 'B';
	else
		flags->turn = 'R';
}

void	handle_flags(int argc, char **argv, t_flags *flags)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if ((ft_strequ("-AI", argv[i]) == 0))
			flags->ai = YES;
//		if ((ft_strequ("-IA", argv[i]) == 0))
//			flags->ai = YES;
		if ((ft_strequ("-BLUE", argv[i]) == 0) || (ft_strequ("-B", argv[i]) == 0))
			flags->turn = 'B';
		if ((ft_strequ("-RED", argv[i]) == 0) || (ft_strequ("-R", argv[i]) == 0))
			flags->turn = 'R';
	}
}

int	error(char *err_msg)
{
  printf("%s\n", err_msg);
  return (-1);
}

t_hexa	*mouse_on_object(int button_x, int button_y, t_hexa **board)
{
	int		i;
	double	rotated_x;
	double	rotated_y;

	i = 0;
	
//	rotated_x = rotation_X(button_x, button_y, 0, -1);
//	rotated_y = rotation_Y(button_x, button_y, 0, -1);
	rotated_x = button_x;
	rotated_y = button_y;
	//	printf("rotated_x vaut %lf|rotated_y vaut %lf\n", rotated_x, rotated_y);
	while (i < 81)
	{
		if (board[i / 9][i % 9].color == 'R' || board[i / 9][i % 9].color == 'B' || board[i / 9][i % 9].eatable == YES)
		{
		  //			printf("ROTATED_X DOIT ETRE COMPRIS ENTRE %d et %d\n", board[i/9][i%9].sprite_area.x, board[i/9][i%9].sprite_area.x + 60);
		  //			printf("ROTATED_Y DOIT ETRE COMPRIS ENTRE %d et %d\n", board[i/9][i%9].sprite_area.y, board[i/9][i%9].sprite_area.y + 60);
		  //			printf("i vaut %d\n", i);
			if ((rotated_x >= board[i/9][i%9].sprite_area.x && rotated_x <= board[i/9][i%9].sprite_area.x + 60) && (rotated_y >= board[i/9][i%9].sprite_area.y && rotated_y <= board[i/9][i%9].sprite_area.y + 60))
			{
			  //				printf("PASS THE TEST\n");
				board[i / 9][i % 9].i = i / 9;
				board[i / 9][i % 9].j = i % 9; 
				return (&(board[i / 9][i % 9]));
			}
		}
		i++;
	}
	return (0);
}

void	printsprite(SDL_Renderer *pRenderer, t_sprite *sprite)
{
  SDL_RenderCopy(pRenderer, sprite->pTexture, NULL, &(sprite)->sprite_area);
}

int main (int argc, char **argv)
{

  printf("begin\n");
  // variable declarations
  
  t_hexa **board;
  SDL_Window *win = NULL;
  SDL_Event e;
  SDL_Renderer *pRenderer;
  t_sprite	*sprites_list[6];
  t_hexa	*clicked_object;
  int		turn;
  int		state;
    t_hexa	*previous_object;
    int	*six_moves;
	t_flags	flags;
  //  int		six_moves[6];
  
  board = init_board();
  set_board(board);
  state = CHOOSE_PAWN;
  init_flags(&flags);
  handle_flags(argc, argv, &flags);
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return (-1);
  win = SDL_CreateWindow("Grapiz", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (!win)
    return (-1);
  SDL_Delay(100);
  pRenderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (!pRenderer)
    return (-1);
  SDL_Delay(100);
  SDL_Delay(100);
  sprites_list[0] = load_background(pRenderer); // on stock le sprite BG
  if (!sprites_list[0])
    return (error("FATAL ERROR: BACKGROUND not loaded"));
  sprites_list[1] = load_board(pRenderer); // on stock le sprite BOARD
  if (!sprites_list[1])
    return (error("FATAL ERROR: BOARD not loaded"));
  sprites_list[2] = load_blue_pawn(pRenderer); // on stock le sprite BLUE
  if (!sprites_list[2])
    return (error("FATAL ERROR: BLUE PAWN not loaded"));
  sprites_list[3] = load_red_pawn(pRenderer); // on stock le sprite RED
  if (!sprites_list[3])
    return (error("FATAL ERROR: RED PAWN not loaded"));
  sprites_list[4] = load_possible_pawn(pRenderer); // on stock le sprite RED
  if (!sprites_list[4])
    return (error("FATAL ERROR: POSSIBLE PAWN not loaded"));
  printsprite(pRenderer, sprites_list[0]);
  printsprite(pRenderer, sprites_list[1]);
  // printsprite(pRenderer, sprites_list[1]);
  print_pieces(pRenderer, board, sprites_list);
  print_board(board);
  SDL_RenderPresent(pRenderer);
  //  SDL_Delay(10000);  
//  SDL_RenderPresent(pRenderer);
  //Handle events on queue
  int quit = 0;
  while (quit == 0)
    {
		while ((flags->ai == YES && turn == flags->turn) || SDL_PollEvent( &e ) != 0)
	{
	  //User requests quit
	  //	  print_tab(board);
	  if (e.type == SDL_QUIT)
	    {
	      quit = 1;
	    }
	  //User presses a key
	  else if (USER_PRESSED_KEY)
	    {
			if (USER_PRESSED_ESC)
			{
				printf("ESC KEY PRESSED\n");
				quit = 1;
				break;
			}
		}
	  else if (AI_PICK_TURN)
	  {
		  //SELECT A PAWN RANDOMLY of the color
/*
						  six_moves = show_possible_moves(board, clicked_object->i * 9 + clicked_object->j, turn);
						  if (no_legal_move(six_moves) == 1)
						  {
							  //on change de tour et break
							  break;
						  }
 */
		  //change the state
		  
	  }
	  else if (AI_PLACE_TURN)
	  {
		  //RANDOM PICK A PAWN IN SIX_MOVES
		  printf("EATABLE ONE\n");
		  if (set_pawn(board, clicked_object->i * 9 + clicked_object->j, six_moves, turn) != -1)
		  {
			  printsprite(pRenderer, sprites_list[0]);
			  printsprite(pRenderer, sprites_list[1]);
//			  previous_object->color = 'e'; 
			  print_pieces(pRenderer, board, sprites_list);
			  SDL_RenderPresent(pRenderer);
			  if (is_game_finished(board, turn))
			  {
						  SDL_Delay(5000);
						  SDL_Quit();
						  // faut free
						  return (0);
			  }
			  if (turn == 'B')
				  turn = 'R';
			  else
				  turn = 'B';
					  state = CHOOSE_PAWN;
		  }
	  }
	  else if (USER_PRESSED_BUTTON)
	  {
		  if (USER_PRESSED_LEFTBUTTON)
		  {
//		  printf("LEFT BUTTON PRESSED\n");
//		  printf("Coordinates: x %i, y %i\n", e.button.x, e.button.y);
			  clicked_object = mouse_on_object(e.button.x, e.button.y, board);
			  if (state == CHOOSE_PAWN)
			  {
				  if (turn == 'B')
					  printf(BLUE_TEXT);
				  else
					  printf(RED_TEXT);
				  if (clicked_object)
				  {
					  printf("clicked_object is PAWN #%i\n", clicked_object->i * 9 + clicked_object->j);
					  if (clicked_object->color == 'B')
						  printf("L'objet est un pion bleu\n");
					  else if (clicked_object->color == 'R')
						  printf("L'objet est un pion rouge\n");
					  if (clicked_object->color == turn)
					  {
						  printf("BONNE COULEUR\n");
						  
						  six_moves = show_possible_moves(board, clicked_object->i * 9 + clicked_object->j, turn);
						  if (no_legal_move(six_moves) == 1)
						  {
							  //on change de tour et break
							  break;
						  }
						  previous_object = clicked_object;
						  printsprite(pRenderer, sprites_list[0]);
						  printsprite(pRenderer, sprites_list[1]);
						  print_pieces(pRenderer, board, sprites_list);
						  SDL_RenderPresent(pRenderer);
						  state = PLACE_PAWN;
						  
					  }
//toseeadiff
//				  print_background_color(pRenderer, clicked_object->sprite_area.x, clicked_object->sprite_area.y);
				  }
				  else
				  {
					  printf("KEEP CLICKING!!!\n");
				  }
				  // 
				  break;
			  }
			  else if (state == PLACE_PAWN)
			  {
				  if (clicked_object)
				  {
					  if (clicked_object->eatable == YES)
					  {
						  
				    printf("EATABLE ONE\n");
				    if (set_pawn(board, clicked_object->i * 9 + clicked_object->j, six_moves, turn) != -1)
					{
						printsprite(pRenderer, sprites_list[0]);
						printsprite(pRenderer, sprites_list[1]);
						previous_object->color = 'e';
						print_pieces(pRenderer, board, sprites_list);
						SDL_RenderPresent(pRenderer);
						if (is_game_finished(board, turn))
						{
							SDL_Delay(5000);
							SDL_Quit();
							return (0);
						}
						if (turn == 'B')
							turn = 'R';
						else
							turn = 'B';
						state = CHOOSE_PAWN;
					}
				    
//				  on mange le pion;
//					on enleve celui actuel
//					on reaffiche
//					on regarde si y a un winner
					printf("BONNE COULEUR PAWN POSSIBLE\n");
					;
					  }
					  else
					  {
						  printf("BUG ?\n%i\n", clicked_object->eatable);
					  }
				  }
				  else
				  {
					  printf("KEEP CLICKING!!!\n");
				  }
				  // 
				  break;
			  }
		  }
	      printf("not handled event\n");
	      
	  }
	}
    }
  return (0);
}
