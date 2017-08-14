/*
** spin_button.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:26:33 2014 Sergen Tanguc
** Last update Sun Jun  8 20:54:10 2014 Sergen Tanguc
*/

#include "my.h"

void		add_spin_bar(t_data *infos)
{
  GtkWidget	*frame;

  frame = gtk_frame_new("X");
  infos->spin_x = gtk_spin_button_new_with_range(0, 1920, 1);
  gtk_container_add(GTK_CONTAINER(frame), infos->spin_x);
  gtk_box_pack_start(GTK_BOX(infos->box_spin), frame, FALSE, FALSE, 0);
  frame = gtk_frame_new("Y");
  infos->spin_y = gtk_spin_button_new_with_range(0, 1000, 1);
  gtk_container_add(GTK_CONTAINER(frame), infos->spin_y);
  gtk_box_pack_start(GTK_BOX(infos->box_spin), frame, FALSE, FALSE, 0);
}

void		save_spin(GtkButton *button, gpointer user_data)
{
  t_data	*infos;

  (void)button;
  infos = (t_data*)user_data;
  infos->spin_xl = gtk_spin_button_get_value_as_int
    (GTK_SPIN_BUTTON(infos->spin_x));
  infos->spin_yl = gtk_spin_button_get_value_as_int
    (GTK_SPIN_BUTTON(infos->spin_y));
}

void		spin_button(GtkButton *button, gpointer user_data)
{
  t_data	*infos;

  (void)button;
  infos = (t_data*)user_data;
  infos->window_spin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(infos->window_spin), "Scale image");
  gtk_window_set_position(GTK_WINDOW(infos->window_spin), GTK_WIN_POS_CENTER);
  gtk_widget_set_size_request(infos->window_spin, 300, 100);
  infos->box_spin = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(infos->window_spin), infos->box_spin);
  add_spin_bar(infos);
  g_signal_connect(G_OBJECT(infos->window_spin), "destroy",
		   G_CALLBACK(save_spin), infos);
  gtk_widget_show_all(infos->window_spin);
}

void		spin_selection_button(t_data *infos)
{
  g_signal_connect(G_OBJECT(infos->button[4]), "pressed",
		   G_CALLBACK(spin_button), infos);
}
