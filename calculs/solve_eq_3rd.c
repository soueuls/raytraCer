/*
** solve_eq.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Mon Apr 21 18:32:08 2014 Colin Coudray
** Last update Thu Apr 24 16:22:11 2014 Colin Coudray
*/

#include "igraph.h"

t_pt		eq_3rd_delta(t_pt abc, long double d, double *a3)
{
  t_pt		a012;
  t_pt		pq_delta;

  a012.x = d / abc.x;
  a012.y = abc.z / abc.x;
  a012.z = abc.y / abc.x;
  *a3 = a012.z / 3.0;
  pq_delta.x = a012.y - *a3 * a012.z;
  pq_delta.y = a012.x - a012.y * *a3 + 2.0 * pow(*a3, 3);
  pq_delta.z = s_q(pq_delta.y / 2.0) + pow(pq_delta.x / 3.0, 3);
  return (pq_delta);
}

t_pt		eq_3rd_pos(t_pt pq_delta, double a3)
{
  t_pt		x123;
  double	w1;
  double	w;

  x123 = init_point(0, 0, 0);
  w1 = -pq_delta.y / 2.0 + sqrt(pq_delta.z);
  w = ((w1 >= 0) ? 1 : -1) * pow(ab_s(w1), 1.0 / 3.0);
  x123.x = w - pq_delta.x / 3.0 / w - a3;
  return (x123);
}

t_pt		eq_3rd_nul(t_pt pq_delta, double a3)
{
  t_pt		x123;

  x123.x = 3.0 * pq_delta.y / pq_delta.x - a3;
  x123.y = -3.0 * pq_delta.y / 2.0 / pq_delta.x - a3;
  x123.z = x123.y;
  return (x123);
}

t_pt		eq_3rd_neg(t_pt pq_delta, double a3)
{
  t_pt		x123;
  double	u;
  double	v;
  double	t;

  u = 2.0 * sqrt(-pq_delta.x / 3.0);
  v = -pq_delta.x / 2.0 / pow(-pq_delta.x / 3.0, 3.0 / 2.0);
  t = acos(v) / 3.0;
  x123.x = u * cos(t) - a3;
  x123.y = u * cos(t + 2.0 * M_PI / 3.0) - a3;
  x123.z = u * cos(t + 4.0 * M_PI / 3.0) - a3;
  return (x123);
}

t_pt		eq_3rd(t_pt abc, long double d)
{
  t_pt		x123;
  t_pt		pq_delta;
  double	a3;

  if (abc.y == abc.z && abc.z == 0)
    {
      x123.x = pow((-d / abc.x), 1.0 / 3.0);
      return (x123);
    }
  pq_delta = eq_3rd_delta(abc, d, &a3);
  if (pq_delta.z > 0)
    x123 = eq_3rd_pos(pq_delta, a3);
  else if (pq_delta.z == 0)
    x123 = eq_3rd_nul(pq_delta, a3);
  else
    x123 = eq_3rd_neg(pq_delta, a3);
  return (x123);
}
