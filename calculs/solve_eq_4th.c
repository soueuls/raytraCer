/*
** solve_eq_4th.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Thu Apr 24 16:23:06 2014 Colin Coudray
** Last update Wed Jun  4 21:13:53 2014 Colin Coudray
*/

#include "igraph.h"

long double		eq_4th_u(long double dp, long double cp, long double delta)
{
  long double	u;
  long double	w;

  if (delta > 0)
    {
      w = pow(-dp / 2.0 + sqrt(delta), 1.0 / 3.0);
      u = w - cp / 3.0 / w;
    }
  else if (delta == 0)
    u = 3 * dp / cp;
  else
    u = 2.0 * sqrt(-cp / 3.0) *
      cos(acos(-dp / 2.0 / pow(-cp / 3.0, 3.0 / 2.0)) / 3.0);
  return (u);
}

t_pt		eq_4th_calc_trs(long double a, long double c, long double u)
{
  t_pt		trs;

  trs.x = a / 3.0 + u;
  trs.y = sqrt(trs.x - a);
  trs.z = sqrt(s_q(trs.x / 2.0) - c);
  return (trs);
}

t_pt		eq_4th_sol12(long double delta, long double partie1,
			     long double partie2, long double decal)
{
  t_pt		sol;

  if (delta >= 0)
    {
      sol.x = partie1 + partie2 + decal;
      sol.y = partie1 - partie2 + decal;
    }
  else
    {
      sol.x = 0;
      sol.y = 0;
    }
  return (sol);
}

t_pt		eq_4th(t_pt abc, t_pt de, long double* fourth)
{
  t_pt		a[5];
  long double	delta;

  a[1].x = abc.y / (2.0 * abc.x);
  a[1].y = abc.z / abc.x - 3.0 * s_q(a[1].x) / 2.0;
  a[1].z = de.x / abc.x + pow(a[1].x, 3) - abc.z * a[1].x / abc.x;
  a[2].x = de.y / abc.x - 3.0 * pow(a[1].x, 4) / 16.0 + abc.z * s_q(a[1].x) /
    (4.0 * abc.x) - de.x * a[1].x / (2.0 * abc.x);
  a[2].y = -2.0 * pow(a[1].y, 3) / 27.0 - s_q(a[1].z) +
    8.0 * a[1].y * a[2].x / 3.0;
  a[2].z = -(s_q(a[1].y) + 12.0 * a[2].x) / 3.0;
  delta = pow(a[2].z / 3.0, 3) + s_q(a[2].y / 2.0);
  a[3] = eq_4th_calc_trs(a[1].y, a[2].x, eq_4th_u(a[2].y, a[2].z, delta));
  a[4].x = -abc.y / (4.0 * abc.x);
  delta = s_q(a[3].y) - 2.0 * a[3].x - 4.0 * a[3].z;
  a[4].y = (a[1].z > 0) ? a[3].y / 2.0 : -a[3].y / 2.0;
  a[4].z = sqrt(ab_s(delta)) / 2.0;
  a[0] = eq_4th_sol12(delta, a[4].y, a[4].z, a[4].x);
  delta = s_q(a[3].y) - 2.0 * a[3].x + 4.0 * a[3].z;
  a[4].y = (a[1].z > 0) ? -a[3].y / 2.0 : a[3].y / 2.0;
  a[4].z = sqrt(ab_s(delta)) / 2.0;
  a[0].z = (delta >= 0) ? a[4].y + a[4].z + a[4].x : 0;
  *fourth = (delta >= 0) ? a[4].y - a[4].z + a[4].x : 0;
  return (a[0]);
}
