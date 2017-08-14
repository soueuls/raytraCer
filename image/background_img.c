/*
** background_img.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Sun Jun  8 15:28:01 2014 Colin Coudray
** Last update Sun Jun  8 15:45:13 2014 Colin Coudray
*/

#include "igraph.h"

void		update_coord_img(int *xx, int *yy)
{
  if (*yy == HEIGHT - 1)
    {
      *xx += 1;
      *yy = 0;
    }
  else
    {
      *yy += 1;
    }
}

t_pt            background_img(int mode)
{
  static t_img  image;
  static int    xx = 0;
  static int    yy = 0;
  t_pt          color;
  int           i;
  int           j;

  if (mode == 0)
    image = decompress_jpeg(BACKGROUND_IMG);
  else if (mode == 1)
    update_coord_img(&xx, &yy);
  else if (mode == 2)
    {
      j = (int)((double)yy / (double)HEIGHT * (double)image.height);
      i = (int)((double)xx / (double)WIDTH * (double)image.width);
      color.x = (unsigned char)image.data[j * image.width * 4 + i * 4 + 2];
      color.y = (unsigned char)image.data[j * image.width * 4 + i * 4 + 1];
      color.z = (unsigned char)image.data[j * image.width * 4 + i * 4 + 0];
    }
  else
    free(image.data);
  return (color);
}
