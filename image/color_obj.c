/*
** color_obj.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri Mar 21 11:56:56 2014 Colin Coudray
** Last update Sun Jun  8 19:04:02 2014 Colin Coudray
*/

#include "igraph.h"

t_pt		diff_color(t_lif *obj, t_lum *spot, double arc_cos)
{
  t_pt		color;

  color.x = (arc_cos * (obj->color.x * spot->color.x) / 255.0) * obj->lum_diff;
  color.y = (arc_cos * (obj->color.y * spot->color.y) / 255.0) * obj->lum_diff;
  color.z = (arc_cos * (obj->color.z * spot->color.z) / 255.0) * obj->lum_diff;
  return (color);
}

t_pt		amb_color(t_lif *obj, t_lum *spot)
{
  t_pt		color;

  color.x = (obj->color.x * spot->color.x) / 255 * obj->lum_amb;
  color.y = (obj->color.y * spot->color.y) / 255 * obj->lum_amb;
  color.z = (obj->color.z * spot->color.z) / 255 * obj->lum_amb;
  return (color);
}

t_pt		calc_spec_ray(t_lif *obj, t_lum *spot, t_pt inter)
{
  t_pt		ray;
  t_pt		normal;
  double	arc_cos;
  long double	norm_ray;
  long double	norm_norm;
  t_pt		refl;

  ray = calc_ray(spot->coord, inter);
  normal = obj->calc_normal(obj, inter);
  norm_ray = sqrt(s_q(ray.x) + s_q(ray.y) + s_q(ray.z));
  norm_norm = sqrt(s_q(normal.x) + s_q(normal.y) + s_q(normal.z));
  arc_cos = (normal.x * ray.x + normal.y * ray.y +
             normal.z * ray.z) / (norm_norm * norm_ray);
  refl.x = 2.0 * arc_cos * (normal.x / norm_norm) - (ray.x / norm_ray);
  refl.y = 2.0 * arc_cos * (normal.y / norm_norm) - (ray.y / norm_ray);
  refl.z = 2.0 * arc_cos * (normal.z / norm_norm) - (ray.z / norm_ray);
  return (refl);
}

t_pt		spec_color(t_lif *obj, t_lum *spot, t_pt inter, t_pt cam)
{
  t_pt		color;
  t_pt		vect;
  t_pt		refl;
  long double	norm_vect;
  long double	norm_refl;
  double	cos_om;

  vect = calc_ray(cam, inter);
  refl = calc_spec_ray(obj, spot, inter);
  norm_vect = sqrt(s_q(vect.x) + s_q(vect.y) + s_q(vect.z));
  norm_refl = sqrt(s_q(refl.x) + s_q(refl.y) + s_q(refl.z));
  cos_om = (vect.x * refl.x + vect.y * refl.y + vect.z * refl.z) /
    (norm_vect * norm_refl);
  if (cos_om > 0)
    {
      color.x = ((obj->color.x * spot->color.x) / 255 * obj->lum_spec) *
	pow(cos_om, PHONG_EXP);
      color.y = ((obj->color.y * spot->color.y) / 255 * obj->lum_spec) *
	pow(cos_om, PHONG_EXP);
      color.z = ((obj->color.z * spot->color.z) / 255 * obj->lum_spec) *
	pow(cos_om, PHONG_EXP);
    }
  else
    color = init_point(0, 0, 0);
  return (color);
}

t_pt		color_obj(t_lif *obj, t_pt cam, t_lum *spot, t_pt inter)
{
  t_pt		color_diff;
  t_pt		color_spec;
  t_pt		color_amb;
  t_pt		color;
  t_pt		normal;
  t_pt		ray;
  long double	tmp_norme;
  long double	arc_cos;

  ray = calc_ray(spot->coord, inter);
  normal = obj->calc_normal(obj, inter);
  tmp_norme = sqrt(s_q(ray.x) + s_q(ray.y) + s_q(ray.z));
  arc_cos = (normal.x * ray.x + normal.y * ray.y +
             normal.z * ray.z) / (tmp_norme);
  if (arc_cos > 0)
    {
      color_diff = diff_color(obj, spot, arc_cos);
      color_amb = amb_color(obj, spot);
      color_spec = spec_color(obj, spot, inter, cam);
      color = add_color(add_color(color_diff, color_amb), color_spec);
      color = effects(obj, inter, arc_cos, color);
    }
  else
    color = amb_color(obj, spot);
  return (check_color(color));
}
