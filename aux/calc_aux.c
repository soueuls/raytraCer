/*
** calc_aux.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 21:15:34 2014 Colin Coudray
** Last update Mon Apr  7 23:47:40 2014 Colin Coudray
*/

#include "igraph.h"

t_pt		calc_vect(int i, int j, t_cam camera)
{
  t_pt  vect;

  vect.x = (int)(i - HEIGHT / 2.0) + camera.angle.x;
  vect.y = (int)(j - WIDTH / 2.0) + camera.angle.y;
  vect.z = FOCALE + camera.angle.z;
  return (vect);
}

long double	s_q(long double nb)
{
  return (nb * nb);
}

t_pt            calc_inter(long double s, t_pt coord, t_pt vect)
{
  t_pt          tmp;

  tmp.x = vect.x * s + coord.x;
  tmp.y = vect.y * s + coord.y;
  tmp.z = vect.z * s + coord.z;
  return (tmp);
}

t_pt    calc_ray(t_pt coord, t_pt intersection)
{
  t_pt  ray;

  ray.x = intersection.x - coord.x;
  ray.y = intersection.y - coord.y;
  ray.z = intersection.z - coord.z;
  return (ray);
}
