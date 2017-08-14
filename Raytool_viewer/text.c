/*
** text.c for $ in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:31:21 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:28 2014 Sergen Tanguc
*/

#include "my.h"

void	modif_text(GtkButton *button, gpointer user_data)
{
  if (docs.actif)
    {
      docs.actif->sauve = FALSE;
    }
  (void)user_data;
  (void)button;
}
