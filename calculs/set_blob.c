/*
** set_blob.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri Apr 25 16:27:13 2014 Colin Coudray
** Last update Sat May 31 14:28:02 2014 Colin Coudray
*/

#include "igraph.h"

#define		COEFF_BLOB ((double)((double)blob->length / (double)PREC_FIELD))

long double	field_blob(t_lif *blob, t_pt vect, t_pt coord, long double k)
{
  long double	sol;

  sol = 1.0 / (s_q(vect.x * k + coord.x - blob->coord->x) +
	       s_q(vect.y * k + coord.y - blob->coord->y) +
	       s_q(vect.z * k + coord.z - blob->coord->z));
  sol *= (double)blob->radius;
  blob->length = sol * (double)PREC_FIELD;
  return (sol);
}

void		reinit_blob(t_lif *blob)
{
  while (blob->type == BLOB)
    {
      blob->length = 0;
      blob = blob->next;
    }
}

long double	solve_eq_blob(t_lif *obj, t_pt vect, t_pt coord)
{
  t_lif		*tmp;
  long double	sol;
  long double	k;

  k = PAS_BLOB;
  while (k < 3.0)
    {
      tmp = obj;
      sol = 0;
      while (tmp->type == BLOB)
	{
	  sol += field_blob(tmp, vect, coord, k);
	  tmp = tmp->next;
	}
      if (sol > THRESHOLD)
	return (k > 0 + EQ_MARGIN ? k : 0);
      else
	{
	  reinit_blob(obj);
	  k += PAS_BLOB;
	}
    }
  return (0);
}

t_pt		calc_normal_blob(t_lif *obj, t_pt inter)
{
  t_pt		normal;
  t_pt		tmp;
  t_pt		tmp_norm;
  t_lif		*blob;

  blob = obj;
  normal = init_point(0, 0, 0);
  while (blob->type == BLOB)
    {
      tmp = transl(inter, blob->coord[0]);
      tmp_norm.x = -tmp.x;
      tmp_norm.y = -tmp.y;
      tmp_norm.z = -tmp.z;
      tmp_norm = normalise(tmp_norm);
      normal.x += (tmp_norm.x * COEFF_BLOB);
      normal.y += (tmp_norm.y * COEFF_BLOB);
      normal.z += (tmp_norm.z * COEFF_BLOB);
      blob = blob->next;
    }
  normal = normalise(normal);
  if (obj->bump_mapping)
    return (bump_normal(normal, inter));
  return (normal);
}
