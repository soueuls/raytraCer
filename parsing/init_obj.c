/*
** init_obj.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Fri Feb 21 19:34:20 2014 Colin Coudray
** Last update Wed Jun  4 21:17:06 2014 Colin Coudray
*/

#include "igraph.h"

long double	rad(long double nb)
{
  return (nb / 180.0 * M_PI);
}

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i += 1;
  return (i);
}

t_lif   *add_after2(t_lif *elem1, t_lif *elem2)
{
  elem2->prev = elem1;
  elem2->next = elem1->next;
  elem1->next->prev = elem2;
  elem1->next = elem2;
  return (elem2);
}

char    *init_obj(int fd, t_sst *supa, char *obj)
{
  int   k;
  char  buff[1024];
  char  **word_tab;
  t_lif *tmp;

  k = 0;
  tmp = supa->obj->next;
  while (tmp->next != supa->obj)
    tmp = tmp->next;
  while (k < 1024)
    buff[k++] = '\0';
  my_go_to(buff, '{', fd);
  my_get_until(buff, '}', fd);
  buff[my_strlen(buff) - 1] = '\0';
  clear_space(buff);
  word_tab = my_str_to_word_tab(buff, " ");
  if (tab_len(word_tab) % 2)
    exit(-1);
  if ((tmp = add_after2(tmp, init_leaf(word_tab, obj))) == NULL)
    return (NULL);
  my_go_to(buff, '<', fd);
  if (my_get_until(buff, '>', fd))
    return (NULL);
  free(word_tab);
  return ((my_strlen(buff) > 4) ? (my_strcpy(obj, buff)) : (NULL));
}
