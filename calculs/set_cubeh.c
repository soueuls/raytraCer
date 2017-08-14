/*
** set_cubeh.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri May  9 00:09:50 2014 Colin Coudray
** Last update Wed Jun  4 21:02:31 2014 Colin Coudray
*/

#include "igraph.h"

#define CUBE_CTE (obj->radius / 10.0)

long double     solve_eq_cubeh(t_lif *obj, t_pt vect, t_pt coord)
{
  t_pt          abc;
  t_pt          de;
  t_pt          sol;
  long double   fourth;
  long double   demi1;
  long double   demi2;

  coord = transl(coord, obj->coord[0]);
  abc.x = (pow(vect.x, 4) + pow(vect.y, 4) + pow(vect.z, 4));
  abc.y = 4.0 * (pow(vect.x, 3) * coord.x + pow(vect.y, 3) *
                 coord.y + pow(vect.z, 3) * coord.z);
  abc.z = 6.0 * (s_q(vect.x * coord.x) + s_q(vect.y * coord.y) +
     s_q(vect.z * coord.z)) - 5.0 * (s_q(vect.x) + s_q(vect.y) + s_q(vect.z));
  de.x = 4.0 * (pow(coord.x, 3) * vect.x + pow(coord.y, 3) *
                vect.y + pow(coord.z, 3) * vect.z) - 10.0 *
    (vect.x * coord.x + vect.y * coord.y + vect.z * coord.z);
  de.y = (pow(coord.x, 4) + pow(coord.y, 4) + pow(coord.z, 4)) -
    5.0 * (s_q(coord.x) + s_q(coord.y) + s_q(coord.z)) + CUBE_CTE;
  sol = eq_4th(abc, de, &fourth);
  if (sol.x == sol.y && sol.y == sol.z && sol.z == 0)
    return (0);
  demi1 = (sol.x > 0 && sol.x <= sol.y) ? sol.x : (sol.y > 0) ? sol.y : 0;
  demi2 = (sol.z > 0 && sol.z <= fourth) ? sol.z : (fourth > 0) ? fourth : 0;
  demi1 = (demi1 > 0 && demi1 < demi2) ? demi1 : demi2;
  return (((demi1 > 0 + EQ_MARGIN ? demi1 : 0) > 0) ? demi1 : 0);
}

t_pt            calc_normal_cubeh(t_lif *obj, t_pt inter)
{
  t_pt          x;

  (void)obj;
  inter = transl(inter, obj->coord[0]);
  inter.x = -inter.x;
  inter.y = -inter.y;
  inter.z = -inter.z;
  x.x = 4.0 * pow(inter.x, 3) - 10.0 * inter.x;
  x.y = 4.0 * pow(inter.y, 3) - 10.0 * inter.y;
  x.z = 4.0 * pow(inter.z, 3) - 10.0 * inter.z;
  if (obj->bump_mapping)
    return (bump_normal(normalise(x), inter));
  return (normalise(x));
}
