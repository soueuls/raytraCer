/*
** init_cam.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Thu Feb 20 19:38:57 2014 Colin Coudray
** Last update Sun Jun  8 20:55:30 2014 Colin Coudray
*/

#include "igraph.h"

t_pt	init_point(long double x, long double y, long double z)
{
  t_pt	tmp;

  tmp.x = x;
  tmp.y = y;
  tmp.z = z;
  return (tmp);
}

void    init_cam_aux(char **word_tab, t_sst *supa)
{
  int   i;
  t_pt  tmp;

  i = 0;
  while (word_tab[i])
    {
      tmp = init_point(litlget(word_tab[i + 1]), litlget(word_tab[i + 2]),
		       litlget(word_tab[i + 3]));
      if (my_strcomp(word_tab[i], "coord"))
	supa->cam.coord = tmp;
      else if (my_strcomp(word_tab[i], "angle"))
	{
	  supa->cam.angle.x = rad(tmp.x);
	  supa->cam.angle.y = rad(tmp.y);
	  supa->cam.angle.z = rad(tmp.z);
	}
      i += 4;
      if (i > tab_len(word_tab))
	exit(-1);
    }
}

void    init_cam(int fd, t_sst *supa)
{
  char  buff[1024];
  int   i;
  char  **word_tab;

  i = 0;
  while (i < 1024)
    buff[i++] = 0;
  while (buff[0] != '{')
    read(fd, buff, 1);
  read(fd, buff, 2);
  i = 0;
  while (buff[i] != '}')
    read(fd, &buff[++i], 1);
  buff[i] = '\0';
  clear_space(buff);
  word_tab = my_str_to_word_tab(buff, " ");
  if (tab_len(word_tab) != 8)
    exit(-1);
  init_cam_aux(word_tab, supa);
  free(word_tab);
  my_go_to(buff, '<', fd);
}
