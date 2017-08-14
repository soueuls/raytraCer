/*
** effects.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Apr  1 14:33:10 2014 Colin Coudray
** Last update Tue Apr 15 17:34:42 2014 Colin Coudray
*/

#include "igraph.h"

t_pt	celshading(t_lif *obj, long double arc_cos)
{
  t_pt	tmp;

  tmp = load_celshader(arc_cos);
  tmp.x = tmp.x * obj->color.x / 255.0;
  tmp.y = tmp.y * obj->color.y / 255.0;
  tmp.z = tmp.z * obj->color.z / 255.0;
  return (tmp);
}

t_pt	inverse_color(t_pt color)
{
  t_pt	tmp;

  tmp.x = 0;
  tmp.y = 0;
  tmp.z = 0;
  (void)color;
  return (tmp);
}

t_pt	color_checker(t_lif *obj, t_pt color, t_pt inter)
{
  int	a;
  int	b;
  int	c;

  a = (inter.x + WIDTH / 2.0) / L_CARR;
  b = (inter.y + WIDTH / 2.0) / L_CARR;
  c = inter.z / L_CARR;
  if (c % 2 || obj->type != 1)
    {
      if (a % 2)
	return ((b % 2) ? (color) : (inverse_color(color)));
      else
	return ((b % 2 == 0) ? (color) : (inverse_color(color)));
    }
  else
    {
      if (a % 2)
	return ((b % 2 == 0) ? (color) : (inverse_color(color)));
      else
	return ((b % 2) ? (color) : (inverse_color(color)));
    }
}

t_pt	effects(t_lif *obj, t_pt inter, long double arc_cos, t_pt color)
{
  if (obj->noise)
    color = color_noise(obj, color, inter, arc_cos);
  if (obj->checker)
    color = color_checker(obj, color, inter);
  if (CELSHADING)
    color = celshading(obj, arc_cos);
  return (color);
}
