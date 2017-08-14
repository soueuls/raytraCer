/*
** bump_mapping.c for RT in /home/coudra/Desktop/igraph/RT
** 
** Made by Colin Coudray
** Login   <coudra@epitech.net>
** 
** Started on  Tue May 27 17:16:35 2014 Colin Coudray
** Last update Wed Jun  4 20:59:09 2014 Colin Coudray
*/

#include "igraph.h"

#define MAT_BUMP (0.6)

t_pt		bump_normal(t_pt normal, t_pt inter)
{
  long double	n;

  n = noise(inter, 7);
  normal.x += n * 0.6;
  normal.y += n * 0.6;
  normal.z += n * 0.6;
  return (normalise(normal));
}
