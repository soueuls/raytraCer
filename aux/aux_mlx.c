/*
** aux_mlx.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 17:10:19 2014 Colin Coudray
** Last update Sun Jun  8 15:26:34 2014 Colin Coudray
*/

#include "igraph.h"

int             gere_key(int keycode, t_img *img)
{
  if (keycode == 65307)
    {
      free(img->mlx);
      free(img);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

int     gere_expose(t_img *im)
{
  mlx_put_image_to_window(im->mlx->mlx_ptr, im->mlx->win_ptr, im->img, 0, 0);
  return (0);
}

t_mlx           *init_main()
{
  t_mlx         *mlx;

  mlx = malloc(sizeof(t_mlx));
  if (mlx == NULL)
    return (NULL);
  mlx->mlx_ptr = mlx_init();
  if (mlx->mlx_ptr == NULL)
    return (NULL);
  mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT,
				"Le RT que tu veux pour ta cassette");
  return (mlx);
}

t_img   *my_new_img(t_mlx *mlx, char *name)
{
  t_img *im;

  if ((im = malloc(sizeof(t_img))) == NULL)
    return (NULL);
  im->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
  im->data = mlx_get_data_addr(im->img, &im->bpp, &im->sizel, &im->endian);
  im->mlx = mlx;
  im->width = WIDTH;
  im->height = HEIGHT;
  im->name = name;
  return (im);
}
