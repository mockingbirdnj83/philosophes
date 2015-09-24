/*
** interface_SDL_fct.c for interface_SDL_fct in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:51:40 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:51:40 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

int		apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
  SDL_Rect	offset;

  if (source == NULL)
    return (-1);
  offset.x = x;
  offset.y = y;
  return (SDL_BlitSurface(source, clip, g_graph.surfaces.screen, &offset));
}

int	create_rgb_surface(SDL_Surface** surface, int width, int height)
{
  int	ret;

  if (*surface != NULL)
    SDL_FreeSurface(*surface);
  *surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
				  width, height, SCREEN_DEPTH,
				  g_graph.surfaces.screen->format->Rmask,
				  g_graph.surfaces.screen->format->Gmask,
				  g_graph.surfaces.screen->format->Bmask,
				  g_graph.surfaces.screen->format->Amask);
  if ((ret = (*surface == NULL ? -1 : 0)) != 0)
    console_err("Unable to create RGB surface");
  return (ret);
}


void	set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  Uint8	*p;

  p = (Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel;
  *(Uint32 *)p = pixel;
}
