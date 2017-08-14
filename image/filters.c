/*
** filters.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Thu May  8 16:49:32 2014 Colin Coudray
** Last update Wed Jun  4 21:41:55 2014 Colin Coudray
*/

#include "igraph.h"

int	manual_cast(int nb)
{
  if (nb < 0)
    nb *= -2;
  if (nb > 255)
    nb = 255;
  return (nb);
}

void	averaging_color(char *data, int adresse)
{
  int	average;

  average = manual_cast(data[adresse]) + manual_cast(data[adresse + 1]) +
    manual_cast(data[adresse + 2]);
  average /= 3;
  data[adresse] = (char)average;
  data[adresse + 1] = (char)average;
  data[adresse + 2] = (char)average;
}

void	black_and_white(t_img *img)
{
  int	i;
  int	j;

  i = -1;
  while (++i < HEIGHT)
    {
      j = -1;
      while (++j < WIDTH)
	averaging_color(img->data, i * 4 * WIDTH + j * 4);
    }
}

void	sepiaing_color(char *data, int adresse)
{
  int	average;

  average = manual_cast(data[adresse]) + manual_cast(data[adresse + 1]) +
    manual_cast(data[adresse + 2]);
  average /= 3;
  data[adresse] = (char)(0.40 * (double)average);
  data[adresse + 1] = (char)(0.88 * (double)average);
  data[adresse + 2] = (char)(2.24 * (double)average);
}

void	go_sepia(t_img *img)
{
  int	i;
  int	j;

  i = -1;
  while (++i < HEIGHT)
    {
      j = -1;
      while (++j < WIDTH)
	sepiaing_color(img->data, i * 4 * WIDTH + j * 4);
    }
}
