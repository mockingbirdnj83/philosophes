/*
** interface_clear_all.c for interface_clear_all in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:48:24 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:48:25 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

int	clear_all(t_sceptiques *tab)
{
  int	i;

  i = -1;
  while (++i < 7)
    tab[i].rice = 0;
  if (g_graph.surfaces.screen != NULL)
    SDL_FreeSurface(g_graph.surfaces.screen);
  i = -1;
  while (++i < 7)
    if (g_graph.surfaces.filos[i] != NULL)
      SDL_FreeSurface(g_graph.surfaces.filos[i]);
  i = -1;
  while (++i < 3)
    if (g_graph.surfaces.faces[i] != NULL)
      SDL_FreeSurface(g_graph.surfaces.faces[i]);
  TTF_CloseFont(g_graph.font);
  TTF_Quit();
  return (0);
}
