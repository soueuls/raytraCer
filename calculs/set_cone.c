/*
** set_cone.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Wed Mar  5 14:30:29 2014 Colin Coudray
** Last update Wed Jun  4 21:53:06 2014 Colin Coudray
*/

#include "igraph.h"

long double	solve_eq_cone_aux(t_lif *obj, t_pt *abc, t_pt vect, t_pt coord)
{
  long double	cte;

  cte = rad(obj->radius);
  abc->x = s_q(vect.x) - cte * s_q(vect.y) + s_q(vect.z);
  abc->y = 2 * (vect.x * coord.x - cte * vect.y *
               coord.y + vect.z * coord.z);
  abc->z = s_q(coord.x) - cte * s_q(coord.y) + s_q(coord.z);
  return (s_q(abc->y) - 4 * abc->x * abc->z);
}

long double	solve_eq_cone(t_lif *obj, t_pt vect, t_pt coord)
{
  t_pt		abc;
  t_pt		delta;
  t_pt		inters1;
  t_pt		in2;

  coord = transl(coord, obj->coord[0]);
  coord = rota(coord, obj->angle);
  vect = rota(vect, obj->angle);
  delta.x = solve_eq_cone_aux(obj, &abc, vect, coord);
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

t_pt		calc_normal_cone(t_lif *obj, t_pt inter)
{
  t_pt		x;
  long double	cte;

  cte = rad(obj->radius);
  x.x = obj->coord->x - inter.x;
  x.y = -cte * (obj->coord->y - inter.y);
  x.z = obj->coord->z - inter.z;
  if (obj->bump_mapping)
    return (bump_normal(normalise(x), inter));
  return (normalise(x));
}
