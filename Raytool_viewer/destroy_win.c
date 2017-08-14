/*
** destroy_win.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:24:03 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:37 2014 Sergen Tanguc
*/

#include "my.h"

void		my_destroy_window(GtkWidget *widget, gpointer pdata)
{
  (void)widget;
  (void)pdata;
  gtk_main_quit();
}
