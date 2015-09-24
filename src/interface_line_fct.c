/*
** interface_line_fct.c for interface_line_fct in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:50:24 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:50:25 2015 aubess_t aubess_t
*/

#include "interface.h"

void		draw_bold_line_init(t_line *l, t_pos a, t_pos b)
{
  l->dx = abs(b.x - a.x);
  l->sx = a.x < b.x ? 1 : -1;
  l->dy = abs(b.y - a.y);
  l->sy = a.y < b.y ? 1 : -1;
  l->err = (l->dx > l->dy ? l->dx : -l->dy) / 2;
}

void		draw_bold_line(SDL_Surface *surface, t_pos a, t_pos b, Uint32 pixel)
{
  t_line	l;

  draw_bold_line_init(&l, a, b);
  while (!(a.x == b.x && a.y == b.y))
    {
      set_pixel(surface, a.x, a.y, pixel);
      set_pixel(surface, a.x-1, a.y, pixel);
      set_pixel(surface, a.x+1, a.y, pixel);
      l.e2 = l.err;
      if (l.e2 > -l.dx)
	{
	  l.err -= l.dy;
	  a.x += l.sx;
	}
      if (l.e2 < l.dy)
	{
	  l.err += l.dx;
	  a.y += l.sy;
	}
    }
}
