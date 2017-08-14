/*
** main.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Mon Jun  2 13:33:11 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:32 2014 Sergen Tanguc
*/

#include "my.h"

int		main(int ac, char **av)
{
  t_data	infos;

  gtk_init(&ac, &av);
  init_window(&infos);
  init_label(&infos);
  init_box(&infos);
  init_box_img(&infos);
  file_selection_button(&infos);
  img_selection_button(&infos);
  edit_selection_button(&infos);
  spin_selection_button(&infos);
  g_signal_connect(G_OBJECT(infos.window), "destroy",
		   G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(infos.window);
  gtk_main();
  return (0);
}
