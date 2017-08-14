/*
** button.c for  in /home/tanguc_s/rendu/BONUS_RT
** 
** Made by Sergen Tanguc
** Login   <tanguc_s@epitech.net>
** 
** Started on  Fri Jun  6 16:29:49 2014 Sergen Tanguc
** Last update Sun Jun  8 20:52:53 2014 Sergen Tanguc
*/

#include "my.h"

void		img_selection_button(t_data *infos)
{
  g_signal_connect(G_OBJECT(infos->button[1]), "pressed",
		   G_CALLBACK(aff_img), infos);
}

void		file_selection_button(t_data *infos)
{
  g_signal_connect(G_OBJECT(infos->button[0]), "pressed",
		   G_CALLBACK(search_file), infos);
}

void		add_toggle_button(t_data *infos)
{
  gchar		*label;

  label = g_locale_to_utf8("Generation ?", -1, NULL, NULL, NULL);
  infos->check_button = gtk_check_button_new_with_label(label);
  g_free(label);
  gtk_box_pack_start(GTK_BOX(infos->hbox), infos->check_button,
		     FALSE, FALSE, 1);
  add_check_scale(infos);
}

void		button_save_file(t_data *infos)
{
  infos->button[3] = gtk_button_new_from_stock(GTK_STOCK_SAVE_AS);
  g_signal_connect(G_OBJECT(infos->window_edit), "destroy",
		   G_CALLBACK(save_file), infos);
  gtk_box_pack_start (GTK_BOX(infos->window_edit), infos->button[3],
		      TRUE, TRUE, 1);
}
