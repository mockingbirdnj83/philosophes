/*
** interface_render.c for interface_render in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:51:12 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:51:13 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

int		render(t_sceptiques *tab)
{
  t_surfaces	*surfaces;
  SDL_Color	fore_color;
  SDL_Color	second_color;
  SDL_Color	back_color;
  t_progress	progress;
  t_pos		name_pos;

  surfaces = &g_graph.surfaces;
  render_init(&surfaces, &fore_color, &second_color, &back_color);
  fill_rect(surfaces->screen, NULL, back_color);
  render_progress_init(&progress, fore_color, second_color, back_color);
  render_legend(name_pos, progress, surfaces, fore_color);
  render_philos(progress, tab, fore_color);
  return (0);
}
