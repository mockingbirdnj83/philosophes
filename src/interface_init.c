/*
** interface_init.c for interface_init in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:50:15 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:50:15 2015 aubess_t aubess_t
*/

#include "interface.h"
#include "interface_global.h"

static void	filoname_init(char *filoname[])
{
  filoname[0] = "Mamadou";
  filoname[1] = "Descartes";
  filoname[2] = "Robin";
  filoname[3] = "Aristote";
  filoname[4] = "Confusus";
  filoname[5] = "Schopenhauer";
  filoname[6] = "Platon";
}

int		interface_init(t_sceptiques *tab)
{
  char*		filoname[7];
  t_surfaces	*surfaces;
  int		i;

  filoname_init(filoname);
  surfaces = &g_graph.surfaces;
  g_graph.fps = DEFAULT_FPS; 
  i = -1;
  while (++i < 7)
    create_rgb_surface(&surfaces->filos[i], FILOIMG_WIDTH, FILOIMG_HEIGHT);
  surfaces->faces[RESTING] = SDL_LoadBMP("assets/filor.bmp");
  surfaces->faces[EATING] = SDL_LoadBMP("assets/filoe.bmp");
  surfaces->faces[THINKING] = SDL_LoadBMP("assets/filot.bmp");
  surfaces->faces[LEFT] = SDL_LoadBMP("assets/end.bmp");
  i = -1;
  while (++i < 7)
    {
      tab[i].name = filoname[i];
      g_graph.filo[i].onScreen.x = LEGENDE_WIDTH + i * FILOIMG_WIDTH;
      g_graph.filo[i].onScreen.y = 0;
    }
  srand((unsigned int) time(NULL));
  init(tab);
  return (0);
}
