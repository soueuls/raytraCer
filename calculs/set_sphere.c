/*
** set_sphere.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Sun Feb 23 23:04:54 2014 Colin Coudray
** Last update Tue May 27 17:14:06 2014 Colin Coudray
*/

#include "igraph.h"

long double	solve_eq_sphere(struct s_lif *obj, t_pt vect, t_pt coord)
{
  t_pt		abc;
  long double	delta;
  long double	s1;
  long double	s2;

  coord = transl(coord, obj->coord[0]);
  abc.x = s_q(vect.x) + s_q(vect.y) + s_q(vect.z);
  abc.y = 2 * (vect.x * coord.x + vect.y *
	       coord.y + vect.z * coord.z);
  abc.z = s_q(coord.x) + s_q(coord.y) +
    s_q(coord.z) - s_q(obj->radius);
  delta = s_q(abc.y) - 4 * abc.x * abc.z;
  if (delta < 0 - EQ_MARGIN)
    return (0);
  else if (delta == 0)
    return (-abc.y / (2.0 * abc.x));
  else
    {
      s1 = ((-abc.y - sqrt(delta)) / (2.0 * abc.x));
      s2 = ((-abc.y + sqrt(delta)) / (2.0 * abc.x));
      if (s2 < 0 + EQ_MARGIN)
	s2 = 0;
      return ((s1 < s2 && s1 > 0 + EQ_MARGIN) ? (s1) : (s2));
    }
}

t_pt		calc_normal_sphere(struct s_lif *obj, t_pt inter)
{
  t_pt		normal;

  normal = transl(inter, obj->coord[0]);
  normal.x = -normal.x;
  normal.y = -normal.y;
  normal.z = -normal.z;
  if (obj->bump_mapping)
    return (bump_normal(normalise(normal), inter));
  return (normalise(normal));
}
