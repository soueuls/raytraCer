/*
** image_conversion_format.c for image_conversion_format in /home/soueuls/JPEG
** 
** Made by Swann Polydor
** Login   <soueuls@epitech.net>
** 
** Started on  Wed Jun  4 13:31:42 2014 Swann Polydor
** Last update Fri Jun  6 18:22:36 2014 Colin Coudray
*/

#include "igraph.h"
#include "struct.h"

char	*convert_to_minilibx(t_img *img)
{
  char	*image;
  int	number_of_components;
  int	i;
  int	j;

  if ((image = malloc(img->width * img->height * 4)) == NULL)
    exit(1);
  number_of_components = img->width * img->height * 4;
  i = 0;
  j = 0;
  while (i++ < number_of_components)
    {
      if (i % 4 == 0)
	image[i - 1] = 0;
      else
	image[i - 1] = img->data[j++];
    }
  free(img->data);
  return (image);
}

char	*convert_to_jpeg(t_img *img)
{
  char	*image;
  int	number_of_components;
  int	i;
  int	j;
  int	tmp;

  if ((image = malloc(img->width * img->height * 3)) == NULL)
    exit(1);
  number_of_components = img->width * img->height * 4;
  i = 0;
  j = 0;
  while (j++ < number_of_components)
    {
      if (j % 4 != 0)
	image[i++] = img->data[j - 1];
      else
	{
	  tmp = image[i - 3];
	  image[i - 3] = image[i - 1];
	  image[i - 1] = tmp;
	}
    }
  return (image);
}
