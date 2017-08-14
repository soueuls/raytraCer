/*
** vect_calc.c for RT in /home/coudra/Desktop/igraph/RT/image
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Mon Apr 14 10:17:59 2014 Colin Coudray
** Last update Wed Jun  4 21:49:25 2014 Colin Coudray
*/

#include "igraph.h"

t_pt            normalise(t_pt vect)
{
  long double   norme;

  norme = sqrt(s_q(vect.x) + s_q(vect.y) + s_q(vect.z));
  vect.x /= norme;
  vect.y /= norme;
  vect.z /= norme;
  return (vect);
}

t_pt            calc_refl(t_lif *obj, t_pt inter, t_pt vect)
{
  t_pt          normal;
  t_pt          refl;
  long double   arc_cos;

  normal = obj->calc_normal(obj, inter);
  vect = normalise(vect);
  arc_cos = normal.x * vect.x + normal.y * vect.y + normal.z * vect.z;
  refl.x = (vect.x - 2.0 * ab_s(arc_cos) * normal.x);
  refl.y = (vect.y - 2.0 * ab_s(arc_cos) * normal.y);
  refl.z = (vect.z - 2.0 * ab_s(arc_cos) * normal.z);
  return (refl);
}

t_pt            calc_transp(t_lif *obj, t_pt inter, t_pt vect, long double *n)
{
  t_pt          m;
  t_pt          refr;
  long double   acos;
  long double   r;

  r = *n / (obj->refraction);
  m = obj->calc_normal(obj, inter);
  vect = normalise(vect);
  acos = m.x * vect.x + m.y * vect.y + m.z * vect.z;
  if ((acos > 0 && obj->refraction > 1) ||
      (acos < 0 && obj->refraction < 1))
    {
      m.x *= -1;
      m.y *= -1;
      m.z *= -1;
      acos = m.x * vect.x + m.y * vect.y + m.z * vect.z;
      if (acos < 0)
        acos *= -1;
    }
  refr.x = r * vect.x + (r * acos - sqrt(1 - s_q(r) * (1 - s_q(acos)))) * m.x;
  refr.y = r * vect.y + (r * acos - sqrt(1 - s_q(r) * (1 - s_q(acos)))) * m.y;
  refr.z = r * vect.z + (r * acos - sqrt(1 - s_q(r) * (1 - s_q(acos)))) * m.z;
  *n = obj->refraction;
  return (refr);
}

