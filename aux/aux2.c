/*
** aux2.c for rtv1 in /home/coudra/Desktop/igraph/rtv1_propre
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Thu Feb 20 19:40:18 2014 Colin Coudray
** Last update Sun Apr 13 12:45:45 2014 Colin Coudray
*/

#include "igraph.h"

void		clear_space(char str[1024])
{
  int   i;
  char  tmp[1024];
  int   j;

  j = 0;
  i = 0;
  if (str != NULL && my_strlen(str))
    {
      while (str[i])
        if (str[i] == ' ' || str[i] == 9 || str[i] == 10)
          {
            if (j > 0)
              tmp[j++] = ' ';
            while (str[i] && (str[i] == ' ' || str[i] == 9 || str[i] == 10))
              i += 1;
          }
        else
          tmp[j++] = str[i++];
      tmp[j] = '\0';
      j = -1;
      while (tmp[++j])
        str[j] = tmp[j];
      str[j] = '\0';
    }
}

int		my_strcomp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i])
    if (s1[i] != s2[i])
      return (0);
    else
      i += 1;
  return (1);
}

long double	ab_s(long double nb)
{
  if (nb >= 0)
    return (nb);
  else
    return (-nb);
}

char    *my_strcat(char *s1, char *s2)
{
  char  *tmp;
  int   i;
  int   j;

  i = 0;
  j = 0;
  if ((tmp = malloc((my_strlen(s1) + my_strlen(s2) + 1) *
                    sizeof(char))) == NULL)
    exit(-1);
  while (s1[i])
    tmp[j++] = s1[i++];
  i = 0;
  while (s2[i])
    tmp[j++] = s2[i++];
  tmp[j] = '\0';
  return (tmp);
}
