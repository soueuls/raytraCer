/*
** calc_solution.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Mon Feb 24 15:38:08 2014 Colin Coudray
** Last update Sun Jun  8 18:32:31 2014 Colin Coudray
*/

#include "igraph.h"

double		*get_both_sol_sphere(t_lif *obj, t_pt coord, t_pt vect)
{
  double	*sol;
  t_pt		abc;
  double	delta;

  if ((sol = malloc(2 * sizeof(double))) == NULL)
    exit(EXIT_FAILURE);
  coord = transl(coord, obj->coord[0]);
  abc.x = s_q(vect.x) + s_q(vect.y) + s_q(vect.z);
  abc.y = 2 * (vect.x * coord.x + vect.y *
               coord.y + vect.z * coord.z);
  abc.z = s_q(coord.x) + s_q(coord.y) +
    s_q(coord.z) - s_q(obj->radius);
  delta = s_q(abc.y) - 4 * abc.x * abc.z;
  if (delta < 0 - EQ_MARGIN)
    {
      sol[0] = 0;
      sol[1] = 0;
    }
  else
    {
      sol[0] = ((-abc.y - sqrt(delta)) / (2.0 * abc.x));
      sol[1] = ((-abc.y + sqrt(delta)) / (2.0 * abc.x));
    }
  return (sol);
}

double		*get_both_sol(t_lif *obj, t_rec info)
{
    return (get_both_sol_sphere(obj, info.coord, info.vect));
}

int		is_a_valid_k(t_sst *supa, t_lif *obj, long double tmp_sol, t_rec info)
{
  t_lif		*tmp;
  double	*sol;

  tmp = supa->obj->next;
  if (tmp_sol == 0 || obj->negatif == 1)
    return (0);
  while (tmp != supa->obj)
    {
      if (tmp->negatif && tmp->type == 0)
	{
	  sol = get_both_sol(tmp, info);
	  if (tmp_sol > *sol && tmp_sol < sol[1])
	    {
	      free(sol);
	      return (0);
	    }
	  free(sol);
	}
      tmp = tmp->next;
    }
  return (1);
}

void		fill_info(t_rec *info, t_pt vect, t_pt coord)
{
  info->vect = vect;
  info->coord = coord;
}

long double	calc_solution(t_sst *supa, t_lif *obj, t_pt vect, t_pt coord)
{
  t_lif		*tmp;
  long double	sol;
  long double	tmp_sol;
  t_rec		info;

  sol = -1;
  tmp = supa->obj->next;
  while (tmp != supa->obj)
    {
      tmp_sol = tmp->solve_eq(tmp, vect, coord);
      fill_info(&info, vect, coord);
      if (is_a_valid_k(supa, tmp, tmp_sol, info))
	if (sol - tmp_sol > 0 - EQ_MARGIN || sol == -1)
	  {
	    sol = tmp_sol;
	    *obj = *tmp;
	    (void)obj;
	  }
      if (tmp->type == BLOB)
	while (tmp->type == BLOB)
	  tmp = tmp->next;
      else
	tmp = tmp->next;
    }
  return ((sol == -1) ? 0 : sol);
}
