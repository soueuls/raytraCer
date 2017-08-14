/*
** set_cylindre.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Wed Mar  5 14:29:37 2014 Colin Coudray
** Last update Thu Jun  5 22:27:24 2014 Colin Coudray
*/

#include "igraph.h"

long double	solve_eq_cylindre_aux(t_lif *obj, t_pt *abc, t_pt vect, t_pt coord)
{
  abc->x = s_q(vect.x) + s_q(vect.z);
  abc->y = 2 * (vect.x * coord.x + vect.z *
	       coord.z);
  abc->z = s_q(coord.x) + s_q(coord.z) - s_q(obj->radius);
  return (s_q(abc->y) - 4 * abc->x * abc->z);
}

long double	solve_eq_cylindre(t_lif *obj, t_pt vect, t_pt coord)
{
  t_pt		abc;
  t_pt		delta;
  t_pt		inters1;
  t_pt		in2;

  coord = transl(coord, obj->coord[0]);
  coord = rota(coord, obj->angle);
  vect = rota(vect, obj->angle);
  delta.x = solve_eq_cylindre_aux(obj, &abc, vect, coord);
  if (delta.x < 0 - EQ_MARGIN)
    return (0);
  else if (delta.x == 0)
    return (-abc.y / (2.0 * abc.x));
  else
    {
      delta.y = ((-abc.y - sqrt(delta.x)) / (2.0 * abc.x));
      delta.z = ((-abc.y + sqrt(delta.x)) / (2.0 * abc.x));
      inters1 = calc_inter(delta.y, coord, vect);
      in2 = calc_inter(delta.z, coord, vect);
      if (delta.y > 0 + EQ_MARGIN && inters1.y > 0 && inters1.y < obj->length)
	return (delta.y);
      else if (delta.z > 0 + EQ_MARGIN && in2.y > 0 && in2.y < obj->length)
	return (delta.z);
    }
  return (0);
}

t_pt		calc_normal_cylindre(t_lif *obj, t_pt inter)
{
  t_pt		x;

  x.x = obj->coord->x - inter.x;
  x.y = 0;
  x.z = obj->coord->z - inter.z;
  if (obj->bump_mapping)
    return (bump_normal(normalise(x), inter));
  return (normalise(x));
}
