/*
** calc_color.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 22:55:36 2014 Colin Coudray
** Last update Sun Jun  8 16:43:54 2014 Colin Coudray
*/

#include "igraph.h"

t_pt		calc_color_refl(t_sst *supa, t_rec *rec, long double sol, t_lif obj)
{
  t_pt		color2;

  color2 = calc_color_aux(supa, *rec, sol, obj);
  fill_rec(rec, sol, &obj, 115);
  rec->color = melt_color(calc_color_net(supa, *rec), color2, obj.reflexion);
  return (rec->color);
}

t_pt		calc_color_net(t_sst *supa, t_rec rec)
{
  t_lif		obj;
  long double	sol;
  t_pt		color2;

  sol = calc_solution(supa, &obj, rec.vect, rec.coord);
  rec.color = init_point(0, 0, 0);
  if (sol > 0 || sol < 0)
    {
      if (obj.reflexion && rec.stack < FIELD_DEPTH)
	rec.color = calc_color_refl(supa, &rec, sol, obj);
      else
	rec.color = calc_color_aux(supa, rec, sol, obj);
      if (obj.transparence && rec.stack < FIELD_DEPTH)
      	{
	  color2 = calc_color_aux(supa, rec, sol, obj);
	  fill_rec(&rec, sol, &obj, 0);
	  rec.color = melt_color(calc_color_net(supa, rec), (obj.reflexion) ?
			     (rec.color) : (color2), obj.transparence);
      	}
    }
  else
    if (rec.stack == 0)
      rec.color = background_img(2);
  return (rec.color);
}

t_pt		calc_color(t_sst *supa, t_pt vect, t_pt coord)
{
  t_rec		rec;

  rec.color = init_point(0, 0, 0);
  rec.stack = 0;
  rec.n = 1;
  rec.coord = coord;
  rec.vect = vect;
  return (calc_color_net(supa, rec));
}
