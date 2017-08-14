/*
** init_light.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri Feb 21 14:05:11 2014 Colin Coudray
** Last update Sun Jun  8 20:56:38 2014 Colin Coudray
*/

#include "igraph.h"

t_lum   *init_light(char **word_tab)
{
  t_lum *new_spot;
  int   i;
  t_pt  tmp;

  i = 0;
  if ((new_spot = malloc(sizeof(t_lum))) == NULL)
    return (NULL);
  if (word_tab != NULL)
    {
      while (word_tab[i])
        {
          tmp = init_point(litlget(word_tab[i + 1]), litlget(word_tab[i + 2]),
			   litlget(word_tab[i + 3]));
          if (my_strcomp(word_tab[i], "coord"))
            new_spot->coord = tmp;
          else if (my_strcomp(word_tab[i], "color"))
            new_spot->color = tmp;
          i += 4;
	  if (i > tab_len(word_tab))
	    exit(-1);
        }
    }
  new_spot->next = new_spot;
  new_spot->prev = new_spot;
  return (new_spot);
}

t_lum   *add_after(t_lum *elem, t_lum *new)
{
  new->prev = elem;
  new->next = elem->next;
  elem->next->prev = new;
  elem->next = new;
  return (new);
}

void	init_spot_aux(int fd, t_lum *tmp, char buff[1024])
{
  char  **word_tab;

  if (read(fd, buff, 3) == -1)
    exit(-1);
  my_get_until(buff, '}', fd);
  buff[my_strlen(buff) - 1] = '\0';
  clear_space(buff);
  word_tab = my_str_to_word_tab(buff, " ");
  if (tab_len(word_tab) != 8)
    exit(-1);
  tmp = add_after(tmp, init_light(word_tab));
  my_go_to(buff, '<', fd);
  my_get_until(buff, '>', fd);
  free(word_tab);
}

char    *init_spot(int fd, t_sst *supa)
{
  char  buff[1024];
  int   i;
  char  *next_obj;
  t_lum *tmp;

  i = 0;
  if ((next_obj = malloc(15 * sizeof(char))) == NULL ||
      (supa->light = init_light(NULL)) == NULL)
    exit(-1);
  tmp = supa->light;
  while (i < 1024)
    buff[i++] = '\0';
  i = 0;
  my_get_until(buff, '>', fd);
  while (my_strcomp(buff, "spot>"))
    init_spot_aux(fd, tmp, buff);
  next_obj = my_strcpy(next_obj, buff);
  return (next_obj);
}
