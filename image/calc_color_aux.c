/*
** calc_color_aux.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Sat Apr  5 17:13:29 2014 Colin Coudray
** Last update Sat Apr  5 17:13:54 2014 Colin Coudray
*/

#include "igraph.h"

t_pt            check_color(t_pt color)
{
  if (color.x < 0)
    color.x = 0;
  if (color.x > MAXCHAR)
    color.x = MAXCHAR;
  if (color.y < 0)
    color.y = 0;
  if (color.y > MAXCHAR)
    color.y = MAXCHAR;
  if (color.z < 0)
    color.z = 0;
  if (color.z > MAXCHAR)
    color.z = MAXCHAR;
  return (color);
}

t_pt            finalise_color(t_pt color, int nb)
{
  if (nb)
    {
      color.x = color.x / (double)nb;
      color.y = color.y / (double)nb;
      color.z = color.z / (double)nb;
      color = check_color(color);
    }
  return (color);
}

t_pt            add_color(t_pt c1, t_pt c2)
{
  t_pt          tmp;

  tmp.x = c1.x + c2.x;
  tmp.y = c1.y + c2.y;
  tmp.z = c1.z + c2.z;
  return (tmp);
}
