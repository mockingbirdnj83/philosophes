/*
** interface_debug.c for interface_debug in /home/aubess_t/work/PSU_2014_philo/gui/src
** 
** Made by aubess_t aubess_t
** Login   <aubess_t@epitech.net>
** 
** Started on  Sun Mar  1 21:48:35 2015 aubess_t aubess_t
** Last update Sun Mar  1 21:48:36 2015 aubess_t aubess_t
*/

#include "interface.h"

int console_err(char* str)
{
  fprintf(stderr, "%s: %s\n", str, SDL_GetError());
  fflush(stderr);
  return (-1);
}

void console_out(char* str)
{
  fprintf(stdout, "%s: %s\n", str, SDL_GetError());
  fflush(stdout);
}
