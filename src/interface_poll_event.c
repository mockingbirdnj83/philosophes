/*
** interface_poll_event.c for interface_poll_event in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:50:35 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:50:36 2015 aubess_t aubess_t
*/

#include "interface.h"

int		poll_event()
{
  SDL_Event	event;
  SDLKey	sym;

  while (SDL_PollEvent(&event) != 0)
    {
      sym = event.key.keysym.sym;
      if (event.type == SDL_QUIT)
	return (1);
      else if (event.type == SDL_KEYUP)
	return (0);
      else if (event.type == SDL_KEYDOWN)
	if (sym == SDLK_ESCAPE)
	  return (1);
    }
  return (0);
}
