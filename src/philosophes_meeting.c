/*
** philosophes_meeting.c for philosophes_meeting in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:52:53 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:52:53 2015 aubess_t aubess_t
*/

#include "philosophes.h"
#include "global.h"

void	rest(t_sceptiques *philosopher)
{
  g_chopsticks[philosopher->id] = 0;
  g_chopsticks[philosopher->id + 1 % 7] = 0;
  pthread_mutex_unlock(&g_m);
  philosopher->status = RESTING;
  usleep(250000);
  philosopher->hunger = philosopher->hunger_base;
  philosopher->stamina = philosopher->stamina_base;
  philosopher->digestion = 0;
}

void	eat(t_sceptiques *philosopher)
{
  g_chopsticks[philosopher->id] = 1;
  g_chopsticks[RCS(philosopher->id)] = 1;
  pthread_mutex_unlock(&g_m);
  philosopher->status = EATING;
  usleep(250000);
  (philosopher->hunger > philosopher->rice ?
   philosopher->rice = 0 :
   (philosopher->rice -= philosopher->hunger));
  ++(philosopher->digestion);
  ++(philosopher->stamina);
  --(philosopher->hunger);
  if (philosopher->rice <= 0)
    philosopher->rice = 0;
  pthread_mutex_lock(&g_m);
  g_chopsticks[philosopher->id] = 0;
  g_chopsticks[RCS(philosopher->id)] = 0;
  pthread_mutex_unlock(&g_m);
}

void	think(t_sceptiques *philosopher)
{
  g_chopsticks[philosopher->id] = 1;
  pthread_mutex_unlock(&g_m);
  philosopher->status = THINKING;
  usleep(250000);
  (philosopher->stamina < (10 - philosopher->intelligence) ?
   philosopher->stamina = 0 :
   (philosopher->stamina -= (10 - philosopher->intelligence)));
  while (philosopher->status != EATING)
    {
      pthread_mutex_lock(&g_m);
      if (g_chopsticks[philosopher->id + 1 % 7] == 0)
	eat(philosopher);
      else
	pthread_mutex_unlock(&g_m);
    }
}

void	*start_meeting(void *p)
{
  unsigned int	rcs;
  unsigned int	lcs;
  t_sceptiques	*philosopher;

  philosopher = (t_sceptiques*)p;
  while (philosopher->rice)
    {
      pthread_mutex_lock(&g_m);
      lcs = g_chopsticks[philosopher->id];
      rcs = g_chopsticks[RCS(philosopher->id)];
      if (philosopher->status != EATING && lcs == 0 && rcs == 0)
	eat(philosopher);
      else if (philosopher->status != EATING &&
	       philosopher->status != THINKING &&
	       lcs == 0)
	think(philosopher);
      else
	rest(philosopher);
    }
  philosopher->status = LEFT;
  pthread_exit(NULL);
  return 0;
}

void	end_meeting(t_sceptiques *p)
{
  int i;

  i = -1;
  while (++i < 7)
    {
      pthread_join(p[i].nic, NULL);
    }
}
