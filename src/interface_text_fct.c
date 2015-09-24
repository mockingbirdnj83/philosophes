/*
** interface_text_fct.c for interface_text_fct in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:52:03 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:52:04 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

void		draw_left_text(SDL_Surface *s, char *str, t_pos p, SDL_Color f)
{
  SDL_Surface	*stext;
  SDL_Rect	offset;

  stext = TTF_RenderText_Solid(g_graph.font, str, f);
  offset.x = p.x;
  offset.y = p.y;
  SDL_BlitSurface(stext, NULL, s, &offset);
  SDL_FreeSurface(stext);
}

void		draw_centered_text(SDL_Surface *s, char *str, t_pos c, SDL_Color f)
{
  int		tx;
  int		ty;
  SDL_Surface	*stext;
  SDL_Rect	offset;

  TTF_SizeText(g_graph.font, str, &tx, &ty);
  stext = TTF_RenderText_Solid(g_graph.font, str, f);
  offset.x = c.x - tx / 2;
  offset.y = c.y - ty + 5;
  SDL_BlitSurface(stext, NULL, s, &offset);
  SDL_FreeSurface(stext);
}
