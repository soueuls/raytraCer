/*
** save_img.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Sat Apr  5 00:08:53 2014 Colin Coudray
** Last update Sat Jun  7 17:45:51 2014 Colin Coudray
*/

#include "igraph.h"

char	*my_nbric(long long nb, int size)
{
  char	*nbr;
  int	i;

  i = size;
  nbr = malloc(size + 1 * sizeof(char));
  if (nbr == NULL)
    return (NULL);
  nbr[i--] = '\0';
  while (i >= 0)
    {
      nbr[i--] = nb % 10 + 48;
      nb /= 10;
    }
  return (nbr);
}

void	save_img(t_img *img)
{
  char	*unique_name;

  unique_name = "sortie.jpg";
  compress_jpeg(img, unique_name);
}
