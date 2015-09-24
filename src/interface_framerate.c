/*
** interface_framerate.c for interface_framerate in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:48:58 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:48:58 2015 aubess_t aubess_t
*/

#include "interface_framerate.h"

int		framerate_delay()
{
  Uint32	current_ticks;
  Uint32	target_ticks;
  Uint32	delay;
  t_framerate	*framerate;

  framerate = &g_graph.framerate;
  framerate->framecount++;
  current_ticks = SDL_GetTicks();
  framerate->time_passed = current_ticks - framerate->lastticks;
  framerate->lastticks = current_ticks;
  target_ticks = framerate->baseticks +
    (Uint32)((float)framerate->framecount * framerate->rateticks);
  if (current_ticks <= target_ticks)
    {
      if ((delay = target_ticks - current_ticks) > 1000)
	return (console_err("delay > 1000\n"));
      SDL_Delay(delay);
    }
  else
    {
      framerate->framecount = 0;
      framerate->baseticks = SDL_GetTicks();
    }
  return (0);
}
