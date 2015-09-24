/*
** interface_circle_fct.c for interface_circle_fct in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:48:01 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:48:11 2015 aubess_t aubess_t
*/

#include "interface.h"

static void	fill_circle_line(SDL_Surface *s, t_dpos d, t_circle c, Uint32 p)
{
  int		x;
  Uint8		*a;
  Uint8		*b;
  int		bpp;

  bpp = s->format->BytesPerPixel;
  d.x = floor(sqrt((2.0 * c.r * d.y) - (d.y * d.y)));
  x = (int)(c.pos.x - d.x);
  a = (Uint8 *)s->pixels + (((int)(c.pos.y + c.r - d.y)) * s->pitch) + (x*bpp);
  b = (Uint8 *)s->pixels + (((int)(c.pos.y - c.r + d.y)) * s->pitch) + (x*bpp);
  while (x <= c.pos.x + d.x)
    {
      *(Uint32 *)a = p;
      *(Uint32 *)b = p;
      a += bpp;
      b += bpp;
      ++x;
    }
}

static void	fill_circle(SDL_Surface *surface, t_circle c, Uint32 pixel)
{
  t_dpos	dxy;

  dxy.y = 0;
  while (dxy.y <= c.r)
    {
      fill_circle_line(surface, dxy, c, pixel);
      dxy.y += 1.0;
    }
}

void		draw_progress_circle(SDL_Surface *surface, t_progress p)
{
  double        end;
  double	i;
  char		str[6];
  Uint32	fpixel;
  Uint32	spixel;
  Uint32	bpixel;
  t_circle	c;
  t_pos		b;

  end = ((PI * p.percent) / 100) + PI;
  fpixel = p.first_color.r << 16 | p.first_color.g << 8 | p.first_color.b;
  spixel = p.second_color.r << 16 | p.second_color.g << 8 | p.second_color.b;
  bpixel = p.back_color.r << 16 | p.back_color.g << 8 | p.back_color.b;
  i = PI;
  while ((i += 0.005) <= PI * 2)
    {
      b.x = round(p.pos.x + cos(i) * p.radius_ext);
      b.y = round(p.pos.y + sin(i) * p.radius_ext);
      draw_bold_line(surface, p.pos, b, (i < end ? fpixel : spixel));
    }
  c.pos = p.pos;
  c.r = p.radius_int;
  fill_circle(surface, c, bpixel);
  sprintf(str, "%u %%", p.percent);
  draw_centered_text(surface, str, p.pos, p.first_color);
}
