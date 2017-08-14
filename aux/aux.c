/*
** aux.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 17:50:21 2014 Colin Coudray
** Last update Sun Jun  8 20:55:55 2014 Colin Coudray
*/

#include "igraph.h"

int	my_putchar(int c)
{
  return (write(1, &c, 1));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      i += 1;
    }
  return (i);
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int     litlget_aux(char *str, int nb, int i)
{
  if (i > 0)
    nb += litlget_aux(str, nb, i - 1);
  if (str[i] == '-')
    return (nb);
  return (nb * 10 + (str[i] - 48));
}

int     litlget(char *str)
{
  int   nb;

  nb = litlget_aux(str, 0, my_strlen(str) - 1);
  if (str[0] == '-')
    return (-nb);
  else
    return (nb);
}
