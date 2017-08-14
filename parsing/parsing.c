/*
** parsing.c for rtv1 in /home/colin/Desktop/igraph/rtv1_propre
** 
** Made by colin
** Login   <colin@epitech.net>
** 
** Started on  Wed Feb 19 16:51:02 2014 colin
** Last update Sun Jun  8 18:35:24 2014 Colin Coudray
*/

#include "igraph.h"

void	my_go_to(char buff[1024], char dest, int fd)
{
  int	b;

  b = 1;
  while (buff[0] != dest && b)
    b = read(fd, buff, 1);
}

int	my_get_until(char buff[1024], char dest, int fd)
{
  int	b;
  int	i;

  i = 0;
  b = 1;
  while (b)
    {
      b = read(fd, &buff[i], 1);
      if (b == 0)
	{
	  buff[i] = '\0';
	  return (1);
	}
      else if (buff[i] == dest)
	b = 0;
      else
	i += 1;
    }
  buff[i + 1] = '\0';
  return (0);
}

t_sst	*parsing(const char *path)
{
  int	fd;
  char	*obj;
  t_sst	*supa;

  if ((fd = open(path, O_RDONLY)) == -1 ||
      (supa = malloc((sizeof(t_sst)))) == NULL)
    exit(-1);
  init_cam(fd, supa);
  obj = init_spot(fd, supa);
  supa->obj = init_leaf(NULL, NULL);
  supa->obj->type = 42;
  while (obj)
    obj = init_obj(fd, supa, obj);
  free(obj);
  close(fd);
  return (supa);
}
