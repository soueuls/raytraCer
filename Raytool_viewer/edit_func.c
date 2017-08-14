/*
** edit_func.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:23:16 2014 Sergen Tanguc
** Last update Sun Jun  8 20:53:00 2014 Sergen Tanguc
*/

#include "my.h"

void		edit_func(GtkButton *button, gpointer user_data)
{
  t_data	*infos;

  (void)button;
  infos = (t_data*)user_data;
  infos->window_edit = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(infos->window_edit),
		       "Raytracer Viewer");
  gtk_window_set_position(GTK_WINDOW(infos->window_edit),
			  GTK_WIN_POS_CENTER);
  infos->text_view = gtk_text_view_new();
  infos->box_view = gtk_vbox_new(TRUE, 2);
  gtk_box_pack_start(GTK_BOX(infos->box_view), infos->text_view, TRUE, TRUE, 0);
  open_file(infos);
  add_scroll_edit_window(infos);
  button_save_file(infos);
  g_signal_connect(G_OBJECT(infos->text_buffer), "changed",
		   G_CALLBACK(modif_text), NULL);
  gtk_widget_set_size_request(infos->window_edit, 600, 620);
  gtk_widget_show_all(infos->window_edit);
}

void		edit_selection_button(t_data *infos)
{
  g_signal_connect(G_OBJECT(infos->button[2]), "pressed",
		   G_CALLBACK(edit_func), infos);
}
