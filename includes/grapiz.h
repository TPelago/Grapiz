#define WIDTH 1024
#define HEIGHT 760
#define	CHOOSE_PAWN 0
#define	PLACE_PAWN 1
#define PAWN 0
#define BOARD 1
#define BACKGROUND 2
#define NO 0
#define YES 1
#define RED 1
#define BLUE 2
#define USER_PRESSED_KEY e.type == SDL_MOUSEBUTTONDOWN
#define USER_PRESSED_ESC e.key.keysym.sym == SDLK_ESCAPE
#define USER_PRESSED_BUTTON e.type == SDL_MOUSEBUTTONDOWN
#define USER_PRESSED_LEFTBUTTON e.button.button == SDL_BUTTON_LEFT
#define AI_PICK_TURN flags->ai == YES && state == CHOOSE_PAWN
#define AI_PLACE_TURN flags->ai == YES && state == PLACE_PAWN
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define RED_TEXT "\n\e[0;31m *******   ******** *******  \n/**////** /**///// /**////** \n/**   /** /**      /**    /**\n/*******  /******* /**    /**\n/**///**  /**////  /**    /**\n/**  //** /**      /**    ** \n/**   //**/********/*******  \n//     // //////// ///////   \n\n\e[0;0m"
#define BLUE_TEXT "\n\e[0;34m ******   **       **     ** ********\n/*////** /**      /**    /**/**///// \n/*   /** /**      /**    /**/**      \n/******  /**      /**    /**/******* \n/*//// **/**      /**    /**/**////  \n/*    /**/**      /**    /**/**      \n/******* /********//******* /********\n///////  ////////  ///////  //////// \n\n\e[0;0m"

typedef struct	s_sprite
{
  SDL_Texture	*pTexture;
  SDL_Rect	sprite_area;
}		t_sprite;

typedef struct	s_hexa_polar
{
  int	x;
  int	y;
}		t_hexa_polar;

typedef struct	s_hexa
{
	double	x;
	double	y;
	int		z;
  	int		i;
  	int		j;
	int		color;
	int		eatable;
	SDL_Rect sprite_area;
}				t_hexa;

typedef struct	s_flags
{
	int		ai;
	int		turn;

}				t_flags;

//grapiz.c quasi fini
void	ft_putchar(char c);
void	print_red(int space);
void	print_empty(void);
void	print_tab(t_hexa **board);
void	print_empty(void);
void	print_outboard(void);
void	print_red(int space);
void	print_blue(int space);
void	padding(int lineno);
void	print_board(t_hexa **board);
void	print_xy(t_hexa **board);
t_hexa	**init_board(void);
void	set_board(t_hexa **board);
//play.c
int		no_legal_move(int *six_moves);
void	reset_six_moves(int (*tab)[6]);
int		*show_possible_moves(t_hexa **tab, int pawn, int turn);
int		valid_pawn(t_hexa **tab, int y, int x, int turn);
int		get_pawn(t_hexa **tab, int turn);
int		how_many_pieces(t_hexa **tab, int turn);
//int		is_contiguous(int **tab, int color, int x, int y, int recursion);
int		is_contiguous(t_hexa tab[9][9], int color, int x, int y, int recursion);
int		is_game_finished(t_hexa **tab, int turn);
int		is_contiguous_pieces(t_hexa tab[9][9], int turn);
//int		is_contiguous_pieces(int *tab, int turn);
//int		set_pawn(char ***tab, int pawn, int *six_moves, int turn);
int		set_pawn(t_hexa **tab, int pawn, int *six_moves, int turn);
int		play(t_hexa **tab);
//colours.c
void	print_darkred(int space);
void	print_darkblue(int space);
void	ft_print_spaces(int spaces);
void	print_empty(void);
void	print_red(int space);
void	print_blue(int space);
void	padding(int lineno);
//directions.c
int		count_deplacement_vertical(t_hexa **array, int pawn);
int		count_deplacement_horizontal(t_hexa **array, int pawn);
int		count_deplacement_diagonal(t_hexa **array, int pawn);
int		up_possible_move(t_hexa **array, int pawn, int deplacement, int turn);
int		down_possible_move(t_hexa **array, int pawn, int deplacement, int turn);
int		left_possible_move(t_hexa **array, int pawn, int deplacement, int turn);
int		right_possible_move(t_hexa **array, int pawn, int deplacement, int turn);
int		upright_possible_move(t_hexa **array, int pawn, int deplacement, int turn);
int		downleft_possible_move(t_hexa **array, int pawn, int deplacement, int turn);
//coord.c
int		get_X_board(int x);
int		get_Y_board(int y);
t_hexa_polar	**init_coord(void);
void	set_coord(t_hexa_polar **tab);
int	rotation_X(double x, double y, int cosinus, int sinus);
int	rotation_Y(double x, double y, int cosinus, int sinus);
//sprites.c
t_sprite	*load_board(SDL_Renderer *pRenderer);
t_sprite    	*load_background(SDL_Renderer *pRenderer);
//t_sprite    	*load_background_color(SDL_Renderer *pRenderer);
t_sprite	*load_blue_pawn(SDL_Renderer *pRenderer);
t_sprite	*load_red_pawn(SDL_Renderer *pRenderer);
t_sprite	*load_possible_pawn(SDL_Renderer *pRenderer);
int    	print_background_color(SDL_Renderer *pRenderer, int x, int y);
int	print_pieces(SDL_Renderer *pRenderer, t_hexa **board, t_sprite **sprite);
void            change_Rect_values(SDL_Rect *area, int type, int x, int y);
//ft_strequ.c
int		ft_strequ(char const *s1, char const *s2);
