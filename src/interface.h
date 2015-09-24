/*
** interface.h for interface in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:49:50 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:49:53 2015 aubess_t aubess_t
*/

#ifndef		INTERFACE_H_
# define	INTERFACE_H_

#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<math.h>
#include	<signal.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	"philosophes.h"
#include	"global.h"

#define		LEGENDE_WIDTH	(80)
#define		FILOIMG_WIDTH	(128)
#define		FILOIMG_HEIGHT	(85)
#define		SCREEN_WIDTH	(FILOIMG_WIDTH*7 + LEGENDE_WIDTH + 8)
#define		SCREEN_HEIGHT	(430)
#define		SCREEN_DEPTH	(32)
#define		DEFAULT_FPS	(60)
#define		PI		3.14159265

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_dpos
{
  double	x;
  double	y;
}		t_dpos;

typedef struct	s_circle
{
  t_pos		pos;
  int		r;
}		t_circle;

typedef struct	s_progress
{
  t_pos		pos;
  int		radius_ext;
  int		radius_int;
  int		percent;
  SDL_Color	first_color;
  SDL_Color	second_color;
  SDL_Color	back_color;
}		t_progress;

typedef struct	s_line
{
  int		dx;
  int		sx;
  int		dy;
  int		sy;
  int		err;
  int		e2;
}		t_line;

typedef struct	s_philograph
{
  t_dpos	onScreen;
}		t_philograph;

typedef struct	s_framerate
{
  Uint32	framecount;
  float		rateticks;
  Uint32	baseticks;
  Uint32	lastticks;
  Uint32	rate;
  Uint32	time_passed;
}		t_framerate;

typedef struct	s_surfaces
{
  SDL_Surface*	screen;
  SDL_Surface*	filos[7];
  SDL_Surface*	faces[4];
}		t_surfaces;

typedef struct	s_interface
{
  int	       	fps;
  t_framerate	framerate;
  t_surfaces	surfaces;
  TTF_Font	*font;
  t_philograph	filo[7];
}		t_interface;

int		console_err(char *str);
void		console_out(char *str);
int		framerate_delay(void);
int		render_stats(SDL_Surface *, char *, t_pos, SDL_Color);
int		render(t_sceptiques *);
int		apply_surface(int, int, SDL_Surface *, SDL_Rect *);
int		fill_rect(SDL_Surface *, SDL_Rect *, SDL_Color rgb);
int		flip(void);
int		create_rgb_surface(SDL_Surface **, int, int);
int		SDL_init(void);
int		video_init(void);
int		interface_init(t_sceptiques *);
int		poll_event(void);
int		process(t_sceptiques *);
int		clear_all(t_sceptiques *);
void		draw_progress_circle(SDL_Surface *, t_progress);
void		draw_centered_text(SDL_Surface *, char *, t_pos, SDL_Color);
void		draw_left_text(SDL_Surface *, char *, t_pos, SDL_Color);
void		draw_bold_line(SDL_Surface *, t_pos, t_pos, Uint32);
void		set_pixel(SDL_Surface *, int, int, Uint32);
void		render_init(t_surfaces **, SDL_Color *, SDL_Color *, SDL_Color *);
void		render_progress_init(t_progress *, SDL_Color, SDL_Color, SDL_Color);
void		render_legend(t_pos, t_progress, t_surfaces *, SDL_Color);
void		render_philos(t_progress, t_sceptiques *, SDL_Color);

#endif		/* !INTERFACE_H_ */
