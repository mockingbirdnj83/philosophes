/*
** interface_render_fct.c for interface_render_fct in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:51:26 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:51:26 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

void	render_init(t_surfaces **srfc, SDL_Color *f, SDL_Color *s, SDL_Color *b)
{
  *srfc = &g_graph.surfaces;
  f->r = 255;
  f->g = 255;
  f->b = 255;
  s->r = 128;
  s->g = 128;
  s->b = 128;
  b->r = 0;
  b->g = 0;
  b->b = 0;  
}

void	render_progress_init(t_progress *p, SDL_Color f, SDL_Color s, SDL_Color b)
{
  p->radius_ext = 40;
  p->radius_int = 30;
  p->percent = 60;
  p->first_color = f;
  p->second_color = s;
  p->back_color = b;
}

void	render_legend(t_pos n, t_progress p, t_surfaces *s, SDL_Color f)
{
  int	i;
  char*	legends[5];

  legends[0] = "Rice";
  legends[1] = "Stamina";
  legends[2] = "Hunger";
  legends[3] = "Intelligence";
  legends[4] = "Digestion";
  i = -1;
  while (++i < 5) 
    {
      n.x = 8;
      n.y = g_graph.filo[0].onScreen.y + 32 +
	FILOIMG_HEIGHT + p.radius_ext + ((p.radius_ext + 16) * i);
      draw_left_text(s->screen, legends[i], n, f);
    }
}

static void	render_data(SDL_Surface *s, int philo, t_progress progress, int data)
{
  static int	n = 0;

  progress.pos.x = g_graph.filo[philo].onScreen.x + FILOIMG_WIDTH/2;
  progress.pos.y = g_graph.filo[philo].onScreen.y + 32 +
    FILOIMG_HEIGHT + ((progress.radius_ext + 16) * (n+1));
  progress.percent = data;
  draw_progress_circle(s, progress);
  if (n++ >= 4)
    n = 0;
}

void		render_philos(t_progress p, t_sceptiques *tab, SDL_Color fore_color)
{
  int		i;
  t_pos		name_pos;
  t_surfaces	*s;

  s = &g_graph.surfaces;
  i = -1;
  while (++i < 7)
    {
      name_pos.x = g_graph.filo[i].onScreen.x + FILOIMG_WIDTH/2;
      name_pos.y = g_graph.filo[i].onScreen.y + 20;
      draw_centered_text(s->screen, tab[i].name, name_pos, fore_color);
      apply_surface(g_graph.filo[i].onScreen.x, g_graph.filo[i].onScreen.y +
		    32, s->faces[tab[i].status], NULL );
      render_data(s->screen, i, p, tab[i].rice * 100 / RICE_MAX);
      render_data(s->screen, i, p, tab[i].stamina * 100 / STAMINA_MAX);
      render_data(s->screen, i, p, tab[i].hunger * 100 / HUNGER_MAX);
      render_data(s->screen, i, p, tab[i].intelligence * 100 / INTELLI_MAX);
      render_data(s->screen, i, p, tab[i].digestion * 100 / DIGESTION_MAX);
    }
}
