/*
** set_plan.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Wed Mar  5 14:28:50 2014 Colin Coudray
** Last update Fri May 30 00:10:23 2014 Colin Coudray
*/

#include "igraph.h"

long double	solve_eq_plan(t_lif *obj, t_pt vect, t_pt coord)
{
  long double	sol;

  coord = transl(coord, obj->coord[0]);
  coord = rota(coord, obj->angle);
  vect = rota(vect, obj->angle);
  if (vect.y <= 0)
    sol = (0);
  else
    sol = (-coord.y / vect.y);
  if (sol < 0 + EQ_MARGIN)
    sol = 0;
  return (sol);
}

t_pt		calc_normal_plan(t_lif *obj, t_pt inter)
{
  t_pt		x;

  if (obj->angle.x + obj->angle.y + obj->angle.z)
    {
      x.x = obj->angle.x;
      x.y = obj->angle.y;
      x.z = obj->angle.z;
    }
  else
    {
      x.x = 0;
      x.y = inter.y;
      x.z = 0;
    }
  if (obj->bump_mapping)
    {
      x = bump_normal(normalise(x), inter);
      return (x);
    }
  return (normalise(x));
}
