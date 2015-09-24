/*
** interface_rect_fct.c for interface_rect_fct in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:51:03 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:51:03 2015 aubess_t aubess_t
*/

#include "interface.h"

int	fill_rect(SDL_Surface* surface, SDL_Rect *rect, SDL_Color rgb)
{
  int	ret;

  if (surface == NULL)
    return(-1);
  if ((ret = SDL_FillRect(surface, rect, SDL_MapRGB(surface->format,
						    rgb.r,
						    rgb.g,
						    rgb.b))) < 0)
    console_err("SDL_FillRect failed");
  return (ret);
}
