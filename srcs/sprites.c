#include <math.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../includes/grapiz.h"

void		change_Rect_values(SDL_Rect *area, int type, int x, int y)
{
  if (type == PAWN)
    {
      area->h = 60;
      area->w = 60;
      area->y = y - area->h/2;
      area->x = x - area->w/2;
      //	  printf("PAWN VALUES MODIFIED: %i %i %i %i\n", area->x, area->y, area->w, area->h);
    }
  else if (type == BOARD)
    {
      area->x = WIDTH/2 - 600/2;
      area->y = HEIGHT/2 - 670/2;
      area->w = 600;
      area->h = 670;
    }
  else if (type == BACKGROUND)
    {
      area->x = 0;
      area->y = 0;
      area->w = WIDTH;
      area->h = HEIGHT;
    }
  else
    {
      area->x = 0;
      area->y = 0;
      area->w = 0;
      area->h = 0;
    }
}

t_sprite	*load_board(SDL_Renderer *pRenderer)
{
  t_sprite	*Board_Sprite;
  SDL_Surface	*Board_IMG;
  SDL_Texture	*Board_Texture;

  Board_Sprite = malloc(sizeof(t_sprite));
  if (!Board_Sprite)
    return (NULL);
  Board_IMG = SDL_LoadBMP("hexagon.bmp");
  if (!Board_IMG)
    return (NULL);
  Board_Texture = SDL_CreateTextureFromSurface(pRenderer, Board_IMG);
  if (!Board_Texture)
    return (NULL);
  Board_Sprite->pTexture = Board_Texture;
  change_Rect_values(&(Board_Sprite->sprite_area), BOARD, 0, 0);
  return (Board_Sprite);
}

int		print_background_color(SDL_Renderer *pRenderer, int x, int y)
{
  SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
  SDL_Rect rectangle;
 
  rectangle.x = x;
  rectangle.y = y;
  rectangle.w = 60;
  rectangle.h = 60;
  SDL_RenderFillRect(pRenderer, &rectangle);
  return (0);
}

t_sprite	*load_background(SDL_Renderer *pRenderer)
{
  t_sprite	*BG_Sprite;
  SDL_Surface	*BG_IMG;
  SDL_Texture	*BG_Texture;

  BG_Sprite = malloc(sizeof(t_sprite));
  if (!BG_Sprite)
    return (NULL);
  BG_IMG = SDL_LoadBMP("background.bmp");
  if (!BG_IMG)
    return (NULL);
  BG_Texture = SDL_CreateTextureFromSurface(pRenderer, BG_IMG);
  if (!BG_Texture)
    return (NULL);
  BG_Sprite->pTexture = BG_Texture;
  change_Rect_values(&(BG_Sprite->sprite_area), BACKGROUND, 0, 0);
  return (BG_Sprite);
}

t_sprite	*load_blue_pawn(SDL_Renderer *pRenderer)
{
  t_sprite	*Blue_Sprite;
  SDL_Surface	*Blue_IMG;
  SDL_Texture	*Blue_Texture;

  Blue_Sprite = malloc(sizeof(t_sprite));
  if (!Blue_Sprite)
    return (NULL);
  Blue_IMG = SDL_LoadBMP("blue.bmp");
  if (!Blue_IMG)
    return (NULL);
  Blue_Texture = SDL_CreateTextureFromSurface(pRenderer, Blue_IMG);
  if (!Blue_Texture)
    return (NULL);
  Blue_Sprite->pTexture = Blue_Texture;
  change_Rect_values(&(Blue_Sprite->sprite_area), PAWN, 0, 0);
  return (Blue_Sprite);
}

t_sprite	*load_red_pawn(SDL_Renderer *pRenderer)
{
  t_sprite	*Red_Sprite;
  SDL_Surface	*Red_IMG;
  SDL_Texture	*Red_Texture;

  Red_Sprite = malloc(sizeof(t_sprite));
  if (!Red_Sprite)
    return (NULL);
  Red_IMG = SDL_LoadBMP("red.bmp");
  if (!Red_IMG)
    return (NULL);
  Red_Texture = SDL_CreateTextureFromSurface(pRenderer, Red_IMG);
  if (!Red_Texture)
    return (NULL);
  Red_Sprite->pTexture = Red_Texture;
  change_Rect_values(&(Red_Sprite->sprite_area), PAWN, 0, 0);
  return (Red_Sprite);
}

t_sprite	*load_possible_pawn(SDL_Renderer *pRenderer)
{
  t_sprite	*Possible_Sprite;
  SDL_Surface	*Possible_IMG;
  SDL_Texture	*Possible_Texture;

  Possible_Sprite = malloc(sizeof(t_sprite));
  if (!Possible_Sprite)
    return (NULL);
  Possible_IMG = SDL_LoadBMP("possible.bmp");
  if (!Possible_IMG)
    return (NULL);
  Possible_Texture = SDL_CreateTextureFromSurface(pRenderer, Possible_IMG);
  if (!Possible_Texture)
    return (NULL);
  Possible_Sprite->pTexture = Possible_Texture;
  change_Rect_values(&(Possible_Sprite->sprite_area), PAWN, 0, 0);
  return (Possible_Sprite);
}

int	print_pieces(SDL_Renderer *pRenderer, t_hexa **board, t_sprite **sprite)
{
  print_tab(board);
  int	i;
  int	rotate_x;
  int	rotate_y;
  (void)sprite;
  (void)pRenderer;
//  i = 0;
//  while (i < 10)
//  board[4][4].color = 'R';
  i = 0;
//  while (i < 81)
  while (i < 81)
    {
//		printf("change_hexa(board, i++, %d, %d, 0, %c, NO\n", board[i/9][i%9].x, board[i/9][i%9].y, board[i/9][i%9].color);
      		if (board[i / 9][i % 9].eatable == YES)
		  {
		    //		    			printf("x=>%i|y=>%i\n", (int)(WIDTH / 2 + (board[i / 9][i % 9].x * 74)),(int) (HEIGHT/2 + (board[i / 9][i % 9].y * 64)));

			rotate_x = rotation_X(WIDTH / 2 + (board[i / 9][i % 9].x * 74), HEIGHT/2 + (board[i / 9][i % 9].y * 64), 0, 1);
			rotate_y = rotation_Y(WIDTH / 2 + (board[i / 9][i % 9].x * 74), HEIGHT/2 + (board[i / 9][i % 9].y * 64), 0, 1);
			change_Rect_values(&(board[i / 9][i % 9].sprite_area), PAWN, rotate_x, rotate_y);
			SDL_RenderCopy(pRenderer, sprite[4]->pTexture, NULL, &(board[i / 9][i % 9].sprite_area));
		  }
		else if (board[i / 9][i % 9].color == 'B')
		{
//normal without rotation
//			change_Rect_values(&(board[i / 9][i % 9].sprite_area), PAWN, WIDTH/2 + board[i / 9][i % 9].x * 74,HEIGHT/2 + board[i / 9][i % 9].y * 64);
//			printf("%f, %f\n", WIDTH/2 + board[i / 9][i % 9].x * 74,  HEIGHT/2 + board[i / 9][i % 9].y * 64);
//			SDL_RenderCopy(pRenderer, sprite[2]->pTexture, NULL, &(board[i / 9][i % 9].sprite_area));
//
//			printf("x=>%i|y=>%i\n", (int)(WIDTH / 2 + (board[i / 9][i % 9].x * 74)),(int) (HEIGHT/2 + (board[i / 9][i % 9].y * 64)));

			rotate_x = rotation_X(WIDTH / 2 + (board[i / 9][i % 9].x * 74), HEIGHT/2 + (board[i / 9][i % 9].y * 64), 0, 1);
			rotate_y = rotation_Y(WIDTH / 2 + (board[i / 9][i % 9].x * 74), HEIGHT/2 + (board[i / 9][i % 9].y * 64), 0, 1);
			change_Rect_values(&(board[i / 9][i % 9].sprite_area), PAWN, rotate_x, rotate_y);
			SDL_RenderCopy(pRenderer, sprite[2]->pTexture, NULL, &(board[i / 9][i % 9].sprite_area));

// -90deg
//			change_Rect_values(&(board[i / 9][i % 9].sprite_area), PAWN, rotation_X(rotate_x, rotate_y, 0, -1), rotation_Y(rotate_x, rotate_y, 0, -1));
//			SDL_RenderCopy(pRenderer, sprite[2]->pTexture, NULL, &(board[i / 9][i % 9].sprite_area));
		}
		else if (board[i / 9][i % 9].color == 'R')
		{
			rotate_x = rotation_X(WIDTH / 2 + (board[i / 9][i % 9].x * 74), HEIGHT/2 + (board[i / 9][i % 9].y * 64), 0, 1);
			rotate_y = rotation_Y(WIDTH / 2 + (board[i / 9][i % 9].x * 74), HEIGHT/2 + (board[i / 9][i % 9].y * 64), 0, 1);
			change_Rect_values(&(board[i / 9][i % 9].sprite_area), PAWN, rotate_x, rotate_y);
			SDL_RenderCopy(pRenderer, sprite[3]->pTexture, NULL, &(board[i / 9][i % 9].sprite_area));
		}
		i++;
	}
  return (1);
}

