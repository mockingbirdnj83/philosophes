/*
** main.c for main in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:52:13 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:52:14 2015 aubess_t aubess_t
*/

#include	"interface.h"

t_interface g_graph;

int main(void)
{
  int ret;
  t_sceptiques tab[7];

  ret = 0;
  if ((ret = SDL_init()) == 0)
    if ((ret = video_init()) == 0)
      if ((ret = interface_init(tab)) == 0)
	while (poll_event() == 0)
	  {
	    process(tab);
	    if ((ret = render(tab)) < 0)
	      return (EXIT_FAILURE);
	    if ((ret = flip()) < 0)
	      return (EXIT_FAILURE);
	    if ((ret = framerate_delay()) < 0)
	      return (EXIT_FAILURE);
	  }
  clear_all(tab);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
