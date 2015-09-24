/*
** interface_SDL_init.c for interface_SDL_init in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:51:51 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:51:51 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

int	SDL_init()
{
  int	ret;

  if ((ret = SDL_Init(SDL_INIT_VIDEO |
		      SDL_INIT_TIMER |
		      SDL_INIT_NOPARACHUTE)) != 0)
    {
      console_err("Unable to init SDL");
      return (ret);
    }
  atexit(SDL_Quit);
  if ((ret = TTF_Init()) != 0)
    {
      console_err("TTF_Init failed");
      return (ret);
  }
  if (!(g_graph.font = TTF_OpenFont("assets/Roboto-Regular.ttf", 16)))
    ret = -1;
  else
    ret = 0;
  if (ret != 0)
    {
      console_err("TTF_OpenFont failed");
      return (ret);
    }
  return (ret);
}

int	video_init()
{
  int	ret;

  g_graph.surfaces.screen = SDL_SetVideoMode(SCREEN_WIDTH,
					   SCREEN_HEIGHT,
					   SCREEN_DEPTH,
					   SDL_HWSURFACE |
					   SDL_DOUBLEBUF);
  if (!(g_graph.surfaces.screen))
    ret = -1;
  else
    ret = 0;
  if (ret < 0)
    console_err("Unable to set video mode");
  else
    SDL_WM_SetCaption("Philo", NULL);
  return (ret);
}
