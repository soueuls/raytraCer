/*
** mai.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Mar 18 17:08:50 2014 Colin Coudray
** Last update Sat Jun  7 17:36:27 2014 Colin Coudray
*/

#include "igraph.h"

int             main(int ac, char **av)
{
  t_mlx         *mlx;
  t_img         *img;

  if (ac > 1)
    {
      if ((mlx = init_main()) == NULL)
        return (1);
      img = my_new_img(mlx, av[1]);
      if (CELSHADING)
	load_celshader(-1);
      background_img(0);
      draw_img(img, av[1]);
      mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img, 0, 0);
      if (ac > 2)
	save_img(img);
      mlx_key_hook(mlx->win_ptr, &gere_key, img);
      mlx_expose_hook(mlx->win_ptr, &gere_expose, img);
      mlx_loop(mlx->mlx_ptr);
      background_img(42);
      free(img);
      free(mlx);
    }
  else
    my_putstr("Veuillez specifier un fichier de conf\n");
  return (0);
}
