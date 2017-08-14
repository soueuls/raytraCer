/*
** generation.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:24:51 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:35 2014 Sergen Tanguc
*/

#include "my.h"

void		generation_img(t_data *infos)
{
  char		*buffer;

  if ((buffer = malloc(sizeof(char) * 4096)) == NULL)
    {
      fprintf(stderr, "Error malloc\n");
      exit(1);
    }
  memset(buffer, 0, 4096);
  buffer = strcat(buffer, "./rt ");
  buffer = strcat(buffer, infos->path_file);
  buffer = strcat(buffer, " ");
  buffer = strcat(buffer, "sortie\0");
  system(buffer);
}

void		generation_on(t_data *infos, gboolean etat_s)
{
  generation_img(infos);
  if (etat_s == 1)
    aff_img_scaled(infos);
  else
    aff_img_regular(infos);
}

void		generation_off(t_data *infos, gboolean etat_s)
{
  if (etat_s == 1)
    aff_img_scaled_off(infos);
  else
    aff_img_regular_off(infos);
}
