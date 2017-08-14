/*
** draw_img.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 19:41:49 2014 Colin Coudray
** Last update Sun Jun  8 19:05:16 2014 Colin Coudray
*/

#include "igraph.h"

void	my_filters(t_img *img)
{
  if (CELSHADING)
    draw_edge(img);
  if (B_A_W)
    black_and_white(img);
  if (SEPIA)
    go_sepia(img);
}

void    my_put_pixel(t_img *img, t_pt color, int i, int j)
{
  int   tmp;

  tmp = (j * 4 * WIDTH) + (i * 4);
  color = check_color(color);
  img->data[tmp++] = (int)color.x;
  img->data[tmp++] = (int)color.y;
  img->data[tmp++] = (int)color.z;
  img->data[tmp] = 0;
}

void	draw_img(t_img *img, const char *pathname)
{
  t_sst	*supa;
  t_pt	vect;
  t_pt	color;
  int	x;
  int	y;

  if ((supa = parsing(pathname)) == NULL)
    exit(EXIT_FAILURE);
  y = -1;
  while (++y < HEIGHT)
    {
      x = -1;
      while (++x < WIDTH)
	{
	  vect = calc_vect(y, x, supa->cam);
	  color = calc_color(supa, vect, supa->cam.coord);
	  my_put_pixel(img, color, y, x);
	  background_img(1);
	}
      mlx_put_image_to_window(img->mlx->mlx_ptr, img->mlx->win_ptr,
			      img->img, 0, 0);
      if (y % 9 == 0)
	printf("%d %%\n", (int)((double)(y + 1) / (double)HEIGHT * 100.0));
    }
  my_filters(img);
}
