/*
** sobel_filter.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Apr 15 17:57:31 2014 Colin Coudray
** Last update Fri Apr 18 13:23:27 2014 Colin Coudray
*/

#include "igraph.h"

long double	calc_colorfulness(t_img *img, int i, int j)
{
  long double	nb;

  nb = 0;
  if (j >= 0 && i >= 0 && i <= WIDTH && j <= HEIGHT)
    {
      nb += img->data[(j * 4 * WIDTH) + (i * 4)];
      nb += img->data[(j * 4 * WIDTH) + (i * 4) + 1];
      nb += img->data[(j * 4 * WIDTH) + (i * 4) + 2];
      nb /= 3.0;
      return (nb);
    }
  else
    return (0);
}

long double	calc_gradient_x(t_img *img, int i, int j)
{
  long double	nb;

  nb = 0;
  nb += calc_colorfulness(img, i - 1, j - 1) * 3;
  nb += calc_colorfulness(img, i - 1, j) * 10;
  nb += calc_colorfulness(img, i - 1, j + 1) * 3;
  nb += calc_colorfulness(img, i + 1, j - 1) * -3;
  nb += calc_colorfulness(img, i + 1, j) * -10;
  nb += calc_colorfulness(img, i + 1, j + 1) * -3;
  return (nb);
}

long double	calc_gradient_y(t_img *img, int i, int j)
{
  long double	nb;

  nb = 0;
  nb += calc_colorfulness(img, i - 1, j - 1) * -3;
  nb += calc_colorfulness(img, i - 1, j + 1) * 3;
  nb += calc_colorfulness(img, i, j - 1) * -10;
  nb += calc_colorfulness(img, i, j + 1) * 10;
  nb += calc_colorfulness(img, i + 1, j - 1) * -3;
  nb += calc_colorfulness(img, i + 1, j + 1) * 3;
  return (nb);
}

int		is_edge(t_img *img, int j, int i)
{
  if (ab_s(calc_gradient_x(img, i, j)) +
      ab_s(calc_gradient_y(img, i, j)) > 0.2)
    return (1);
  else
    return (0);
}
