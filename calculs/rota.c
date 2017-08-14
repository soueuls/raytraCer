/*
** rota.c for rtv1 in /home/colin/Desktop/igraph/rtv1
** 
** Made by colin
** Login   <colin@epitech.net>
** 
** Started on  Tue Feb 11 14:00:40 2014 colin
** Last update Sun May 11 14:15:55 2014 Colin Coudray
*/

#include "igraph.h"

t_pt		transl(t_pt point, t_pt coord)
{
  t_pt		tmp;

  tmp.x = point.x - coord.x;
  tmp.y = point.y - coord.y;
  tmp.z = point.z - coord.z;
  return (tmp);
}

t_pt            rota_x(t_pt point, long double angle)
{
  t_pt		tmp;

  tmp.x = point.x;
  tmp.y = cosf(angle) * point.y - sinf(angle) * point.z;
  tmp.z = sinf(angle) * point.y + cosf(angle) * point.z;
  return (tmp);
}

t_pt            rota_y(t_pt point, long double angle)
{
  t_pt		tmp;

  tmp.x = cosf(angle) * point.x + sinf(angle) * point.z;
  tmp.y = point.y;
  tmp.z = -sinf(angle) * point.x + cosf(angle) * point.z;
  return (tmp);
}

t_pt            rota_z(t_pt point, long double angle)
{
  t_pt		tmp;

  tmp.x = cosf(angle) * point.x - sinf(angle) * point.y;
  tmp.y = sinf(angle) * point.x + cosf(angle) * point.y;
  tmp.z = point.z;
  return (tmp);
}

t_pt		rota(t_pt point, t_pt angle)
{
  t_pt		tmp;

  tmp = rota_x(point, angle.x);
  tmp = rota_y(tmp, angle.y);
  tmp = rota_z(tmp, angle.z);
  return (tmp);
}
