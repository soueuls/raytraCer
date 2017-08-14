/*
** color_noise.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Apr  1 20:45:22 2014 Colin Coudray
** Last update Wed Jun  4 21:36:55 2014 Colin Coudray
*/

#include "igraph.h"

double		get_noise_value(t_lif *obj, t_pt inter)
{
  double	n;

  if (obj->noise == 1 && obj->type != 1)
    n = noise(inter, FREQ);
  else if (obj->noise == 1 && obj->type == 1)
    n = noise(inter, FREQ);
  else if (obj->type == 1)
    {
      n = STRIURE_BOIS * noise(inter, 50);
      n = (double)n - (int)n;
    }
  else
    {
      n = STRIURE_BOIS * noise(inter, 50);
      n = (double)n - (int)n;
    }
  return (n);
}

t_pt		color_interpole(t_lif *obj, double n)
{
  t_pt		tmp_color;

  tmp_color.z = ab_s(RN * (n - V1) / (V2 - V1) +
		     obj->color.z * (V2 - n) / (V2 - V1));
  tmp_color.y = ab_s(GN * (n - V1) / (V2 - V1) +
		     obj->color.y * (V2 - n) / (V2 - V1));
  tmp_color.x = ab_s(BN * (n - V1) / (V2 - V1) +
		     obj->color.x * (V2 - n) / (V2 - V1));
  return (tmp_color);
}

t_pt		color_interpole_else(t_lif *obj, double n)
{
  t_pt		tmp_color;

  tmp_color.z = ab_s(obj->color.z * (n - V3) / (V4 - V3) +
		     RN * (V4 - n) / (V4 - V3));
  tmp_color.y = ab_s(obj->color.y * (n - V3) / (V4 - V3) +
		     GN * (V4 - n) / (V4 - V3));
  tmp_color.x = ab_s(obj->color.x * (n - V3) / (V4 - V3) +
		     BN * (V4 - n) / (V4 - V3));
  return (tmp_color);
}

t_pt		color_noise(t_lif *obj, t_pt color, t_pt inter, long double arc_cos)
{
  double	n;
  t_pt		tmp_color;

  if ((n = get_noise_value(obj, inter)) < V2)
    tmp_color = color_interpole(obj, n);
  else if (n < V3)
    {
      tmp_color.z = ab_s(obj->color.z * (n - V2) / (V3 - V2) +
			 obj->color.z * (V3 - n) / (V3 - V2));
      tmp_color.y = ab_s(obj->color.y * (n - V2) / (V3 - V2) +
			 obj->color.y * (V3 - n) / (V3 - V2));
      tmp_color.x = ab_s(obj->color.x * (n - V2) / (V3 - V2) +
			 obj->color.x * (V3 - n) / (V3 - V2));
    }
  else
    tmp_color = color_interpole_else(obj, n);
  color.x = arc_cos * tmp_color.x;
  color.y = arc_cos * tmp_color.y;
  color.z = arc_cos * tmp_color.z;
  return (color);
}
