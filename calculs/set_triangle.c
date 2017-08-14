/*
** set_triangle.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri May  9 00:20:13 2014 Colin Coudray
** Last update Wed Jun  4 21:04:13 2014 Colin Coudray
*/

#include "igraph.h"

t_pt		cross_product(t_pt a, t_pt b)
{
  t_pt		x;

  x.x = a.y * b.z - a.z * b.y;
  x.y = a.z * b.x - a.x * b.z;
  x.z = a.x * b.y - a.y * b.x;
  return (x);
}

double		dot(t_pt a, t_pt b)
{
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}

long double	solve_eq_triangle(t_lif *obj, t_pt vect, t_pt coord)
{
  t_pt		n;
  double	d;
  long double	sol;
  t_pt		tmp;
  t_pt		edge0;
  t_pt		edge1;
  t_pt		edge2;
  t_pt		c0;
  t_pt		c1;
  t_pt		c2;

  n = obj->calc_normal(obj, coord);
  d = n.x * obj->coord[0].x + n.y * obj->coord[0].y + n.z * obj->coord[0].z;
  sol = (n.x * coord.x + n.y * coord.y + n.z * coord.z + d) /
    (n.x * vect.x + n.y * vect.y + n.z * vect.z);
  tmp = calc_inter(sol, coord, vect);
  edge0 = calc_ray(obj->coord[0], obj->coord[1]);
  edge1 = calc_ray(obj->coord[1], obj->coord[2]);
  edge2 = calc_ray(obj->coord[2], obj->coord[0]);
  c0 = calc_ray(tmp, obj->coord[0]);
  c1 = calc_ray(tmp, obj->coord[1]);
  c2 = calc_ray(tmp, obj->coord[2]);
  return ((dot(n, cross_product(edge0, c0)) > 0 &&
	   dot(n, cross_product(edge1, c1)) > 0 &&
	   dot(n, cross_product(edge2, c2)) > 0) ? sol : 0);
}

t_pt		calc_normal_triangle(t_lif *obj, t_pt inter)
{
  t_pt		a;
  t_pt		b;

  (void)inter;
  a = calc_ray(obj->coord[1], obj->coord[0]);
  b = calc_ray(obj->coord[2], obj->coord[0]);
  return (normalise(cross_product(normalise(b), normalise(a))));
}
