/*
** calc_color_utils.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Sun Jun  8 15:52:17 2014 Colin Coudray
** Last update Sun Jun  8 15:58:16 2014 Colin Coudray
*/

#include "igraph.h"

#define MARGIN_SHAD ((EQ_MARGIN + (obj_hit.type == BLOB) ? 4.0 * PAS_BLOB : 0))

t_pt		melt_color(t_pt color1, t_pt color2, double proportion)
{
  t_pt		tmp;

  tmp.x = ab_s((ab_s(color1.x) * proportion +
		ab_s(color2.x) * (1.0 - proportion)));
  tmp.y = ab_s((ab_s(color1.y) * proportion +
		ab_s(color2.y) * (1.0 - proportion)));
  tmp.z = ab_s((ab_s(color1.z) * proportion +
		ab_s(color2.z) * (1.0 - proportion)));
  return (check_color(tmp));
}

t_pt		calc_color_aux(t_sst *supa, t_rec rec, long double sol, t_lif obj)
{
  t_lif		obj_hit;
  t_lum		*tmp;
  long double	tmp_sol;
  t_pt		tmp_vect;
  t_pt		color;
  int		nb;

  color = init_point(0, 0, 0);
  tmp = supa->light->next;
  nb = 1;
  while (tmp != supa->light && nb++)
    {
      tmp_vect = calc_ray(tmp->coord, calc_inter(sol, rec.coord, rec.vect));
      tmp_sol = calc_solution(supa, &obj_hit, tmp_vect, tmp->coord);
      if (!(tmp_sol > 0 + MARGIN_SHAD && tmp_sol < 1 - MARGIN_SHAD) ||
	  obj_hit.transparence)
        color = add_color(color, color_obj(&obj, rec.coord, tmp,
					   calc_inter(sol, rec.coord, rec.vect)));
      tmp = tmp->next;
    }
  return (color);
}

void		fill_rec(t_rec *rec, long double sol, t_lif *obj, int b)
{
  rec->coord = calc_inter(sol, rec->coord, rec->vect);
  if (b)
    rec->vect = calc_refl(obj, rec->coord, rec->vect);
  else
    rec->vect = calc_transp(obj, rec->coord, rec->vect, &rec->n);
  rec->stack += 1;
}
