/*
** get_next_line.c for  in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue Apr 15 16:17:36 2014 Colin Coudray
** Last update Tue Apr 15 17:12:04 2014 Colin Coudray
*/

#include "igraph.h"

int		get_char(const int fd)
{
  static int	i = 0;
  static int	r = 0;
  static char	buff[1024];

  if (i == r)
    {
      r = read(fd, buff, 1024);
      i = 0;
      if (r <= 0)
	return (123456);
    }
  return (buff[i++]);
}

char		*get_next_line(const int fd)
{
  char		*tmp;
  int		c;
  int		i;

  i = 0;
  if ((tmp = malloc(1024 * sizeof(char))) == NULL)
    exit(-1);
  while ((c = get_char(fd)) != 123456 && c != '\n' && i < 1023)
    tmp[i++] = (char)c;
  if (c == 123456 && i == 0)
  {
    free(tmp);
    return (NULL);
  }
  tmp[i] = '\0';
  return (tmp);
}
