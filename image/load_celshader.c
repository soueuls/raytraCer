/*
** load_celshader.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Apr 15 15:22:41 2014 Colin Coudray
** Last update Sun Jun  8 17:06:15 2014 Colin Coudray
*/

#include "igraph.h"

void		draw_edge(t_img *img)
{
  int		i;
  int		j;
  char		*edge;

  i = -1;
  if ((edge = malloc(HEIGHT * WIDTH * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  while (++i < HEIGHT)
    {
      j = -1;
      while (++j < WIDTH)
	edge[i * WIDTH + j] = (is_edge(img, i, j) ? 0 : 1);
    }
  i = -1;
  while (++i < HEIGHT)
    {
      j = -1;
      while (++j < WIDTH)
	{
	  img->data[i * WIDTH * 4 + j * 4] *= edge[i * WIDTH + j];
	  img->data[i * WIDTH * 4 + j * 4 + 1] *= edge[i * WIDTH + j];
	  img->data[i * WIDTH * 4 + j * 4 + 2] *= edge[i * WIDTH + j];
	}
    }
  free(edge);
}

t_pt		celshad(long double arc_cos, int table[10][4])
{
  int		i;

  i = 0;
  arc_cos *= 100;
  while (arc_cos > table[i][0])
    i += 1;
  return (init_point(table[i][1], table[i][2], table[i][3]));
}

t_pt		load_celshader(long double nb)
{
  int		i;
  int		j;
  static int	table[10][4];
  char		*tmp;
  char		**word_tab;

  if (nb == -1)
    {
      j = 0;
      if ((i = open("celshading.texture", O_RDONLY)) == -1)
	exit(EXIT_FAILURE);
      while ((tmp = get_next_line(i)))
	{
	  word_tab = my_str_to_word_tab(tmp, " ");
	  table[j][0] = litlget(word_tab[0]);
	  table[j][1] = litlget(word_tab[1]);
	  table[j][2] = litlget(word_tab[2]);
	  table[j++][3] = litlget(word_tab[3]);
	  free(tmp);
	  free(word_tab);
	}
      return (init_point(0, 0, 0));
    }
  else
    return (celshad(nb, table));
}
